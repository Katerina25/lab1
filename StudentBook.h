#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class StudentBook {
private:
	int cost;//стоимость
	int pages;//количество страниц
	int year;//год издания
	int year_study;//год обучения
	std::string type;//учебное заведение
	std::string name;//навание
	std::string author;//автор
public:
	StudentBook(int cost = 0, int pages = 0, int year = 0,
		int year_study = 0, const char *type = "",
		const char *name = "", const char *author = "");
	StudentBook(const StudentBook& k);

	/*геттеры и сеттеры*/
	int& _cost();
	int& _pages();
	int& _year();
	int& _year_study();
	std::string& _type();
	std::string& _name();
	std::string& _author();

	friend std::istream& operator >> (std::istream& in, StudentBook& k);
	friend std::ostream& operator <<(std::ostream& out, const StudentBook& k);
};
