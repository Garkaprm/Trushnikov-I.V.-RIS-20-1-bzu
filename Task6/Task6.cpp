#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    char str[255];  //Создание строки
    int a, n = 0, k = 0;
    cout << "Введите строку:\n";
    gets_s(str);    //Ввод строки с клавиатуры
    while (n <= strlen(str)) {     //Цикл для сортировки элементов строки по убыванию
        for (int i = 0; i < strlen(str); i++) {
            a = str[i];
            if (str[i + 1] > str[i] ) {
                str[i] = str[i + 1];
                str[i + 1] = a;
            }
        }
        n++;
    }
    cout << "Цифры введенной Вами строки, расположенные по убыванию: \n";
    for (int i = 0; i < strlen(str); i++) {   //Цикл для вывода элементов строки, которые являются цифрами 
        if (isdigit(str[i])) {
            cout << str[i];
        }
    }
    cout<< '\n';
    system("pause");
}
