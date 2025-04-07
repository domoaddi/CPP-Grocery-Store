#ifndef FRESH_PRODUCE_H
#define FRESH_PRODUCE_H

#include "Item.h"

class FreshProduce : public Item {
public:
    FreshProduce(const std::string& name, double price, int quantity, double discount = 0.0);
    double calcPrice() const;
    void printDetails() const;
};

#endif // FRESH_PRODUCE_H




