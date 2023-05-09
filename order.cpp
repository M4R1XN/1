#include "order.h"
#include <iostream>

Order::Order() {}

void Order::addProduct(const Product& product) {
    products.push_back(product);
    std::cout << "����� ���i��� ������ �� ����������." << std::endl;
}

void Order::removeProduct(const Product& product) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == product.getName()) {
            products.erase(it);
            std::cout << "����� ���i��� �������� � ����������." << std::endl;
            return;
        }
    }

    std::cout << "����� �� �������� � ���������i." << std::endl;
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
        std::cout << "���������� ������." << std::endl;
        return;
    }

    std::cout << "������ �����i� � ���������i:" << std::endl;
    for (const auto& product : products) {
        std::cout << "- " << product.getName() << " (" << product.getQuantity() << " ��.)" << std::endl;
    }
}
