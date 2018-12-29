#include "stdafx.h" 
#include "StudentBook.h"

StudentBook::StudentBook(int cost, int pages, int year,
	int year_study, const char *type,
	const char *name, const char *author)
	:cost(cost), pages(pages), year(year), type(type), year_study(year_study), name(name), author(author) {}
StudentBook::StudentBook(const StudentBook& k)
	: cost(k.cost), pages(k.pages), year(k.year), type(k.type), year_study(k.year_study), name(k.name), author(k.author) {}
int& StudentBook::_cost() { return cost; }
int& StudentBook::_pages() { return pages; }
int& StudentBook::_year() { return year; }
int& StudentBook::_year_study() { return year_study; }
std::string& StudentBook::_type() { return type; }
std::string& StudentBook::_name() { return name; }
std::string& StudentBook::_author() { return author; }

std::istream& operator >> (std::istream& in, StudentBook& k) {
	std::cout << " ¬ведите стоимость\n ¬ведите количество страниц\n ¬ведите год издани€\n ¬ведите год обучени€\n ¬ведите название учебного заведени€\n ¬ведите название\n ¬ведите автора\n";
	if (!(in >> k.cost >> k.pages >> k.year >> k.year_study >> k.type >> k.name >> k.author)) throw Exception("Error readig");
	return in;
}
std::ostream& operator<<(std::ostream& out, const StudentBook& k) {
	out << k.cost << ' ' << k.pages << ' ' << k.year << ' ' << k.year_study << ' ' << k.type << ' ' << k.name << ' ' << k.author;
	return out;
}