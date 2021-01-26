#include <iostream>
using namespace std;
#include <Windows.h>

void answer(int year, char month[10]) {  //перегруженный метод для вывода года и месяца
    switch (year) { //выбор варианта из 12 годов 
    case 1:
        cout << "Год крысы, ";
        break;
    case 2:
        cout << "Год быка, ";
        break;
    case 3:
        cout << "Год тигра, ";
        break;
    case 4:
        cout << "Год кота, ";
        break;
    case 5:
        cout << "Год дракона, ";
        break;
    case 6:
        cout << "Год змеи, ";
        break;
    case 7:
        cout << "Год лошади, ";
        break;
    case 8:
        cout << "Год козы, ";
        break;
    case 9:
        cout << "Год обезьяны, ";
        break;
    case 10:
        cout << "Год петуха, ";
        break;
    case 11:
        cout << "Год собаки, ";
        break;
    case 12:
        cout << "Год свиньи, ";
        break;
    default:
        cout << "Вы ввели неправильное число";
        break;
    }
    int number = 0;
    { //подготовка данных для использования switch
        if (!strcmp(month, "январь")) number = 1;
        if (!strcmp(month, "февраль")) number = 2;
        if (!strcmp(month, "март")) number = 3;
        if (!strcmp(month, "апрель")) number = 4;
        if (!strcmp(month, "май")) number = 5;
        if (!strcmp(month, "июнь")) number = 6;
        if (!strcmp(month, "июль")) number = 7;
        if (!strcmp(month, "август")) number = 8;
        if (!strcmp(month, "сентябрь")) number = 9;
        if (!strcmp(month, "октябрь")) number = 10;
        if (!strcmp(month, "ноябрь")) number = 11;
        if (!strcmp(month, "декабрь")) number = 12;
    }
    switch (number) { //выбор месяца из 12
    case 1:
        cout << "знак зодиака - Козерог.";
        break;
    case 2:
        cout << "знак зодиака - Водолей.";
        break;
    case 3:
        cout << "знак зодиака - Рыбы.";
        break;
    case 4:
        cout << "знак зодиака - Овен.";
        break;
    case 5:
        cout << "знак зодиака - Телец.";
        break;
    case 6:
        cout << "знак зодиака - Близнецы.";
        break;
    case 7:
        cout << "знак зодиака - Рак.";
        break;
    case 8:
        cout << "знак зодиака - Лев.";
        break;
    case 9:
        cout << "знак зодиака - Дева.";
        break;
    case 10:
        cout << "знак зодиака - Весы.";
        break;
    case 11:
        cout << "знак зодиака - Скорпион.";
        break;
    case 12:
        cout << "знак зодиака - Стрелец.";
        break;
    default:
        cout << "Вы ввели неправильное месяц";
        break;
    }
    cout << endl;
}
void answer(char year[20], int month) {  //перегруженный метод для вывода года и месяца
    int number = 0;
    {   //подготовка данных для использования switch
        if (!strcmp(year, "первый")) number = 1;
        if (!strcmp(year, "второй")) number = 2;
        if (!strcmp(year, "третий")) number = 3;
        if (!strcmp(year, "четвертый")) number = 4;
        if (!strcmp(year, "пятый")) number = 5;
        if (!strcmp(year, "шестой")) number = 6;
        if (!strcmp(year, "седьмой")) number = 7;
        if (!strcmp(year, "восьмой")) number = 8;
        if (!strcmp(year, "девятый")) number = 9;
        if (!strcmp(year, "десятый")) number = 10;
        if (!strcmp(year, "одинадцатый")) number = 11;
        if (!strcmp(year, "двенадцатый")) number = 12;
    }
    switch (number) { //выбор варианта из 12 годов
    case 1:
        cout << "Год крысы, ";
        break;
    case 2:
        cout << "Год быка, ";
        break;
    case 3:
        cout << "Год тигра, ";
        break;
    case 4:
        cout << "Год кота, ";
        break;
    case 5:
        cout << "Год дракона, ";
        break;
    case 6:
        cout << "Год змеи, ";
        break;
    case 7:
        cout << "Год лошади, ";
        break;
    case 8:
        cout << "Год козы, ";
        break;
    case 9:
        cout << "Год обезьяны, ";
        break;
    case 10:
        cout << "Год петуха, ";
        break;
    case 11:
        cout << "Год собаки, ";
        break;
    case 12:
        cout << "Год свиньи, ";
        break;
    default:
        cout << "Вы ввели неправильный номер, ";
        break;
    }
    switch (month) {  //выбор месяца из 12
    case 1:
        cout << "знак зодиака - Козерог.";
        break;
    case 2:
        cout << "знак зодиака - Водолей.";
        break;
    case 3:
        cout << "знак зодиака - Рыбы.";
        break;
    case 4:
        cout << "знак зодиака - Овен.";
        break;
    case 5:
        cout << "знак зодиака - Телец.";
        break;
    case 6:
        cout << "знак зодиака - Близнецы.";
        break;
    case 7:
        cout << "знак зодиака - Рак.";
        break;
    case 8:
        cout << "знак зодиака - Лев.";
        break;
    case 9:
        cout << "знак зодиака - Дева.";
        break;
    case 10:
        cout << "знак зодиака - Весы.";
        break;
    case 11:
        cout << "знак зодиака - Скорпион.";
        break;
    case 12:
        cout << "знак зодиака - Стрелец.";
        break;
    default:
        cout << "Вы ввели неправильное месяц";
        break;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int year;
    char month[10];  //Создание переменных
    cout << "Введите номер года ЦИФРОЙ от 1 до 12: ";
    cin >> year; //Создание переменных
    cout << "Введите НАЗВАНИЕ месяца: ";
    cin >> month;
    OemToCharA(month, month); //преобразование для использованию кириллицы
    answer(year, month); //вызов функции
    cout << endl; 

    char year2[20];
    int month2; //Создание переменных
    cout << "Введите номер года СЛОВОМ от 1 до 12: ";
    cin >> year2; //Создание переменных
    cout << "Введите НОМЕР месяца: ";
    cin >> month2; //Создание переменных
    OemToCharA(year2, year2); //преобразование для использованию кириллицы
    answer(year2, month2); //вызов функции
    cout << endl;
    system("pause");
}

