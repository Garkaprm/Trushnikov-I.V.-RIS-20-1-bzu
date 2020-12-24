#include <iostream>
#include <fstream> 

using namespace std;

struct list { //создание структуры
	int data;
	list* link;
	list* relink;
};
list* head = 0, * tail = 0; //указатели на адрес элемента

void addtobeg() //функция для добавления элемента в начало списка
{
	list* p = new list;
	cout<< ("Введите новый элемент: ");
	cin>> p->data;
	if (head == NULL)
	{
		tail = p;
	}
	p->link = head;
	head = p;
}

void addtoend() { //функция для добавления элемента в конец списка
	list* p = new list;
	printf("Введите новый элемент: ");
	cin>> p->data;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		tail->link = p;
	}
	p->link = NULL;
	tail = p;
}

void delofelem() //функция для удаления элемента списка по заданию варианта 8
{
	int index;
	list* p = head;
	list* pk;
	if (head == NULL)
	{
		printf("Список пуст.");
		printf("\n");
	}
	else
	{
		printf("Введите номер элемента, после которого хотите удалить элемент: ");
		cin>> index;
		printf("\n");
			for (int i = 1; i < index - 1; i++)
			{
				p = head->link;
			}
			pk = p->link->link;
			p->link->link = pk->link;
			delete pk;
			p = head;
	}
}

void deltolist() //удаление списка
{
	list* p = head;
	if (p == NULL)
	{
		printf("СПИСОК ПУСТ.");
		printf("\n\n");
	}
	else
	{
		while (p != NULL)
		{
			head = p->link;
			delete p;
			p = head;
		}
	}
	cout << endl;
}

void out()  //функция для вывода списка в консоль
{
	list* p = head; 
	if (p == NULL)
	{
		printf("Список пуст.");
		printf("\n\n");
	}
	else
	{
		printf("Полученный список: ");
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->link;
		}
		printf("\n");
	}
	cout << endl;
}
void outfile(int n) //функция для записи даных из файла в программу
{
	int* mas = new int[sizeof(list)];
	ifstream fin("db.txt");
	cout << "Полученный из файла список: ";
	for (int i = 0; i < n - 1; i++) {
		fin >> mas[i];
		cout << mas[i] << " ";
	}
	cout << endl << endl;
}

FILE* db;  //указатель, связанный с файлом
void infile() //функция для записи списка в файл
{
	db = fopen("db.txt", "w");
	list* p = head;
		while (p != NULL)
		{
			fprintf(db, "%d", p->data);
			fputc('\n', db); //Запись обозначения конца строки
			p = p->link;
		}
	fclose(db); //закрытие потока
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите колиество элементов списка: ";
	int n, kol;
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		addtoend(); //Вызов функции
	}
	cout << endl;
	out(); //Вызов функции
	delofelem(); //Вызов функции
	out(); //Вызов функции
	cout << "Введите колиество элементов, которые необходимо добавить в начало списка: ";
	cin >> kol;
	cout << endl;
	for (int i = 0; i < kol; i++) {
		addtobeg(); //Вызов функции
	}
	cout << endl;
	out(); //Вызов функции
	cout << "Запись списка в файл db.txt\n";
	infile(); //Вызов функции
	cout << "Удаление списка.";
	deltolist(); //Вызов функции
	out(); //Вызов функции
	cout << "Заполнение списка из файла bd.txt\n";
	outfile(n+kol); //Вызов функции
	system("pause");
}