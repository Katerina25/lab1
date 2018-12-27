#include "stdafx.h"
#include "BookMarket.h"

Keeper<Book>& BookMarket::_book() { return book; }
Keeper<StudentBook>& BookMarket::_sbook() { return sbook; }
Keeper<Kanc>& BookMarket::_kanc() { return kanc; }