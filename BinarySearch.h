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

		up = middle; // ��� ������ ��������� ��������
		down = middle; // ��� ������ ��������� ��������

		// ���� ����� � ���� ���������� ��������
		up = middle + 1;
		while (up <= end) {
			if (data[up].getFio() == key) {
				Found.push_back(data[up]);
				up += 1;
			}
			else { break; }
		}
		// ���� ���� � ���� ���������� ��������
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


	////////������ � �������/////////////
	/////////////////////////////////////
	cout << "�������� ����� � ������� ��������������� ��������. ��� n = " << length << " ����� ������ ���������: "
		<< (end - startWithoutSort) << " �����������\n";
	cout << "�������� ����� � �����������. ��� n = " << length << " ����� ������ ���������: " <<
		(end - startWithSort)  << " �����������\n";
	cout << "�� ������: " << key <<" " << Found1.size() << "\n";
	if (Found1.size() > 0) {
		cout << "�������: \n";
		for (int i = 0; i < Found1.size(); i++) {
			cout << "\t" << Found1[i].AllString() << "\n";
		}
	}
	else {
		cout << "������ �� �������\n";
	}
	cout << "------------------------------------------------------------------\n";



	///////������ � ����///////
	///////////////////////////
	ofstream file;
	file.open("D:\\�����\\������ ����������������\\19var\\laba2\\BinarySearch.txt", ios::app); // �������� ���� ��� ������
	if (file.is_open())
	{
		file << "�������� ����� � ������� ��������������� ��������. ��� n = " << length << " ����� ������ ���������: "
			<< (end - startWithoutSort) << " �����������\n";
		file << "�������� ����� � �����������. ��� n = " << length << " ����� ������ ���������: " <<
			(end - startWithSort) << " �����������\n";
		file << "�� ������: " << key << " " << "\n";
		if (Found1.size() > 0) {
			file << "�������: \n";
			for (int i = 0; i < Found1.size(); i++) {
				file << "\t" << Found1[i].AllString() << "\n";
			}
		}
		else {
			file << "������ �� �������\n";
		}
		file << "------------------------------------------------------------------\n";
	}

	
}























#endif
