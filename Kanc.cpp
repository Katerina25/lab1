#include "stdafx.h"
#include "Kanc.h"

Kanc::Kanc(int cost, const char* target, const char *color, const char *type)
	:cost(cost), target(target), color(color), type(type) {}
Kanc::Kanc(const Kanc& k)
	: cost(k.cost), target(k.target), color(k.color), type(k.type) {}
int& Kanc::_cost() { return cost; }
std::string& Kanc::_target() { return target; }
std::string& Kanc::_color() { return color; }
std::string& Kanc::_type() { return type; }

std::istream& operator >> (std::istream& in, Kanc& k) {
	std::cout << " ¬ведите стоимость\n ¬ведите назначение\n ¬ведите цвет\n ¬ведите тип\n";
	if (!(in >> k.cost >> k.target >> k.color >> k.type)) throw Exception("Error readig");
	return in;
}
std::ostream& operator<<(std::ostream& out, const Kanc& k) {
	out << k.cost << ' ' << k.target << ' ' << k.color << ' ' << k.type;
	return out;
}