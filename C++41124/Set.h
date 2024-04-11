#pragma once
class Set
{
public:
	Set(Set& other);
	Set(int* aray);
	Set();
	~Set();
	Set& operator+=(int num);
	Set& operator-=(int num);
	friend Set* operator+(Set& left, Set& right);
	friend Set* operator*(Set& left, Set& right);
	friend Set* operator-(Set& left, Set& right);
	void printSet();
private:
	int* arr;
	int size = 0;
};

