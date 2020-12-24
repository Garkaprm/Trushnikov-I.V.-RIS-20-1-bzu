﻿#include <iostream>
#include <Windows.h>
using namespace std;

FILE* F1;  //указатель, связанный с файлом
FILE* F2; //указатель, связанный с файлом
void writeF1() {  //Функция для записи строк в F1
    if ((F1 = fopen("F1.txt", "w")) == NULL) { //открытие потока для записи
        printf("Ошибка чтения файла");
        exit(1);
    }
    char line[255];
    cout << "Введите 10 строк в файл F1:\n";
    for (int i = 0; i < 10; i++) {
        gets_s(line); //Ввод строки с клавиатуры
        OemToCharA(line, line); //Преобразование строки для кириллицы
        fputs(line, F1); //Запись строки в файл F1
        fputc('\n', F1); //Запись обозначения конца строки
    }
    fclose(F1); //закрытие потока
}
void copy() {  //Функция для копирования строк из F1 в F2 с учетом условия варианта
    char line[255];
    int n = 0;
    if ((F1 = fopen("F1.txt", "r")) == NULL) { //открытие потока для чтения
        printf("Ошибка чтения файла");
        exit(1);
    }
    if ((F2 = fopen("F2.txt", "w")) == NULL) { //открытие потока для записи
        printf("Ошибка чтения файла");
        exit(1);
    }
    while (fgets(line, 255, F1) != NULL) { //Проверка конца файла F1
        for (int i = 0; i < 255; i++) { //Цикл для перебора каждого элемента строки
            if (isdigit(line[i])){  //Если элемент строки является цифрой, то проверка следующей строки.
                break;
            }
            n++;  //Если в строке не оказалось цифр, то увеличение счетчика на 1
        }
        if (n>= 254) fputs(line, F2); //Если счетчик больше или равен количеству элементов строки, то копирование строки в фаил F2
        n = 0; //обнуление счетчика
    }
    fclose(F1); //закрытие потока
    fclose(F2); //закрытие потока
}
int strtA() {  //Функция для подсчета строк, начинающихся с "А" (на русской и английский раскладках) 
    char line[255];
    int n = 0;
    if ((F2 = fopen("F2.txt", "r")) == NULL) { //открытие потока для чтения
        printf("Ошибка чтения файла");
        exit(1);
    }
    while (fgets(line, 255, F2) != NULL) { //Проверка конца файла F2
        if (line[0] == 'A' or line[0] == 'А') //Если строка начинается с "А" (на русской и английский раскладках), то увеличение счетчика на 1
            n++;
    }
    fclose(F2); //закрытие потока
    return n; //Возврат счетчика из функции
}


int main()
{
    setlocale(LC_ALL, "ru");
    writeF1(); //Вызов функции
    cout<< "\nВведенные Вами строки сохранились в файле F1, в папке проекта." << endl;
    copy();  //Вызов функции
    cout << "\nВ файл F2 скопированы строки, согласно задания." << endl;
    cout << "Количество строк в F2, которые начинаются на 'А' = " << strtA()<< endl<< endl; //Вызов функции
    system("pause");
}