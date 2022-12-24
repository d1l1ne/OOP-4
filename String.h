#pragma once
#include<iostream>
#include <cstddef>

using namespace std;

class String {

private:

	size_t size;
	size_t capacity;
	char* pointer;

public:

	String();
	String(const char* str);
	String(const String& str);
	String(String&& str) noexcept;
	~String();
	String& operator=(const char* str);
	String& operator=(String& str) noexcept;
	char& operator[](size_t pos);
	String& insert(size_t pos, const char* str);
	int compare(String& str);
	String& insert(size_t pos, const char* str, size_t n);
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t getSize();

};