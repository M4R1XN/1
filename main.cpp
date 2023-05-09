#include <iostream>
#include <string>
#include "inventory.h" // включаємо заголовний файл інвентарю
#include "Product.h"
#include <locale.h>


int main() {
    setlocale(LC_ALL, "ukrainian");
    int a = 0;
    Inventory inventory; // створюємо екземпляр інвентарю
    inventory.load("inventory.db"); // завантажуємо дані з бази даних
    int choice = 0; // змінна для вибору опції користувачем

    do {
        // виводимо меню опцій для користувача
        std::cout << "1. Переглянути список товарiв\n";
        std::cout << "2. Додати товар\n";
        std::cout << "3. Редагувати товар\n";
        std::cout << "4. Видалити товар\n";
        std::cout << "5. Зберегти змiни та вийти\n";
        std::cout << "Ваш вибiр: ";
        std::cin >> choice;

        // обробляємо вибір користувача
        switch (choice) {
        case 1:
            inventory.display(); // виводимо список товарів
            break;
        case 2:
            inventory.addProduct(); // додаємо новий товар
            break;
        case 3:
            inventory.editProduct(); // редагуємо товар
            break;
        case 4:
            inventory.deleteProduct(a); // видаляємо товар
            break;
        case 5:
            inventory.save("inventory.db"); // зберігаємо зміни в базі даних
            std::cout << "До побачення!\n";
            break;
        default:
            std::cout << "Невiрний вибiр. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }

    } while (choice != 5); // продовжуємо цикл, поки користувач не вибере опцію "зберегти та вийти"

    return 0;
}