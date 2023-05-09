#include "order.h"
#include <iostream>

Order::Order() {}

void Order::addProduct(const Product& product) {
    products.push_back(product);
    std::cout << "Товар успiшно додано до замовлення." << std::endl;
}

void Order::removeProduct(const Product& product) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == product.getName()) {
            products.erase(it);
            std::cout << "Товар успiшно видалено з замовлення." << std::endl;
            return;
        }
    }

    std::cout << "Товар не знайдено у замовленнi." << std::endl;
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (const auto& product : products) {
        total += product.getPrice();
    }
    return total;
}

void Order::display() const {
    if (products.empty()) {
        std::cout << "Замовлення порожнє." << std::endl;
        return;
    }

    std::cout << "Список товарiв у замовленнi:" << std::endl;
    for (const auto& product : products) {
        std::cout << "- " << product.getName() << " (" << product.getQuantity() << " шт.)" << std::endl;
    }
}
