#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class Book {
private:
	int cost;//���������
	int pages;//���������� �������
	int year;//��� �������
	std::string type;//����
	std::string annotation;//���������
	std::string name;//�������
	std::string author;//�����
public:
	Book(int cost = 0, int pages = 0, int year = 0,
		const char *type = "", const char *annotation = "",
		const char *name = "", const char *author = "");
	Book(const Book& k);

	//������� � �������
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