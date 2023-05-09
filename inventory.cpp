#include <iostream>
#include <fstream>
#include <vector>
#include "inventory.h"
#include "product.h"

Inventory::Inventory() {}

void Inventory::display() {
    std::cout << "Список товарiв:" << std::endl;
    for (int i = 0; i < products_.size(); i++) {
        std::cout << i << ". " << products_[i].getName() << " - " << products_[i].getQuantity() << " шт. - " << products_[i].getPrice() << " грн." << std::endl;
    }
}

void Inventory::load(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Помилка вiдкриття файлу: " << filename << std::endl;
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
    std::cout << "Данi успiшно завантаженi з файлу: " << filename << std::endl;
}

void Inventory::save(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Помилка вiдкриття файлу: " << filename << std::endl;
        return;
    }

    for (const auto& product : products_) {
        file << product.getName() << ' ' << product.getQuantity() << ' ' << product.getPrice() << '\n';
    }

    file.close();
    std::cout << "Змiни успiшно збережено до файлу: " << filename << std::endl;
}

void Inventory::addProduct() {
    std::string name;
    int quantity;
    double price;

    std::cout << "Введiть назву товару: ";
    std::cin >> name;
    std::cout << "Введіть кiлькість товару: ";
    std::cin >> quantity;
    std::cout << "Введіть цiну товару: ";
    std::cin >> price;

    products_.emplace_back(name, quantity, price);
    std::cout << "Товар успiшно додано до списку." << std::endl;
}

void Inventory::editProduct() {
    int productIndex;
    std::cout << "Введiть номер товару, який потрiбно редагувати: ";
    std::cin >> productIndex;

    if (productIndex >= 0 && productIndex < products_.size()) {
        std::string name;
        int quantity;
        double price;

        std::cout << "Введiть нову назву товару: ";
        std::cin >> name;
        std::cout << "Введiть нову кiлькiсть товару: ";
        std::cin >> quantity;
        std::cout << "Введiть нову цiну товару: ";
        std::cin >> price;

        products_[productIndex].setName(name);
        products_[productIndex].setQuantity(quantity);
        products_[productIndex].setPrice(price);

        std::cout << "Товар успiшно відредаговано." << std::endl;
    }
    else {
        std::cout << "Недiйсний номер товару. Спробуйте ще раз." << std::endl;
    }
}

void Inventory::deleteProduct(int index) {
    if (index >= 0 && index < products_.size()) {
        products_.erase(products_.begin() + index);
        std::cout << "Товар успішно видалено зi списку." << std::endl;
    }
    else {
        std::cout << "Недiйсний номер товару. Спробуйте ще раз." << std::endl;
    }
}