#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "product.h"

class Inventory {
private:
    std::vector<Product> products_; // ������ ������
public:
    Inventory(); // ����������� �� �������������
    void load(const std::string& filename); // ����������� ��� � �����
    void save(const std::string& filename); // �������� ��� �� �����
    void addProduct(); // ������ ����� �����
    void editProduct(); // ���������� �������� �����
    void deleteProduct(int index); // �������� �����
    void display(); // ������� ������ ������
};

#endif
