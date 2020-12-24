#include <iostream>
using namespace std;

void trans (int mtrx[20][20],int n){    //Функция с принимаемыми параметрами
    int matrix2[20][20], counter = 0;
    for (int i = 0; i < n; i++) {     //Цикл с параметром для транспонирования матрицы
        for (int j = 0; j < n; j++) {
            matrix2[i][j] = mtrx[j][i];
        }
    }
    cout << "\nТранспонированная матрица\n";
    for (int i = 0; i < n; i++) {            //Цикл для вывода матрицы
        for (int j = 0; j < n; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {            //Цикл со вложенным условием для определения симметрической матрицы 
        for (int j = 0; j < n; j++) {
            if (*mtrx[i, j] == *matrix2[i, j]) counter++;
        }
    }
    if (counter == pow(2, n)) {
        cout << "\nМатрица является симметрической.\n\n";
    }
    else {
        cout << "\nМатрица не является симметрической.\n\n";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n, choose, matrix[20][20] ;    //Объявление переменных и двумерного массива
    cout << "Введите количество строк и столбцов матрицы от 0 до 20: ";
    cin >> n;   //Ввод с клавиатуры
    cout << "\nДля присвоения элементам случайных значений введите 0,\nдля ввода элементов с клавиатуры введите 1 : \n";
    cin >> choose;
    if (choose == 0) {    //с 39 по 58 строку условия для выбора способа создания массива
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 100;
            }
        }
    }
    if (choose == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "matrix[" << i << "," << j << "] = ";
                cin>> matrix[i][j];
            }
        }
    }
    if (choose != 0 && choose != 1) {
        cout << "\nОшибка, неправильно введенное число\nЗапустите программу заново\n";
        system("pause");
        exit(0);
    }
    cout << "\nПолученная матрица\n";  //Цикл для вывода первой матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
    trans(matrix, n);   //Вывоз функции с параметрами
    system("pause");
}


