#include "Set.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

Set::Set(Set& other) {
	this->arr = other.arr;
	this->size = other.size;
}

Set::Set() {
	arr = new int[100];
}

Set::Set(int* aray) {
	arr = aray;
}

Set::~Set() {
	cout << "Set destroyed " << endl;
}

void Set::printSet() {
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

Set& Set::operator+=(const int num) {
	
	size++;
	if (size != 1) {
		arr[size-1] = num;
		
	}
	else {
		arr[0] = num;
	}
	return *this;
}
Set& Set::operator-=(int num) {

	for (int l = 1; l <= num; l++) {
		int* temp = new int[size];
		*temp = (int)malloc(sizeof(int) * size);

		for (int j = 0; j < size; j++) {
			temp[j] = arr[j];
		}

		size--;
		new int[size];

		for (int j = 0; j < size; j++) {
			arr[j] = temp[j];
		}

		free(temp);
	}
	Set returnSet;
	returnSet.arr = arr;
	returnSet.size = size;
	return returnSet;
	
}

Set* operator+(Set& left, Set& right) {
	
	int* ptr = new int[left.size + right.size];
	int index = 0;
	int returnSetIndex = 0;
	Set *returnSet = new Set();
	for (int i = 0; i < left.size; i++) {
		for (int j = 0; j < right.size; j++) {
			if (left.arr[i] = right.arr[j]) {
				ptr[index] = left.arr[i];
				returnSet->arr[index] = left.arr[i];
				index++;
				returnSetIndex++;
				break;
			}
		}
	}

	for (int i = 0; i < left.size; i++) {
		bool found = false;
		for (int j = 0; j < index; j++) {
			if (left.arr[i] == ptr[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			returnSet->arr[returnSetIndex] = left.arr[i];
			returnSetIndex++;
		}
	}

	for (int i = 0; i < right.size; i++) {
		bool found = false;
		for (int j = 0; j < index; j++) {
			if (right.arr[i] == ptr[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			returnSet->arr[returnSetIndex] = right.arr[i];
			returnSetIndex++;
		}
	}

	return returnSet;
}

Set* operator-(Set& left, Set& right) {
	Set *returnSet = new Set();
	
	for (int i = 0; i < left.size; i++) {
		bool found = false;
		for (int j = 0; j < right.size; j++) {
			if (left.arr[i] = right.arr[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			returnSet->arr[returnSet->size] = left.arr[i];
			returnSet->size++;
		}
	}
	
	return returnSet;
}

Set* operator*(Set& left, Set& right) {
	Set *returnSet = new Set();
	for (int i = 0; i < left.size; i++) {
		for (int j = 0; j < right.size; j++) {
			if (left.arr[i] = right.arr[j]) {
				returnSet->arr[returnSet->size] = left.arr[i];
				returnSet->size++;
				break;
			}
		}
	}

	return returnSet;
}