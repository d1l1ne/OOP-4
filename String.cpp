#pragma warning(disable:6386)
#pragma warning(disable:6385)
#pragma warning(disable:6001)
#include<iostream>
#include <cstddef>
#include "string.h"

using namespace std;

String::String() {

	size = 0;
	capacity = 0;
	pointer = nullptr;


}
String::String(const char* str) {

	capacity = sizeof(str);
	size = 0;
	for (int i = 0; str[i]; i++) {
		size++;
	}
	pointer = new char[size];

	for (int i = 0; i < size; i++) {

		pointer[i] = str[i];

	}

}

String::String(const String& str) {
	
	capacity = str.capacity;
	size = str.size;
	pointer = new char[size];

	for (int i = 0; i < size; i++){

		pointer[i] = str.pointer[i];

	}

}

String::~String() {

}

String::String(String&& str) noexcept {

	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;

	str.size = 0;
	str.capacity = 0;
	str.pointer = nullptr;

}

String& String::operator= (const char* str) {

	capacity = sizeof(str);
	size = 0;
	for (int i = 0; str[i]; i++) {
		size++;
	}
	pointer = const_cast<char*>(str);

	return *this;

}

String& String::operator=(String& str) noexcept {

	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;

	str.size = 0;
	str.capacity = 0;
	str.pointer = nullptr;

	return *this;

}

char& String::operator[](size_t pos) {

	try {

		return pointer[pos];

	}
	catch (exception& e) {

		cout << e.what() << endl;
		throw e;

	}
	
}

String& String::insert(size_t pos, const char* str) {

	size_t tempsize, tempcapacity;
	

	if (sizeof(str) == 0) {

		return *this;

	}
	else {

		size_t tsize = 0;
		for (int i = 0; str[i]; i++) {
			tsize++;
		}
		char* str1 = new char[tsize];
		for (int o = 0; o < tsize; o++) {

			str1[o] = str[o];

		}

		tempcapacity = sizeof(str1);
		tempsize = tsize;

		size_t newsize = size + tempsize;
		size_t newcapacity = capacity + tempcapacity;

		char* tempchar = new char[newsize];
		for (int i = 0; i < pos; i++) {

			tempchar[i] = pointer[i];

		}
		size_t y(0);
		for (size_t k = pos; k < pos + tempsize; k++) {

			tempchar[k] = str1[y];
			y++;

		}
		y = pos;
		for (size_t e = pos + tempsize; e < newsize; e++) {

			tempchar[e] = pointer[y];
			y++;

		}

		size = newsize;
		capacity = newcapacity;
		pointer = new char[newsize];

		for (int h = 0; h < newsize; h++) {

			pointer[h] = tempchar[h];

		}

		return *this;
	}

}

int String::compare(String& str) {

	int result = 0;
	size_t counter;
	
	if (sizeof(str) < capacity) {
		counter = sizeof(str) / sizeof(str[0]);
	}
	else if (sizeof(str) > capacity) {
		counter = size;
	}
	else if (sizeof(str) == 0) {
		return 1;
	}
	else {
		counter = size;
	}

	for (int i = 0; i < counter; i++) {

		if (pointer[i] < str[i]) {

			result = -1;
			break;

		}
		else if (pointer[i] > str[i]) {

			result = 1;
			break;

		}

	}

	return result;

}

String& String::insert(size_t pos, const char* str, size_t n) {

	size_t tempsize, tempcapacity;
	int g(0);
	for (int i = 0; str[i]; i++) {
		g++;
	}
	if (sizeof(str) == 0|| g < n ) {

		return *this;

	}
	else {

		char* str1 = new char[n];
		for (int o = 0; o < n; o++) {
			
			str1[o] = str[o];

		}

		tempcapacity = sizeof(str1);
		tempsize = n;

		size_t newsize = size + tempsize;
		size_t newcapacity = capacity + tempcapacity;

		char* tempchar = new char[newsize];
		for (size_t i = 0; i < pos; i++) {

			tempchar[i] = pointer[i];

		}
		size_t y(0);
		for (size_t k = pos; k < pos + tempsize; k++) {

			tempchar[k] = str1[y];
			y++;

		}
		y = pos;
		for (size_t e = pos + tempsize; e < newsize; e++) {

			tempchar[e] = pointer[y];
			y++;

		}

		size = newsize;
		capacity = newcapacity;
		pointer = new char[newsize];

		for (size_t h = 0; h < newsize; h++) {

			pointer[h] = tempchar[h];

		}

		return *this;
	}

}

size_t String::find(const char* str, size_t pos, size_t n) const {

	size_t result(0); 
	size_t g(0);
	for (int i = 0; str[i]; i++) {
		g++;
	}

	if (n > g || n <= 0) {

		cerr << "n must be less or equal str size" << endl;
		return -792;

	}
	else {

		bool state(false);

		for (int i = pos; i < size - n+1; i++) {

			int y = 0;
			
			for (int k = 0; k < n; k++) {
				
				if (str[k] != pointer[i + y]) {
					
					break;

				}
				else if (k == n - 1 && str[k] == pointer[i + y]) {
					
					state = true;

				}
				y++;
				
			}

			if (state) {

				result = i;
				break;

			}

		}
		if (state) {
			return result;
		}
		else {
			return -792;
		}
		

	}

}

size_t String::getSize() {
	
	return size;

}