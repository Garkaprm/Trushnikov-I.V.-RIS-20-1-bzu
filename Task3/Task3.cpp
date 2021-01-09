#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");  //Для корректного вывода кириллицы
    double a = 0.1, b = 0.8, k = 10, pi = 3.14, e = 0.0001; //Переменные, заданные вариантом
    double X, Y = 0; //Переменные для записи вычислений
    double step = (b - a) / k; //Шаг для X
    
    for (X = a; X <= b; X += step) {  //Цикл, изменяющий X в диапазоне измерения
        double s, SN = 0, SE = 0, n = 1;
        while (n <= 40){    //Цикл, вычисляющий сумму ряда по заданной n
            SN += pow(X, n) * sin(n * pi / 4); //Сумма ряда
            n++;      //Увеличение номера члена
        }

        n = 1;
        do {  //Цикл вычисляющий сумму ряда с заданной точностью
            s = pow(X, n) * sin(n * pi / 4); //Член ряда n
            SE += s;  //Сумма членов ряда
            n++;             //Увеличение номера члена
        } while (abs(SE - s) < e);   
        
        Y = (X * sin(pi / 4)) / (1 - 2 * X * cos(pi / 4) + pow(X, 2));  //Функция f(x)
        cout << "X = " << X;                  //
        cout << ", SN = " << SN;              //
        cout << ", SE = " << SE;              //        Вывод результатов
        cout << ", Y = " << Y << "; \n";      //
    }
    system("pause");
}