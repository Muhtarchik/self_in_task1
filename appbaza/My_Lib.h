
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int minimum(int a, int b);

class Student {

	string Name, Surname;

	int HW[10];
	int Exam;
	float Rez;
public:
	Student() { 
		cout << "Input name: "; cin >> Name; 
		cout << "Input surname: "; cin >> Surname;
	
	}

};