#ifndef MultiMapSearch
#define MultiMapSearch
#include <iostream>
#include <map>
#include "Header.h"
#include <ctime>
using namespace std;
using namespace N;


void multimapsearch(vector<OurClass> & data, int length, string & key) {
	multimap<string, OurClass> myMap;
	for (int i = 0; i < length; i++) {
		myMap.emplace(data[i].getFio(), data[i]);
	}
	double start = clock();
	auto eqr = myMap.equal_range(key);
	double end = clock();
	auto st = eqr.first;
	auto en = eqr.second;
	

	///////////ЗАПИСЬ В КОНСОЛЬ///////////////
	//////////////////////////////////////////
	cout << "Поиск с multimap. При n = " << length << " время поиска составило: " <<
		end - start << " миллисекунд\n";
	cout << "Мы искали: " << key << "\n";
	if (st != myMap.end()) {
		cout << "Нашлось:\n";
		for (auto it = st; it != en;it++) {
				cout << "\t" << (it->second).AllString() << "\n";
		}
	}
	else {
		cout << "Ничего не нашлось\n";
	}
	cout << "------------------------------------------------------------------\n";


	////////////////ЗАПИСЬ В ФАЙЛ////////////////
	/////////////////////////////////////////////

	ofstream file;
	file.open("D:\\УЧЕБА\\Методы программирования\\19var\\laba2\\MultiMapSearch.txt", ios::app); // окрываем файл для записи
	if (file.is_open()){
		file << "Поиск с multimap. При n = " << length << " время поиска составило: "
			<< (end - start) << " миллисекунд\n";
		file << "Мы искали: " << key << " " << "\n";
		if (st != myMap.end()) {
			file << "Нашлось: \n";
			for (auto it = st; it != en;it++) {
				file << "\t" << (it->second).AllString() << "\n";
			}
		}
		else {
			file << "Ничего не найдено\n";
		}
		file << "------------------------------------------------------------------\n";
	}
}















#endif
