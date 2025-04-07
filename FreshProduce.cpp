#include "FreshProduce.h"
#include <iostream>
#include <iomanip>

// Constructor
FreshProduce::FreshProduce(const std::string& name, double price, int quantity, double discount)
    : Item(name, price, quantity, discount) {}

// Override the calcPrice method to apply specific pricing logic for fresh produce
double FreshProduce::calcPrice() const {
    // Apply discount logic here, assuming similar to MeasuredProduct
    return quantity * price * (1 - discount);
}

// Override the printDetails method to provide detailed output specific to fresh produce
void FreshProduce::printDetails() const {
    std::cout << "Fresh Produce - ";
    std::cout << getName() << ": " << getQuantity()
        << " units at $" << std::fixed << std::setprecision(2)
        << getPrice() << " each, Total: $" << std::fixed << std::setprecision(2)
        << calcPrice() << "\n";
}