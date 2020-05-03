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




	////////������ � �������/////////////
	/////////////////////////////////////
	cout << "������ �����. ��� n = " << length << " ����� ������ ���������: " <<
		(end - start) << " �����������\n";
	cout << "�� ������: " << key  << "\n";
	if (Found.size() > 0) {
		cout << "�������: \n";
		for (int i = 0; i < Found.size(); i++) {
			cout << "\t" << Found[i].AllString() << "\n";
		}
	}
	else {
		cout << "������ �� �������\n";
	}
	cout << "------------------------------------------------------------------\n";



	///////������ � ����///////
	///////////////////////////
	ofstream file;
	file.open("D:\\�����\\������ ����������������\\19var\\laba2\\LinearSearch.txt", ios::app); // �������� ���� ��� ������
	if (file.is_open())
	{
		file << "������ �����. ��� n = " << length << " ����� ������ ���������: "
			<< (end - start)  << " �����������\n";
		file << "�� ������: " << key << " " << "\n";
		if (Found.size() > 0) {
			file << "�������: \n";
			for (int i = 0; i < Found.size(); i++) {
				file << "\t" << Found[i].AllString() << "\n";
			}
		}
		else {
			file << "������ �� �������\n";
		}
		file << "------------------------------------------------------------------\n";
	}


}




#endif 
