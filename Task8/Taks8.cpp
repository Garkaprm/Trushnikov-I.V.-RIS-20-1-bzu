#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;
#pragma warning(suppress : 4996)

struct Buyer { //создание структуры
    char name[50];
    char address[50];
    char telephone[50];
    char card[50];
};
FILE* db;  //указатель, связанный с файлом
FILE* db2; //указатель, связанный с файлом
Buyer man; //элемент структуры
Buyer arr[5]; //массив для хранения элементов структуры

void write() {
    //проверка файла и открытие потока для записи
    if ((db = fopen("db.txt", "wb")) == NULL) { 
        printf("Ошибка чтения файла");
        exit(1);
    }
    //запись данных в элементы структуры
    for (int i = 1; i <= 5; i++) {
        cout << i << " человек: \n";
        printf("Введите ФИО: ");
        gets_s(man.name);
        OemToCharA(man.name, man.name); //преобразование для вывода кириллицы
        printf("Введите адрес: ");
        gets_s(man.address);
        OemToCharA(man.address, man.address); //преобразование для вывода кириллицы
        printf("Введите номер телефона: ");
        gets_s(man.telephone);
        OemToCharA(man.telephone, man.telephone); //преобразование для вывода кириллицы
        printf("Введите номер кредитной карты: ");
        gets_s(man.card);
        OemToCharA(man.card, man.card); //преобразование для вывода кириллицы
        fwrite(&man, sizeof(Buyer), 1, db);
        //проверка файла
        if (ferror(db) != NULL) {
            printf("Ошибка файла");
            exit(2);
        }
        cout << '\n';
    }
    fclose(db); //закрытие потока
}
void read() {
    //проверка файла и открытие потока для чтения
    if ((db = fopen("db.txt", "rb")) == NULL) {
        printf("Ошибка чтения файла");
        exit(1);
    }
    //цикл для вывода элементов структуры
    for (int i = 1; !feof(db) && i <= 5; i++) {
        fread(&arr[i], sizeof(Buyer), 1, db);
        cout << "\n \nДанные " << i << " человека:";
        cout << "\nФИО: " << *&arr[i].name;
        cout << "\nАдрес: " << *&arr[i].address;
        cout << "\nНомер телефона: " << *&arr[i].telephone;
        cout << "\nНомер кредитной карты: " << *&arr[i].card;
    }
    fclose(db); //закрытие потока
}
void deleted() {
    //проверка файла и открытие потока для чтения
    if ((db = fopen("db.txt", "rb")) == NULL) {
        printf("Ошибка чтения файла");
        exit(4);
    }
    //проверка файла и открытие потока для записи
    if ((db2 = fopen("db2.txt", "wb")) == NULL) {
        printf("Ошибка чтения файла");
        exit(5);
    }
    for (int i = 1; !feof(db) && i <= 5; i++) { //цикл для чтения всех записей файла 1
        fread(&arr[i], sizeof(Buyer), 1, db);
        if (i >= 4) {   //начиная с 4 элемента (т.к. первые 3 необходимо удалить) запись в фаил 2
            fwrite(&arr[i], sizeof(Buyer), 1, db2);
        }
        if (ferror(db) != NULL) {
            printf("Ошибка файла");
            exit(6);
        }
    }
    fclose(db);  //закрытие потока
    fclose(db2); //закрытие потока
}
void add() {
    //проверка файла и открытие потока для добавления
    if ((db2 = fopen("db2.txt", "ab")) == NULL) {
        printf("Ошибка чтения файла");
        exit(6);
    }
    //добавление в фаил 3-х элементов
    for (int i = 6; i <= 8; i++) {
        cout << i << " человек: \n";
        printf("Введите ФИО: ");
        gets_s(man.name);
        OemToCharA(man.name, man.name);
        printf("Введите адрес: ");
        gets_s(man.address);
        OemToCharA(man.address, man.address);
        printf("Введите номер телефона: ");
        gets_s(man.telephone);
        OemToCharA(man.telephone, man.telephone);
        printf("Введите номер кредитной карты: ");
        gets_s(man.card);
        OemToCharA(man.card, man.card);
        fwrite(&man, sizeof(Buyer), 1, db2);
        if (ferror(db) != NULL) {
            printf("Ошибка файла");
            exit(2);
        }
        cout << '\n';
    }
        fclose(db2); //закрытие потока
}

int main()
{
    setlocale(LC_ALL, "ru");
    write(); //вызов функции
    cout << '\n';
    read();   //вызов функции
    cout << "\n\n\nУдаление первых 3-х элементов структуры\n";
    deleted();  //вызов функции
    cout << "Добавление 3-х элементов структуры в конец файла\n\n";
    add();  //вызов функции
    system("pause");
}
