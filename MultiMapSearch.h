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
	

	///////////������ � �������///////////////
	//////////////////////////////////////////
	cout << "����� � multimap. ��� n = " << length << " ����� ������ ���������: " <<
		end - start << " �����������\n";
	cout << "�� ������: " << key << "\n";
	if (st != myMap.end()) {
		cout << "�������:\n";
		for (auto it = st; it != en;it++) {
				cout << "\t" << (it->second).AllString() << "\n";
		}
	}
	else {
		cout << "������ �� �������\n";
	}
	cout << "------------------------------------------------------------------\n";


	////////////////������ � ����////////////////
	/////////////////////////////////////////////

	ofstream file;
	file.open("D:\\�����\\������ ����������������\\19var\\laba2\\MultiMapSearch.txt", ios::app); // �������� ���� ��� ������
	if (file.is_open())
	{
		file << "������ �����. ��� n = " << length << " ����� ������ ���������: "
			<< (end - start) << " �����������\n";
		file << "�� ������: " << key << " " << "\n";
		if (st != myMap.end()) {
			file << "�������: \n";
			for (auto it = st; it != en;it++) {
				file << "\t" << (it->second).AllString() << "\n";
			}
		}
		else {
			file << "������ �� �������\n";
		}
		file << "------------------------------------------------------------------\n";
	}
}















#endif
