#include "stdafx.h"
#include "Book.h"

Book::Book(int cost, int pages, int year,
	const char *type, const char *annotation,
	const char *name, const char *author)
	:cost(cost), pages(pages), year(year), type(type), annotation(annotation), name(name), author(author) {}
Book::Book(const Book& k)
	: cost(k.cost), pages(k.pages), year(k.year), type(k.type), annotation(k.annotation), name(k.name), author(k.author) {}

int& Book::_cost() { return cost; }
int& Book::_pages() { return pages; }
int& Book::_year() { return year; }
std::string& Book::_type() { return type; }
std::string& Book::_annotation() { return annotation; }
std::string& Book::_name() { return name; }
std::string& Book::_author() { return author; }

std::istream& operator >> (std::istream& in, Book& k) {
	if (!(in >> k.cost >> k.pages >> k.year >> k.year >> k.annotation >> k.name >> k.author)) throw Exception("Error readig");
	return in;
}

std::ostream& operator<<(std::ostream& out, const Book& k) {
	out << k.cost << ' ' << k.pages << ' ' << k.year << ' ' << k.year << ' ' << k.annotation << ' ' << k.name << ' ' << k.author;
	return out;
}