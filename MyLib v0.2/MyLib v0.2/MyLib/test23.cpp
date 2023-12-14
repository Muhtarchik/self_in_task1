#include "Mylib1.h" 
#include "WwFiles.h" 
#include "time.h"
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
	


		vector<Person> Group1(10000);
		vector<Person> Group2(100000);
		vector<Person> Group3(1000000);
		
		// Не нужна, просто для вида
		// Добавить измерения
		sort(Group1.begin(), Group1.end(), isLuckyStudent);
		sort(Group2.begin(), Group2.end(), isLuckyStudent);
		sort(Group3.begin(), Group3.end(), isLuckyStudent);


		vector<Person> Group1_lessThen5;
		vector<Person> Group1_moreThen5;

		vector<Person> Group2_lessThen5;
		vector<Person> Group2_moreThen5;

		vector<Person> Group3_lessThen5;
		vector<Person> Group3_moreThen5;
		

		time_t start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		for (int i = 0; i < 10000; i++)
		{
			if (Group1[i].getFinal() < 5.0)
				Group1_lessThen5.push_back(Group1[i]);
			else
				Group1_moreThen5.push_back(Group1[i]);
		}
		time_t finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (10000): " << difftime(finish, start) << endl;

		start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		for (int i = 0; i < 100000; i++)
		{
			if (Group2[i].getFinal() < 5.0)
				Group2_lessThen5.push_back(Group2[i]);
			else
				Group2_moreThen5.push_back(Group2[i]);
		}
		 finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (100000): " << difftime(finish, start) << endl;

		start = time(nullptr); // Время в секундах с 1970 года	
		// Логика того, как делятся студенты
		for (int i = 0; i < 1000000; i++)
		{
			if (Group3[i].getFinal() < 5.0)
				Group3_lessThen5.push_back(Group3[i]);
			else
				Group3_moreThen5.push_back(Group3[i]);
		}
		finish = time(nullptr); // Время в миллисекундах с 1970 года

		cout << "Seconds to split in two part (1000000): " << difftime(finish, start) << endl;

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