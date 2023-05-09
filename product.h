#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;     // назва товару
    int quantity;         // кількість товару
    double price;         // ціна товару

public:
    Product();  // конструктор за замовчуванням
    Product(const std::string& name, int quantity, double price)
        : name(name), quantity(quantity), price(price)
    {

    }

    // геттери та сеттери для полів товару
    std::string getName() const;
    void setName(const std::string& name);
    int getQuantity() const;
    void setQuantity(int quantity);
    double getPrice() const;
    void setPrice(double price);
};

#endif