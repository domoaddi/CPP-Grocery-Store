#include "Item.h"
#include <iostream>
#include <iomanip>

// Calculate total price based on quantity and item price
double Item::calcPrice() const {
    // Apply discount dynamically during calculation
    return quantity * price * (1 - discount);
}

// Print details about the item
void Item::printDetails() const {
    std::cout << name << ": " << quantity << " units at $"
        << std::fixed << std::setprecision(2) << price << " each, Total: $"
        << std::fixed << std::setprecision(2) << calcPrice() << "\n";
}
