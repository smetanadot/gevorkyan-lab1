// эффективность доолжна вводиться
// функции от копипаста
// удалить воркинг
// редактировать колво рабочих фабрик
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct pipeline // pipe
{
	string pipename;
	int pipelength;
	int pipediameter;
	bool piperepair;
};

struct compressorstation //cs
{
	string csname;
	int csshop;
	int csworkshop;
	double csefficiency;
};

bool verification()
{
	while (true)
	{
		if (cin.good())
		{
			return true;
		}
		else
		{
			cout << "Incorrect data. Please, try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			return false;
		}
	}
}
void add_pipe(pipeline& p)
{
	cout << "Choose a name for the pipeline\n";
	cin.ignore(10000,'\n');
	getline(cin, p.pipename);
	
	while (true)
	{
		cout << "Choose pipe length\n";
		cin >> p.pipelength;
		if (verification() && 2000 > p.pipelength > 0)
		{
			break;
		}
	}

	while (true)
	{
		cout << "Choose pipe diameter\n";
		cin >> p.pipediameter;
		if (verification() && 1000 > p.pipediameter > 0)
		{
			break;
		}
	}

	while (true)
	{
		cout << "Under repair?\n0. No\n1. Yes\n";
		cin >> p.piperepair;
		if (verification())
		{
			break;
		}
	}
}

void edit_pipe(pipeline& p)
{
	if (p.pipelength > 0)
	{
		while (true)
		{
			cout << "Under repair?\n0. No\n1. Yes\n";
			cin >> p.piperepair;
			if (verification())
			{
				break;
			}
		}
	}
	else
	{
		cout << "Create pipeline first" << endl;
	}
}

void add_cs(compressorstation& c)
{
	cout << "Choose a name for the cs\n";
	cin.ignore(10000, '\n');
	getline(cin, c.csname);

	while (true)
	{
		cout << "Enter the number of workshops\n";
		cin >> c.csshop;
		if (verification() && 1000 > c.csshop > 0)
		{
			break;
		}
	}

	while (true)
	{
		cout << "Enter the number of working workshops\n";
		cin >> c.csworkshop;
		if (verification() && c.csshop >= c.csworkshop > 0)
		{
			break;
		}
	}

	c.csefficiency = double(c.csworkshop) / c.csshop;

	
}
void edit_cs(compressorstation& c)
{
	if (c.csshop > 0)
	{
		while (true)
		{
			cout << "Enter the number of working workshops\n";
			cin >> c.csworkshop;
			if (verification() && c.csshop >= c.csworkshop > 0)
			{
				break;
			}
		}
	}
	else
	{
		cout << "Create cs first" << endl;
	}
	c.csefficiency = double(c.csworkshop) / c.csshop;
}

void menu()
{
	cout <<

		"0. Escape\n" <<
		"1. Add new pipeline\n" <<
		"2. Add new cs\n" <<
		"3. Show all objects\n" <<
		"4. Edit pipeline\n" <<
		"5. Edit cs\n" <<
		"6. Save\n" <<
		"7. Load\n" << endl;
};

void show_all_objects(const compressorstation& c, const pipeline& p)
{
	if (p.pipename != "")
	{
		cout << "------PIPELINE------" <<
			"\nName: " << p.pipename <<
			"\nLength: " << p.pipelength <<
			"\nDiameter: " << p.pipediameter <<
			"\nUnder repair? " << p.piperepair <<
			"\n--------------------" << endl;
	}
	else 
	{
		cout << "Create pipeline first" << endl;
	}
	if (c.csname != "") {
		cout << "------CS------" <<
			"\nName: " << c.csname <<
			"\nNumber of workshops: " << c.csshop <<
			"\nNumber of working shops: " << c.csworkshop <<
			"\nEfficiency: " << c.csefficiency <<
			"\n--------------------" << endl;
	}
	else
	{
		cout << "Create cs first" << endl;
	}
}



int main()
{
	int choice;
	
	compressorstation c;
	pipeline p;

	ofstream save("save.txt");


	while (true)
	{

		menu();
		cin >> choice;
		switch (choice)
		{
		case 0: // escape
			break;

		case 1: // add new pipeline

			add_pipe(p);
			
			continue;

		case 2: // add new cs

			add_cs(c);
			
			continue;

		case 3: // show all objects

			show_all_objects(c,p);

			continue;

		case 4: // edit pipe
			
			edit_pipe(p);

			continue;
		case 5: // edit cs

			edit_cs(c);

			continue;
			
		case 6: // save
			continue;
		case 7: // load
			break;
		default: // unexpected error
			break;
		}
	}
}