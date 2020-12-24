
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "Russian"); //Для вывода кириллицы
	double sum = 0;   //Сумма ряда
	double n = 0;       //Номер члена ряда
	double p = 1;       //Переменная для разности соседних членов ряда
	while (abs(p) > 0.0001)  // цикл 
	{
		double an = (2 * n - 1) / (pow(2, n)); //Член ряда n
		double an2 = (2 * (1 + n) - 1) / (pow(2, n + 1)); //Член ряда n+1
		sum = sum + an;  //Сумма членов ряда
		p = an2-an;      //Разность соседних членов ряда
		n++;             //Увеличение номера члена
	}
	cout << "Сумма ряда в варианте 8 с точностью e=10^(-4) = " <<sum <<'\n'; //Вывод ответа
	system("pause"); //Пауза закрытия консоли
}


