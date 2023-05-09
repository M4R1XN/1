#ifndef UTILS_H
#define UTILS_H

// ������� ������� ��� ������������ ����

#include <string>
#include <ctime>

// ������� ��� ������������ ����� � ��������� tm
// ������� �������� �����: "01/01/2023"
// ������� ��������� tm, �� ������ ���������� ����
tm stringToTime(const std::string& dateString)
{
    std::tm time = {};
    strptime(dateString.c_str(), "%d/%m/%Y", &time);
    return time;
}

// ������� ��� ������������ ��������� tm � �����
// ������� ��������� �����: "01/01/2023"
// ������� �����, �� ������ ����������� ����
std::string timeToString(const tm& time)
{
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &time);
    return std::string(buffer);
}

#endif
