#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "product.h"

class Inventory {
private:
    std::vector<Product> products_; // вектор товарів
public:
    Inventory(); // конструктор за замовчуванням
    void load(const std::string& filename); // завантажити дані з файлу
    void save(const std::string& filename); // зберегти дані до файлу
    void addProduct(); // додати новий товар
    void editProduct(); // редагувати існуючий товар
    void deleteProduct(int index); // видалити товар
    void display(); // вивести список товарів
};

#endif
