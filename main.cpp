#include <iostream>
#include "Header.h"
#include "fstream"
#include <vector>
#include <string>
#include "QuickSortString.h"
#include "LinearSearch.h"
#include "BinarySearch.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	vector<string> strings;
	ifstream In("D:\\УЧЕБА\\Методы программирования\\19var\\DataCpp.txt");
	string str;
	while (!In.eof())
	{
		getline(In, str);
		strings.push_back(str);

	}
	vector<OurClass> Data;
	for (int i = 0; i < strings.size();i++) {
		Data.push_back(N::OurClass(strings[i]));
	}
	string fio = "Ябурова Ника Яновна";
	int dev[7] = { 100,1000,1000,20000,50000,70000,Data.size() };
	for (int i = 0; i < 7; i++) {
		linearSearch(Data, dev[i], fio);
		binarySearch(Data, dev[i], fio);
	}
}