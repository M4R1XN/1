#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "product.h"

class Order {
private:
    std::vector<Product> products; // вектор товарів
public:
    Order(); // конструктор за замовчуванням
    void addProduct(const Product& product); // додати товар до замовлення
    void removeProduct(const Product& product); // видалити товар з замовлення
    double calculateTotal() const; // обчислити загальну суму замовлення
    void display() const; // вивести список товарів у замовленні
};

#endif
