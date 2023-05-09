#ifndef UTILS_H
#define UTILS_H

// Допоміжні функції для перетворення дати

#include <string>
#include <ctime>

// Функція для перетворення рядка в структуру tm
// Приклад вхідного рядка: "01/01/2023"
// Повертає структуру tm, що містить розпарсену дату
tm stringToTime(const std::string& dateString)
{
    std::tm time = {};
    strptime(dateString.c_str(), "%d/%m/%Y", &time);
    return time;
}

// Функція для перетворення структури tm в рядок
// Приклад вихідного рядка: "01/01/2023"
// Повертає рядок, що містить перетворену дату
std::string timeToString(const tm& time)
{
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &time);
    return std::string(buffer);
}

#endif
