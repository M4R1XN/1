#include "product.h"

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string& name) {
    this->name = name;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    this->price = price;
}
