#include "Header.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

// конструктор
N::OurClass::OurClass(const std::string& str) {
	std::vector<std::string> v;
	int size = str.size();
	int left = 0;
	int right;
	int numspace = 5;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && numspace > 0) {
			right = i;
			v.push_back(str.substr(left, right - left));
			left = i + 1;
			numspace--;
		}
	}
	home = std::stoi(v[0]);
	flat = std::stoi(v[1]);
	room = std::stoi(v[2]);
	s = std::stoi(v[3]);
	people = std::stoi(v[4]);
	fio = str.substr(left);
}

N::OurClass::OurClass() {
	home = 0;
	flat = 0;
	s = 0;
	fio = "";
	people = 0;
	room = 0;
}

//возвращает номер дома
int N::OurClass::getHome() {
	return home;
}
//возвращает номер квартиры
int N::OurClass::getFlat() {
	return flat;
}

//возвращает площадь
int N::OurClass::getSquare() {
	return s;
}

int N::OurClass::getPeople() {
	return people;
}
//возврашает ФИО
std::string N::OurClass::getFio() {
	return fio;
}

std::string N::OurClass::AllString() {
	return std::to_string(home) + " " + std::to_string(flat) + " " + std::to_string(room) + " " + std::to_string(s) + " " +
		std::to_string(people) + " " + fio;
}
//работает также, как конструктор
void N::OurClass::setAll(std::string& str) {
	std::vector<std::string> v;
	int size = str.size();
	int left = 0;
	int right;
	int numspace = 5;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ' && numspace > 0) {
			right = i;
			v.push_back(str.substr(left, right - left));
			left = i + 1;
			numspace--;
		}
	}
	home = std::stoi(v[0]);
	flat = std::stoi(v[1]);
	room = std::stoi(v[2]);
	s = std::stoi(v[3]);
	people = std::stoi(v[4]);
	fio = str.substr(left);
}

std::string N::OurClass::showSorted() {
	return std::to_string(s) + " " + std::to_string(home) + " " + std::to_string(flat) + " " + fio;
}

//// перегрузка оператора сравнения БОЛЬШЕ
bool N::operator>(const OurClass& left, const OurClass& right) {
	if ((left.fio > right.fio)) {
		return true;

	}
	else
		return false;
}

// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
bool N::operator>=(const OurClass& left, const OurClass& right) {
	if ((left.fio > right.fio) || (left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};


// перегрузка оператора МЕНЬШЕ
bool N::operator<(const OurClass& left, const OurClass& right) {
	if (left.fio < right.fio) {
		return true;

	}
	else
		return false;
};


//перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
bool N::operator<=(const OurClass& left, const OurClass& right) {
	if ((left.fio < right.fio) ||  (left.fio == right.fio)) {
		return true;

	}
	else
		return false;
};
