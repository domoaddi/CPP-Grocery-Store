// Domeneak Addison, ITDEV-185-900, Final 2024

#include "Item.h"
#include "FreshProduce.h"
#include "MeasuredProduct.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cctype> // for std::isdigit
#include <algorithm> // for std::any_of

// Set the vector of Item pointers to simulate an online shopping cart
std::vector<Item*> cart;

// Function to check if a string contains any digits
bool containsDigits(const std::string& s) {
    return std::any_of(s.begin(), s.end(), ::isdigit);
}

void addItemToCart() {
    std::string name, tempPrice;
    double price;
    int quantity;

    std::cout << "Enter item name: ";
    std::cin >> name;

    // Ensure the item name is not numeric
    if (containsDigits(name)) {
        std::cout << "Invalid item name. Please ensure the name does not contain numbers.\n";
        return;
    }

    std::cout << "Enter price per unit: $";
    std::cin >> tempPrice;

    // Check if price input is a number
    try {
        price = std::stod(tempPrice);
    }
    catch (const std::exception&) {  // Notice the omitted variable name
        std::cout << "Invalid price entered. Please enter a numeric value.\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    if (quantity <= 0) {
        std::cout << "Quantity must be greater than zero.\n";
        return;
    }

    // Create and add the item to the cart
    cart.push_back(new MeasuredProduct(name, price, quantity));
    std::cout << quantity << " units of " << name << " at $" << price << " each added to your cart.\n";
}

void checkout() {
    double total = 0.0, tipPercentage, totalTip;

    std::cout << "\nEnter tip percentage in a whole number: ";
    std::cin >> tipPercentage;

    std::cout << "\nReceipt:\n";
    for (Item* item : cart) {
        std::cout << item->getName() << " - " << item->getQuantity() << " x $"
            << std::fixed << std::setprecision(2) << item->getPrice()
            << " = $" << std::fixed << std::setprecision(2) << item->calcPrice() << "\n";
        total += item->calcPrice();
        delete item; // To release memory
    }
    cart.clear();

    totalTip = total * (tipPercentage / 100);
    total += totalTip;

    std::cout << "Tip: $" << std::fixed << std::setprecision(2) << totalTip << "\n";
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << total << "\n\n";
}

void updateItemPrices() {
    // Iterate over each item in the cart
    for (Item* item : cart) {
        std::string newName;
        double newPrice;

        std::cout << "Enter the new price for " << item->getName() << ": $";
        std::cin >> newPrice;

        // Check if the input is valid
        if (std::cin.fail() || newPrice <= 0) {
            std::cin.clear(); // Clear input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid price entered. Please enter a valid positive number.\n";
            continue;
        }

        // Update the price of the item
        item->setPrice(newPrice);
        std::cout << "Price for " << item->getName() << " updated to $" << newPrice << ".\n";
    }
}

void applyDiscount() {
    double discountPercentage;

    std::cout << "Enter discount percentage in a whole number. Be truthful!: ";
    std::cin >> discountPercentage;

    if (discountPercentage < 0 || discountPercentage > 100) {
        std::cout << "Invalid discount percentage. Please enter a value between 0 and 100.\n";
        return;
    }

    // Convert percentage to fraction
    double discountFraction = discountPercentage / 100.0;

    // Apply discount to each item in the cart
    for (Item* item : cart) {
        item->applyDiscount(discountFraction);
    }

    std::cout << "Discount of " << discountPercentage << "% applied to all items in the cart.\n";
}

int main() {
    int choice;

    while (true) {
        std::cout << "Welcome to Addison's Online Grocery Store!\n";
        std::cout << "Please select an option to begin:\n";
        std::cout << "(1) Add an Item\n";
        std::cout << "(2) Checkout and Pay\n";
        std::cout << "(3) Update Item Prices\n";
        std::cout << "(4) Apply Discount\n";
        std::cout << "(5) Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addItemToCart();
            break;
        case 2:
            checkout();
            break;
        case 3:
            updateItemPrices();
            break;
        case 4:
            applyDiscount();
            break;
        case 5:
            std::cout << "Thank you for shopping at your local Addison's!\n";
            return 0;
        default:
            std::cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}
