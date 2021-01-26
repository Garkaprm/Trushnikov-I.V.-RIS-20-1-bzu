﻿#include <iostream>
using namespace std;

void min(int n, ...) //функция, принимаемая переменное количество параметров
{
	int* p = &n; //указатель на адрес первого параметра
	double min = *(p + 1); //присвоение переменной значения, которое находится по следующему адресу
		for (n; n != 0; n--) { //цикл для нахождения минимального элемента массива
			if (*(p + n) < min) min = *(p + n);
		}
	cout << "Минимальный элемент = " << min << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	min(5, 24, -14, 488, 3); //Вызов функции для нахождения минимального значения из всех параметров
	min(10, 45, -4, 934, 1, -6, 11, -123, 15, -7);
	min(12, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5);

	system("pause");
}