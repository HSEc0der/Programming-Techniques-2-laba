#ifndef LinearSearch
#define LinearSearch
#include "Header.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

void linearSearch(vector<OurClass> & data, int length, std::string& key) {
	vector<OurClass> Found;



	double start = clock();
	for (int i = 0; i < length;i++) {
		if (data[i].getFio() == key) {
			Found.push_back(data[i]);
		}
	}
	double end = clock();




	////////ЗАПИСЬ В КОНСОЛЬ/////////////
	/////////////////////////////////////
	cout << "Прямой поиск. При n = " << length << " время поиска составило: " <<
		(end - start) << " миллисекунд\n";
	cout << "Мы искали: " << key  << "\n";
	if (Found.size() > 0) {
		cout << "Нашлось: \n";
		for (int i = 0; i < Found.size(); i++) {
			cout << "\t" << Found[i].AllString() << "\n";
		}
	}
	else {
		cout << "Ничего не найдено\n";
	}
	cout << "------------------------------------------------------------------\n";



	///////ЗАПИСЬ В ФАЙЛ///////
	///////////////////////////
	ofstream file;
	file.open("D:\\УЧЕБА\\Методы программирования\\19var\\laba2\\LinearSearch.txt", ios::app); // окрываем файл для записи
	if (file.is_open())
	{
		file << "Прямой поиск. При n = " << length << " время поиска составило: "
			<< (end - start)  << " миллисекунд\n";
		file << "Мы искали: " << key << " " << "\n";
		if (Found.size() > 0) {
			file << "Нашлось: \n";
			for (int i = 0; i < Found.size(); i++) {
				file << "\t" << Found[i].AllString() << "\n";
			}
		}
		else {
			file << "Ничего не найдено\n";
		}
		file << "------------------------------------------------------------------\n";
	}


}




#endif 
