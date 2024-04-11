#pragma once
class Set
{
public:
	Set(Set& other);
	Set();
	~Set();
	Set& operator+=(int num);
	Set& operator-=(int num);
	friend Set operator+(Set& left, Set& right);
	friend Set operator*(Set& left, Set& right);
	friend Set operator-(Set& left, Set& right);
	void printSet();
private:
	int arr[1];
	int size = 0;
};

