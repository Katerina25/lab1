#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class StudentBook {
private:
	int cost;//���������
	int pages;//���������� �������
	int year;//��� �������
	int year_study;//��� ��������
	std::string type;//������� ���������
	std::string name;//�������
	std::string author;//�����
public:
	StudentBook(int cost = 0, int pages = 0, int year = 0,
		int year_study = 0, const char *type = "",
		const char *name = "", const char *author = "");
	StudentBook(const StudentBook& k);

	/*������� � �������*/
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
