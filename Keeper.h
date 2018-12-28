#pragma once
#include "BookMarket.h"

//массив с динамическим добавлением и удалением элементов
template<typename T>
class Keeper {
private:
	T *data;
	unsigned _size;
public:
	Keeper();
	~Keeper();
	void Add(const T & sign);//добавление в конец массива
	T & operator[](unsigned index);//получение элемента по индексу
	unsigned Size();//размер
	void Remove(unsigned index);//удаление
	void Clear();//очищаение массива
};

template<typename T>
Keeper<T>::Keeper() :data(nullptr), _size(0) { std::cout << "\nконструктор Keeper"; }
template<typename T>
Keeper<T>::~Keeper() { delete[] data; std::cout << "\nдеструктор Keeper"; }

template<typename T>
void Keeper<T>::Add(const T & sign) {//добавление в конец массива
	T *temp;//буфер
	try {//обрабатываем исключение
		temp = new T[_size + 1];
	}
	catch (...) {
		throw Exception("Ошибка выделения памяти");
	}
	//копируем в буфер
	for (unsigned i = 0; i < _size; ++i) {
		temp[i] = data[i];
	}
	temp[_size] = sign;
	//копируем в поле
	delete[] data;
	data = temp;
	++_size;
}

template<typename T>
T & Keeper<T>::operator[](unsigned index) {//получение элемента по индексу
	if (index >= _size) {
		throw Exception("Индекс вне границ массива");
	}
	return data[index];
}

template<typename T>
void Keeper<T>::Remove(unsigned index) {//удаление элемента
	if (index >= _size) {
		throw Exception("Индекс вне границ массива");
	}
	T *temp;//буфер
	try {//обрабатываем исключение
		temp = new T[_size + 1];
	}
	catch (...) {
		throw Exception("Ошибка выделения памяти");
	}
	//копируем в буфер, ропуская не нужный
	for (unsigned i = 0; i < _size; ++i) {
		if (i != index) {
			temp[i] = data[i];
		}
	}
	//копируем в поле
	delete[] data;
	data = temp;
	--_size;
}
template<typename T>
unsigned Keeper<T>::Size() { return _size; }

template<typename T>
void Keeper<T>::Clear() {
	_size = 0;
	delete[] data;
	data = nullptr;
}
