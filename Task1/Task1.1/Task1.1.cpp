#include <iostream>

int main()
{
    float a = 100;
    float b = 0.001; //Создание переменных

    float aa = pow(a, 2); //"а" во 2 степени
    float aaa = pow(a, 3); //"а" в 3 степени
    float aaaa = pow(a, 4); //"a" в 4 степень

    float bb = pow(b, 2); //"b" во 2 степени
    float bbb = pow(b, 3); //"b" в 3 степени
    float bbbb = pow(b, 4); //"b" в 4 степень

    float q = pow(a + b, 4); //Первое действие
    float w = aaaa + 4 * aaa * b + 6 * aa * bb; //Второе действие
    float e = q - w; //Числитель
    float r = 4 * a * bbb + bbbb; //Знаменатель

    float answer = e / r; //ответ
    std::cout << answer; //Вывод в консоль
}