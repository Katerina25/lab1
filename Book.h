#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class Book {
private:
	int cost;//стоимость
	int pages;//количество страниц
	int year;//год издания
	std::string type;//жанр
	std::string annotation;//аннотация
	std::string name;//навание
	std::string author;//автор
public:
	Book(int cost = 0, int pages = 0, int year = 0,
		const char *type = "", const char *annotation = "",
		const char *name = "", const char *author = "");
	Book(const Book& k);

	//геттеры и сеттеры
	int& _cost();
	int& _pages();
	int& _year();
	std::string& _type();
	std::string& _annotation();
	std::string& _name();
	std::string& _author();

	friend std::istream& operator >> (std::istream& in, Book& k);
	friend std::ostream& operator<<(std::ostream& out, const Book& k);
};