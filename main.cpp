#include<iostream>
#include <cstddef>
#include "String.h"

using namespace std;

int main() {

	char source[11] = "qwerty";

	String s1(source);

	cout << "[]:" << endl;
	for (int i = 0; i < s1.getSize(); i++) {
		cout << s1[i];
	}
	cout << endl << endl;

	String s2(s1);
	cout << "clone:" << endl;
	for (int i = 0; i < s2.getSize(); i++) {
		cout << s2[i];
	}
	cout << endl << endl;

	String s3(s2);
	cout << "move:" << endl;
	for (int i = 0; i < s3.getSize(); i++) {
		cout << s3[i];
	}
	cout << endl << endl;

	String s4, s5;
	s4 = "qwerty";
	cout << "=char" << endl;
	for (int i = 0; i < s4.getSize(); i++) {
		cout << s4[i];
	}
	cout << endl << endl;
	
	s5 = s4;
	cout << "=string" << endl;
	for (int i = 0; i < s5.getSize(); i++) { 
		cout << s5[i];
	}
	cout << endl << endl;

	s3.insert(3, "xx");
	cout << "insert 1" << endl; 
	for (int i = 0; i < s3.getSize(); i++) {
		cout << s3[i];
	}
	cout << endl << endl;

	s3.insert(3, "xx", 1);
	cout << "insert 2" << endl;
	for (int i = 0; i < s3.getSize(); i++) {
		cout << s3[i];
	}
	cout << endl << endl;

	String s7("abc");
	String s8("abd");
	String s9("abc");
	String s10("abb");
	cout << "compare:" << endl << s7.compare(s8)<<" "<< s7.compare(s9)<<" "<< s7.compare(s10) << endl << endl;
	
	cout << "find:" << endl << s1.find("rt", 0, 2) << endl << endl;
	
	cout << "Selection sort:" << endl;
	String array[7] = { s1, s3, s5, s7, s8, s9, s10 };
	cout << "Before:" << endl << endl;;
	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < array[i].getSize(); k++) {
			cout << array[i][k];
		}
		cout << endl;
	}

	String tempsort;
	for (int i = 0; i < 7; i++) {

		for (int k = i + 1; k < 7; k++) {

			if (array[i].compare(array[k]) > 0) {
				
				tempsort = array[i];
				array[i] = array[k];
				array[k] = tempsort;

			}

		}

	}
	cout <<endl<< "After:" << endl << endl;;
	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < array[i].getSize(); k++) {
			cout << array[i][k];
		}
		cout << endl;
	}

	cout << endl << "Task 3:" << endl;

	int task3counter(0);

	for (int i = 0; i < 7; i++) {

		if (array[i].find("ab", 0, 2)==0) {

			task3counter++;
			array[i].insert(0, "x");

		}

	}

	cout << "Strings starting with ab: " << task3counter << endl;
	cout << endl << "After changing (added x):" << endl;
	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < array[i].getSize(); k++) {
			cout << array[i][k];
		}
		cout << endl;
	}

	cout << endl;
	task3counter = 0;
	for (int i = 0; i < 7; i++) {

		if (array[i].find("qw", 0, 2) == 0) {

			task3counter++;
			array[i].insert(0, "u");

		}

	}

	cout << "Strings starting with qw: " << task3counter << endl;
	cout << endl << "After changing (added u):" << endl;
	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < array[i].getSize(); k++) {
			cout << array[i][k];
		}
		cout << endl;
	}
	cout << endl << endl;

	system("pause");
	return 0;

}