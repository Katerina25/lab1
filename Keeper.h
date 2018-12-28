#pragma once
#include "BookMarket.h"

//������ � ������������ ����������� � ��������� ���������
template<typename T>
class Keeper {
private:
	T *data;
	unsigned _size;
public:
	Keeper();
	~Keeper();
	void Add(const T & sign);//���������� � ����� �������
	T & operator[](unsigned index);//��������� �������� �� �������
	unsigned Size();//������
	void Remove(unsigned index);//��������
	void Clear();//��������� �������
};

template<typename T>
Keeper<T>::Keeper() :data(nullptr), _size(0) { std::cout << "\n����������� Keeper"; }
template<typename T>
Keeper<T>::~Keeper() { delete[] data; std::cout << "\n���������� Keeper"; }

template<typename T>
void Keeper<T>::Add(const T & sign) {//���������� � ����� �������
	T *temp;//�����
	try {//������������ ����������
		temp = new T[_size + 1];
	}
	catch (...) {
		throw Exception("������ ��������� ������");
	}
	//�������� � �����
	for (unsigned i = 0; i < _size; ++i) {
		temp[i] = data[i];
	}
	temp[_size] = sign;
	//�������� � ����
	delete[] data;
	data = temp;
	++_size;
}

template<typename T>
T & Keeper<T>::operator[](unsigned index) {//��������� �������� �� �������
	if (index >= _size) {
		throw Exception("������ ��� ������ �������");
	}
	return data[index];
}

template<typename T>
void Keeper<T>::Remove(unsigned index) {//�������� ��������
	if (index >= _size) {
		throw Exception("������ ��� ������ �������");
	}
	T *temp;//�����
	try {//������������ ����������
		temp = new T[_size + 1];
	}
	catch (...) {
		throw Exception("������ ��������� ������");
	}
	//�������� � �����, �������� �� ������
	for (unsigned i = 0; i < _size; ++i) {
		if (i != index) {
			temp[i] = data[i];
		}
	}
	//�������� � ����
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
