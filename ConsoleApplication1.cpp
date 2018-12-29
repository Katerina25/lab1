
#include "stdafx.h"

#include "BookMarket.h"
#include <fstream>

using namespace std;

template<typename T>
void Menu(Keeper<T> &data) {
	cout << "1. Добавить\n2 Удалить\n3 Редактировать\n4 Вывести\nОтмена\n";
	int a;
	T tmp;
	while (!(cin >> a));
	if (a == 1) {
		cin >> tmp;
		data.Add(tmp);
	}
	else if (a == 2) {
		cout << "Индекс: ";
		while (!(cin >> a));
		data.Remove(a);
	}
	else if (a == 3) {
		cout << "Индекс: ";
		while (!(cin >> a));
		cin >> data[a];
	}
	else if (a == 4) {
		for (int i = 0; i < data.Size(); ++i) {
			cout << data[i] << '\n';
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	BookMarket market;
	Kanc k;
	Book b;
	StudentBook s;
	//загрузка из файла
	ifstream in("data");
	if (in) {
		int size;
		in >> size;
		for (int i = 0; i < size; ++i) {
			in >> k;
			market._kanc().Add(k);
		}
		in >> size;
		for (int i = 0; i < size; ++i) {
			in >> b;
			market._book().Add(b);
		}
		in >> size;
		for (int i = 0; i < size; ++i) {
			in >> s;
			market._sbook().Add(s);
		}
	}
	in.close();
	while (true) {
		system("cls");
		cout << "1 Канцелярия\n2 Книги\n3 Учебники\n4 Выход\n";
		int a;
		while (!(cin >> a));
		if (a == 1) {
			Menu(market._kanc());
		}
		else if (a == 2) {
			Menu(market._book());
		}
		else if (a == 3) {
			Menu(market._sbook());
		}
		else {
			break;
		}
		system("pause>>void");
	}

	/*запись в файл*/
	ofstream out("data");
	out << market._kanc().Size() << '\n';
	for (int i = 0; i < market._kanc().Size(); ++i) {
		out << market._kanc()[i] << '\n';
	}
	out << market._book().Size() << '\n';
	for (int i = 0; i < market._book().Size(); ++i) {
		out << market._book()[i] << '\n';
	}
	out << market._sbook().Size() << '\n';
	for (int i = 0; i < market._sbook().Size(); ++i) {
		out << market._sbook()[i] << '\n';
	}
	out.close();
}