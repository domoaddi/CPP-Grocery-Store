#ifndef MEASURED_PRODUCT_H
#define MEASURED_PRODUCT_H

#include "Item.h"
#include <iostream>
#include <iomanip>

class MeasuredProduct : public Item {
public:
    MeasuredProduct(const std::string& name, double price, int quantity, double discount = 0.0)
        : Item(name, price, quantity, discount) {}

    virtual double calcPrice() const override {
        return quantity * price * (1 - discount); // Apply discount in price calculation
    }
    virtual void printDetails() const override {
        std::cout << "Measured Product - " << getName() << ": " << getQuantity()
            << " units at $" << std::fixed << std::setprecision(2)
            << getPrice() << " each, Total: $" << std::fixed << std::setprecision(2)
            << calcPrice() << "\n";
    }

    // Implementation of setQuantity method to allow quantity updates
    inline void setQuantity(int newQuantity) {
        if (newQuantity > 0) {
            Item::setQuantity(newQuantity);
        }
        else {
            std::cout << "Quantity must be greater than zero.\n";
        }
    }
};

#endif // MEASURED_PRODUCT_H



