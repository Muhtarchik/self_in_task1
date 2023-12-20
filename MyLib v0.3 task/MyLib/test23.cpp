#include "Mylib1.h" 
#include "WwFiles.h" 
#include "time.h"
#include "list"
#include "algorithm"
using namespace std;
int main()
{
	cout << "Press: \n1 - random generate\n2 - read from file\n3 - generate tests\n";
	int select1; cin >> select1;
	switch (select1) {
	case 1: {	
		cout << "How many person belongs to the Group?";
		int PN; cin >> PN;
		time_t start = time(nullptr); // Время в секундах с 1970 года	
		vector<Person> Group(PN);

		cout << "If you want rearenge data by names press1, Surnames - 2, Fimalpoint -3";
		int selection;
		cin >> selection;
		switch (selection) {
		case 1: sort(Group.begin(), Group.end(), lessName); break;
		case 2: sort(Group.begin(), Group.end(), lessSurname); break;
		default: sort(Group.begin(), Group.end());
		}

		for (auto& B : Group) cout << B;

		time_t finish = time(nullptr); // Время в секундах с 1970 года

		cout << "Seconds: " << difftime(finish, start);
		break;
	}
	case 2: {

		string name;
		system("dir *.txt");
		std::cout << "Inpute file name:";
		cin >> name;

		time_t start = time(nullptr); // Время в секундах с 1970 года		
		dataread(name);
		time_t finish = time(nullptr); // Время в секундах с 1970 года

		cout << "Seconds need to read from file: " << difftime(finish, start);
		break;
	}
	
	case 3: {
		
		cout << "Now we gonna generate\n";
	
		list<Person> Group1(10000);
		list<Person> Group2(100000);
		list<Person> Group3(1000000);


		list<Person> Group1_failed;

		list<Person> Group1_lessThen5;
		list<Person> Group1_moreThen5;

		list<Person> Group2_failed;

		list<Person> Group2_lessThen5;
		list<Person> Group2_moreThen5;

		list<Person> Group3_failed;

		list<Person> Group3_lessThen5;
		list<Person> Group3_moreThen5;
		

		time_t start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		
		for (auto iter = Group1.begin(); iter != Group1.end(); ++iter)
		{
			if (iter -> getFinal() < 5.0)
				Group1_lessThen5.push_back(*iter);
			else
				Group1_moreThen5.push_back(*iter);
		}
		time_t finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (10000): " << difftime(finish, start) << endl;

		start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		auto iter = Group1.begin();
		while (true)
		{
			if (iter == Group1.end())
				break;
			if (iter->getFinal() < 5.0)
			{
				Group1_failed.push_back(*iter);
				iter = Group1.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to change in two part (10000): " << difftime(finish, start) << endl;

		start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		for (auto iter = Group2.begin(); iter != Group2.end(); ++iter)
		{
			if (iter -> getFinal() < 5.0)
				Group2_lessThen5.push_back(*iter);
			else
				Group2_moreThen5.push_back(*iter);
		}

		finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (100000): " << difftime(finish, start) << endl;

		iter = Group2.begin();
		while (true)
		{
			if (iter == Group2.end())
				break;
			if (iter->getFinal() < 5.0)
			{
				Group2_failed.push_back(*iter);
				iter = Group2.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		for (auto iter = Group2.begin(); iter != Group2.end(); ++iter)
		{
			if (iter -> getFinal() < 5.0)
				Group3_lessThen5.push_back(*iter);
			else
				Group3_moreThen5.push_back(*iter);
		}
		finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (1000000): " << difftime(finish, start) << endl;

		iter = Group3.begin();
		while (true)
		{
			if (iter == Group3.end())
				break;
			if (iter->getFinal() < 5.0)
			{
				Group3_failed.push_back(*iter);
				iter = Group3.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		int choice;
		cout << "Enter group num: ";
		cin >> choice;
		start = time(nullptr); // Время в секундах с 1970 года	
		switch (choice)
		{
		case 1:
		{
			ofstream less5("less5.txt");
			ofstream more5("more5.txt");
			for (auto& B : Group1_lessThen5) less5 << B;
			for (auto& B : Group1_moreThen5) more5 << B;
			break;
		}
		case 2:
		{
			ofstream less5("less5.txt");
			ofstream more5("more5.txt");
			for (auto& B : Group2_lessThen5) less5 << B;
			for (auto& B : Group2_moreThen5) more5 << B;
			break;
		}
		case 3:
		{
			ofstream less5("less5.txt");
			ofstream more5("more5.txt");
			for (auto& B : Group3_lessThen5) less5 << B;
			for (auto& B : Group3_moreThen5) more5 << B;
			break;
		}
		default:
			break;
		}
		finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to write in two files: " << difftime(finish, start) << endl;
		break;

	}

	default: {
		vector<Person> Group;
		for (int j = 0; j < 3; j++) {
			Person temp;
			cin >> temp;
			Group.push_back(temp);
			temp.~Person();
			//temp cleatr(); 
		}

		cout << "If you want rearenge data by names press 1\nSurnames - 2\nFimalpoint - 3\n";
		int selection;
		cin >> selection;


		time_t start = time(nullptr); // Время в секундах с 1970 года		
		switch (selection) {
		case 1: sort(Group.begin(), Group.end(), lessName); break;
		case 2: sort(Group.begin(), Group.end(), lessSurname); break;
		default: sort(Group.begin(), Group.end());
		}
		for (auto& B : Group) cout << B;
		time_t finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to sort data: " << difftime(finish, start);
		break;
	}


	}


	system("pause");
}