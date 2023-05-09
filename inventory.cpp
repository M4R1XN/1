#include <iostream>
#include <fstream>
#include <vector>
#include "inventory.h"
#include "product.h"

Inventory::Inventory() {}

void Inventory::display() {
    std::cout << "������ �����i�:" << std::endl;
    for (int i = 0; i < products_.size(); i++) {
        std::cout << i << ". " << products_[i].getName() << " - " << products_[i].getQuantity() << " ��. - " << products_[i].getPrice() << " ���." << std::endl;
    }
}

void Inventory::load(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "������� �i������� �����: " << filename << std::endl;
        return;
    }

    products_.clear();

    std::string name;
    int quantity;
    double price;

    while (file >> name >> quantity >> price) {
        products_.emplace_back(name, quantity, price);
    }

    file.close();
    std::cout << "���i ���i��� ����������i � �����: " << filename << std::endl;
}

void Inventory::save(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "������� �i������� �����: " << filename << std::endl;
        return;
    }

    for (const auto& product : products_) {
        file << product.getName() << ' ' << product.getQuantity() << ' ' << product.getPrice() << '\n';
    }

    file.close();
    std::cout << "��i�� ���i��� ��������� �� �����: " << filename << std::endl;
}

void Inventory::addProduct() {
    std::string name;
    int quantity;
    double price;

    std::cout << "����i�� ����� ������: ";
    std::cin >> name;
    std::cout << "������ �i������ ������: ";
    std::cin >> quantity;
    std::cout << "������ �i�� ������: ";
    std::cin >> price;

    products_.emplace_back(name, quantity, price);
    std::cout << "����� ���i��� ������ �� ������." << std::endl;
}

void Inventory::editProduct() {
    int productIndex;
    std::cout << "����i�� ����� ������, ���� ����i��� ����������: ";
    std::cin >> productIndex;

    if (productIndex >= 0 && productIndex < products_.size()) {
        std::string name;
        int quantity;
        double price;

        std::cout << "����i�� ���� ����� ������: ";
        std::cin >> name;
        std::cout << "����i�� ���� �i���i��� ������: ";
        std::cin >> quantity;
        std::cout << "����i�� ���� �i�� ������: ";
        std::cin >> price;

        products_[productIndex].setName(name);
        products_[productIndex].setQuantity(quantity);
        products_[productIndex].setPrice(price);

        std::cout << "����� ���i��� ������������." << std::endl;
    }
    else {
        std::cout << "���i����� ����� ������. ��������� �� ���." << std::endl;
    }
}

void Inventory::deleteProduct(int index) {
    if (index >= 0 && index < products_.size()) {
        products_.erase(products_.begin() + index);
        std::cout << "����� ������ �������� �i ������." << std::endl;
    }
    else {
        std::cout << "���i����� ����� ������. ��������� �� ���." << std::endl;
    }
}