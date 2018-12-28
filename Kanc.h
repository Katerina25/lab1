#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class Kanc {//����������
private:
	int cost;//���������
	std::string type; //���
	std::string color; //����
	std::string target;//����������
public:
	Kanc(int cost = 0, const char* target = "", const char *color = "", const char *type = "");
	Kanc(const Kanc& k);
	int& _cost();
	std::string& _target();
	std::string& _color();
	std::string& _type();

	friend std::istream& operator >> (std::istream& in, Kanc& k);
	friend std::ostream& operator<<(std::ostream& out, const Kanc& k);
};