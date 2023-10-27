#include <iostream>
#include <string>
#include "Windows.h"
size_t size = 5;

int divisionHash(int key) {
    return key % size;
}

int multiplicationHash(int key) {
    const float A = 0.6180339887; // Золоте число (рекомендована константа)
    double temp = key * A - floor(key*A);
    return temp*size;
}

int stringHash(const std::string& text) {
    int hash = 0;   
    int i = 0;
    for (const char& c : text) {
        hash += (int)(c)*pow(31, i);
        i++;
    }
    return hash % size;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool cancel = true;
    while (true) {
        std::cout << "1.Хеш-функцію методом ділення" << std::endl;
        std::cout << "2.Хеш-функцію методом множення" << std::endl;
        std::cout << "3.Хеш-функцію методом рядкових ключів" << std::endl;
        int num;
        std::cin >> num;
        if (num == 1) {
            std::cout << "Введіть значення key: ";
            int num2;
            std::cin >> num2;
            int num3 = divisionHash(num2);
            std::cout << num3 << std::endl;
        }
        else if (num == 2) {
            std::cout << "Введіть значення key: ";
            int num4;
            std::cin >> num4;
            int num6 = multiplicationHash(num4);
            std::cout << num6 << std::endl;
        }
        else if (num == 3) {
            std::cout << "Введіть значення key: ";
            std::string str;
            std::cin >> str;
            int num7 = stringHash(str);
            std::cout << num7 << std::endl; // Замінено num3 на num7
        }
        else {
            break;
        }

    }

}
