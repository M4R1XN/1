#include <iostream>
#include <string>
#include "inventory.h" // �������� ���������� ���� ���������
#include "Product.h"
#include <locale.h>


int main() {
    setlocale(LC_ALL, "ukrainian");
    int a = 0;
    Inventory inventory; // ��������� ��������� ���������
    inventory.load("inventory.db"); // ����������� ��� � ���� �����
    int choice = 0; // ����� ��� ������ ����� ������������

    do {
        // �������� ���� ����� ��� �����������
        std::cout << "1. ����������� ������ �����i�\n";
        std::cout << "2. ������ �����\n";
        std::cout << "3. ���������� �����\n";
        std::cout << "4. �������� �����\n";
        std::cout << "5. �������� ��i�� �� �����\n";
        std::cout << "��� ���i�: ";
        std::cin >> choice;

        // ���������� ���� �����������
        switch (choice) {
        case 1:
            inventory.display(); // �������� ������ ������
            break;
        case 2:
            inventory.addProduct(); // ������ ����� �����
            break;
        case 3:
            inventory.editProduct(); // �������� �����
            break;
        case 4:
            inventory.deleteProduct(a); // ��������� �����
            break;
        case 5:
            inventory.save("inventory.db"); // �������� ���� � ��� �����
            std::cout << "�� ���������!\n";
            break;
        default:
            std::cout << "���i���� ���i�. ��������� �� ���.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }

    } while (choice != 5); // ���������� ����, ���� ���������� �� ������ ����� "�������� �� �����"

    return 0;
}