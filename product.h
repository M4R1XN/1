#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;     // ����� ������
    int quantity;         // ������� ������
    double price;         // ���� ������

public:
    Product();  // ����������� �� �������������
    Product(const std::string& name, int quantity, double price)
        : name(name), quantity(quantity), price(price)
    {

    }

    // ������� �� ������� ��� ���� ������
    std::string getName() const;
    void setName(const std::string& name);
    int getQuantity() const;
    void setQuantity(int quantity);
    double getPrice() const;
    void setPrice(double price);
};

#endif