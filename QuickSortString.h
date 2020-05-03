#ifndef QuickSortString
#define QuickSortString

#include "Header.h"
#include "string"
using namespace std;
using namespace N;

void qsort(vector<OurClass> & data, int first, int last) {
	N::OurClass count;
	string mid;
	int f = first;
	int l = last;
	mid = (data[(f + l) / 2]).getFio();
	do {
		while ((data[f]).getFio() < mid) {
			f++;
		}
		while ((data[l]).getFio() > mid) {
			l--;
		}
		if (f <= l) {
			count = data[f];
			data[f] = data[l];
			data[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) {
		qsort(data, first, l);
	}
	if (f < last) {
		qsort(data, f, last);
	}
}

void quickSort(vector<OurClass>& data, int length) {
	qsort(data, 0, length - 1);
}











#endif QuickSortString