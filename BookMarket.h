#pragma once
#include "Book.h"
#include "StudentBook.h"
#include "Kanc.h"
#include "Keeper.h"

class BookMarket {
private:
	Keeper<Book> book;
	Keeper<StudentBook> sbook;
	Keeper<Kanc> kanc;
public:
	Keeper<Book>& _book();
	Keeper<StudentBook>& _sbook();
	Keeper<Kanc>& _kanc();
};

#pragma once
