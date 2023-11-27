#include "Mylib1.h" 
#include "WwFiles.h" 

int main()
{
	cout << "Use automatic user generation (1),read from file(2) or turn on manual input of all data";
	int select1; cin >> select1;
	switch (select1) {
	case 1: {
		cout << "How many person belongs to the Group?";
		int PN; cin >> PN;
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
		break;
	}
	case 2: {

		string name;
		system("dir *.txt");
		std::cout << "Inpute file name:";
		cin >> name;
		dataread(name); break;
	}
	
	case 3: {
		cout << "Now we gonna generate";
		
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
		

		// Логика того, как делятся студенты
		for (int i = 0; i < 10000; i++)
		{
			if (Group1[i].getFinal() < 5.0)
				Group1_lessThen5.push_back(Group1[i]);
			else
				Group1_moreThen5.push_back(Group1[i]);
		}

		// Логика того, как делятся студенты
		for (int i = 0; i < 100000; i++)
		{
			if (Group2[i].getFinal() < 5.0)
				Group2_lessThen5.push_back(Group2[i]);
			else
				Group2_moreThen5.push_back(Group2[i]);
		}

		// Логика того, как делятся студенты
		for (int i = 0; i < 1000000; i++)
		{
			if (Group3[i].getFinal() < 5.0)
				Group3_lessThen5.push_back(Group3[i]);
			else
				Group3_moreThen5.push_back(Group3[i]);
		}

		int choice;
		cout << "Enter group num:";
		cin >> choice;
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

		cout << "If you want rearenge data by names press1, Surnames - 2, Fimalpoint -3 ";
		int selection;
		cin >> selection;
		switch (selection) {
		case 1: sort(Group.begin(), Group.end(), lessName); break;
		case 2: sort(Group.begin(), Group.end(), lessSurname); break;
		default: sort(Group.begin(), Group.end());
		}
		for (auto& B : Group) cout << B;
		break;
	}


	}


	system("pause");
}