#pragma once
#include "Exception.h"
#include <string>
#include <iostream>

class Kanc {//канцел€ри€
private:
	int cost;//стоимость
	std::string type; //тип
	std::string color; //цвет
	std::string target;//назначение
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