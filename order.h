#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "product.h"

class Order {
private:
    std::vector<Product> products; // ������ ������
public:
    Order(); // ����������� �� �������������
    void addProduct(const Product& product); // ������ ����� �� ����������
    void removeProduct(const Product& product); // �������� ����� � ����������
    double calculateTotal() const; // ��������� �������� ���� ����������
    void display() const; // ������� ������ ������ � ���������
};

#endif
