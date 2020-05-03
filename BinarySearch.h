#ifndef BinarySearch
#define BinarySearch


#include "Header.h"
#include <vector>
#include <iostream>
#include <ctime>
#include "QuickSortString.h"
using namespace std;
using namespace N;

void bsearch(vector<OurClass>& data, int start, int end, std::string& key, vector<OurClass>& Found) {
	int up;
	int down;
	if (start > end)
		return;
	int middle = start + ((end - start) / 2);
	if (data[middle].getFio() == key) {
		Found.push_back(data[middle]);

		up = middle; // для поиска остальных значений
		down = middle; // для поиска остальных значений

		// идем вверх и ищем подходящие значения
		up = middle + 1;
		while (up <= end) {
			if (data[up].getFio() == key) {
				Found.push_back(data[up]);
				up += 1;
			}
			else { break; }
		}
		// идем вниз и ищем подходящие значения
		down = middle - 1;
		while (down >= start) {
			if (data[down].getFio() == key) {
				Found.push_back(data[down]);
				down -= 1;
			}
			else { break; }
		}

		return;
	}
	else {
		if (data[middle].getFio() > key) {
			bsearch(data, start, middle - 1, key, Found);
		}
	}

	bsearch(data, middle + 1, end, key, Found);

}

void binarySearch(vector<OurClass> & data, int length,std::string& key) {
	double startWithSort;
	double startWithoutSort;
	double end;
	vector<OurClass> Found1;
	vector<OurClass> copyData(data);
	startWithSort = clock();
	quickSort(copyData, length);
	startWithoutSort = clock();
	bsearch(copyData, 0, length - 1, key, Found1);
	end = clock();


	////////ЗАПИСЬ В КОНСОЛЬ/////////////
	/////////////////////////////////////
	cout << "Бинарный поиск с заранее отсортированным массивом. При n = " << length << " время поиска составило: "
		<< (end - startWithoutSort) << " миллисекунд\n";
	cout << "Бинарный поиск с сортировкой. При n = " << length << " время поиска составило: " <<
		(end - startWithSort)  << " миллисекунд\n";
	cout << "Мы искали: " << key <<" " << Found1.size() << "\n";
	if (Found1.size() > 0) {
		cout << "Нашлось: \n";
		for (int i = 0; i < Found1.size(); i++) {
			cout << "\t" << Found1[i].AllString() << "\n";
		}
	}
	else {
		cout << "Ничего не найдено\n";
	}
	cout << "------------------------------------------------------------------\n";



	///////ЗАПИСЬ В ФАЙЛ///////
	///////////////////////////
	ofstream file;
	file.open("D:\\УЧЕБА\\Методы программирования\\19var\\laba2\\BinarySearch.txt", ios::app); // окрываем файл для записи
	if (file.is_open())
	{
		file << "Бинарный поиск с заранее отсортированным массивом. При n = " << length << " время поиска составило: "
			<< (end - startWithoutSort) << " миллисекунд\n";
		file << "Бинарный поиск с сортировкой. При n = " << length << " время поиска составило: " <<
			(end - startWithSort) << " миллисекунд\n";
		file << "Мы искали: " << key << " " << "\n";
		if (Found1.size() > 0) {
			file << "Нашлось: \n";
			for (int i = 0; i < Found1.size(); i++) {
				file << "\t" << Found1[i].AllString() << "\n";
			}
		}
		else {
			file << "Ничего не найдено\n";
		}
		file << "------------------------------------------------------------------\n";
	}

	
}























#endif
