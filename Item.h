#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, double price, int quantity, double discount = 0.0)
        : name(name), price(price), quantity(quantity), discount(discount) {}

    virtual ~Item() = default;

    virtual double calcPrice() const;
    virtual void printDetails() const;

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setPrice(double newPrice) { price = newPrice; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void applyDiscount(double discountPercent) { discount = discountPercent / 100.0; }

protected:
    std::string name;
    double price;
    int quantity;
    double discount;
};

#endif // ITEM_H




