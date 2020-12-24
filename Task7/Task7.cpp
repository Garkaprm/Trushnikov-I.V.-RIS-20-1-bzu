﻿#include <iostream>
using namespace std;

//Задание №1
void exam(string name = "Иформатика и основы алгоритмизации ", string date = "с 13.01.2021 по 29.01.2021 ", double score = 4.5) //Функция, принимаемая параметры
{
    cout << "Название экзамена: " << name;
    cout << "\nДата экзамена: " << date;
    cout << "\nСредний балл: " << score << '\n'<<'\n';
}
//Задание №2
void min(int n, ...) //функция, принимаемая переменное количество параметров
{
    int *p = &n; //указатель на адрес первого параметра
    double min = *(p+1); //присвоение переменной значения, которое находится по следующему адресу
    for (; n != 0; n--) {   //цикл для нахождения минимального элемента массива
        if (*(p+n) < min) min = *(p+n);
    }
    cout << "Минимальный элемент массива = " << min << "\n\n";
}
//Задание №3
int search(int srch) {  //перегруженные метод для нахождения элемента массива, которое принимается в параметре
    int s = 0;
    int arr[] = {1, 2, 5, 53, 62, 0, 99}; //массив элементов 
    for (int i = 0; i < 10; i++) {
        if (arr[i] == srch) s++;
    }
    return s;
}
double search(double srch) {  //перегруженные метод для нахождения элемента массива, которое принимается в параметре
    int s = 0;
    double arr[] = { 2.4, 54.64, 1.0, 123.321, 0.76 }; //массив элементов 
    for (int i = 0; i < 10; i++) {
        if (arr[i] == srch) s++;
    }
    return s;
}
char search(char srch) {  //перегруженные метод для нахождения элемента массива, которое принимается в параметре
    int s = 0;
    char arr[] = "Hello World"; //массив элементов - строка
    for (int i = 0; i < 20; i++) {
        if (arr[i] == srch) s++;
    }
    return s;
}
//Задание №4
template <class T>   //объявление нового типа данных 
T search(T srch) {  //шаблон функции, которое может принимает в параметр любой тип данных
    int s = 0;
    char arr[100];
    for (int i = 0; i < 100; i++) {  
        arr[i] = rand() % 10; //заполнение массива случайными числами от 0 до 9
    }
    for (int i = 0; i < 100; i++) {
        if (arr[i] == srch) s++;
    }
    return s;
}
//Задание №5
double func(double x) {  //функция, описывающая уравнение
    return (x - 1 / (3 + sin(3.6 * x)));
}
double diff(double x) {  //функция, описывающая производную уравнения
    double h = 0.01;
    return (func(x + h) - func(x - h)) / (2.0 * h);
}
double answer() {  //функция для вычисления корня уравнения методом Ньютона
    double a = 0.1, b = 0.85, e = 0.0001, x[100];
    int i = 0;
    x[i] = 0 - func(0) / diff(0); 
    while (a <= b or x[i+1] - x[i] <= e) {  //цикл для нахождения корня с заданной точностью
        x[i+1] = a - func(a) / diff(a);
         a += 0.01;
    }
    return x[i];
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Задание №1\n";
    exam();  //Вызов функции с опущенными параметрами (по умолчанию)
    exam("Математика", "20.01.2020", 3.7); //вызов функции с заданными параметрами
    exam("Философия"); //вызов функции с частично опущенными параметрами

    cout << "Задание №2\n";
    min(6, 24, 75, -14, 488, 6, 3); //Вызов функции для нахождения минимального значения из всех параметров

    cout << "Задание №3\n";
    if (search((int)72) > 0) {  //условие с вызовом функции, принимаемой параметр int
        cout << "Да, в массиве есть этот элемент\n\n";
    }
    else {
        cout << "Нет, в массиве нет этого элемента\n\n";
    }
    if (search((double)123.321) > 0) { //условие с вызовом функции, принимаемой параметр double
        cout << "Да, в массиве есть этот элемент\n\n";
    }
    else {
        cout << "Нет, в массиве нет этого элемента\n\n";
    }
    if (search('z') > 0) { //условие с вызовом функции, принимаемой параметр char
        cout << "Да, в массиве есть этот элемент\n\n";
    }
    else {
        cout << "Нет, в массиве нет этого элемента\n\n";
    }

    cout << "Задание №4\n";
    if (search(5) > 0) {   //условие с вызовом функции, принимаемой параметр любого значения
        cout << "Да, в массиве есть этот элемент\n\n";
    }
    else {
        cout << "Нет, в массиве нет этого элемента\n\n";
    }

    cout << "Задание №5\n";
    cout << "Точное значение = " << 0.2624 << '\n';
    cout << "Корень, найденый методом Ньютона = " << answer() << '\n';  //вывод на экран результата функции, которая вычисляет корень уравнения методом Ньютона
    cout << "Погрешность вычислений = " << abs(0.2624-abs(answer())) << '\n'; //сравнение точного значения и найденного 
    system("pause");
}
