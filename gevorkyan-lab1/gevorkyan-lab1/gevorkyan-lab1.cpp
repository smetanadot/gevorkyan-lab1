// gevorkyan-lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
	int csefficiency;
	bool csstatus;
};

void addpipe(pipeline& p)
{
	cout << "Choose a name for the pipeline\n";
	cin >> p.pipename;

	while (true)
	{
		cout << "Choose pipe length\n";
		cin >> p.pipelength;		
		if (cin.good() && (2000 > p.pipelength > 0))
		{
			break;
		}
		else
		{
			cout << "Incorrect data\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	

	while (true)
	{
		cout << "Choose pipe diameter\n";
		cin >> p.pipediameter;
		if (cin.good() && 1000 > p.pipediameter > 0)
		{
			break;
		}
		else
		{
			cout << "Incorrect data";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	while (true)
	{
		cout << "Under repair?\n0. No\n1. Yes\n";
		cin >> p.piperepair;
		if (cin.good())
		{
			break;
		}
		else
		{
			cout << "Incorrect data";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

void addcs(compressorstation& c)
{
	cout << "Choose a name for the cs\n";
	cin >> c.csname;

	

	while (true)
	{
		cout << "Enter the number of workshops\n";
		cin >> c.csshop;
		if (cin.good() && 100 > c.csshop > 0)
		{
			break;
		}
		else
		{
			cout << "Incorrect data";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	

	while (true)
	{
		cout << "Enter the number of working workshops\n";
		cin >> c.csworkshop;
		if (cin.good() && c.csshop > c.csworkshop > 0)
		{
			break;
		}
		else
		{
			cout << "Incorrect data";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	c.csefficiency = float(c.csworkshop / c.csshop);


	while (true)
	{
		cout << "Working?\n0. No\n1. Yes\n";
		if (cin.good())
		{
			break;
		}
		else
		{
			cout << "Incorrect data";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	cin >> c.csstatus;
	
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

void showallobjects(const compressorstation& c, const pipeline& p)
{

	cout << "------PIPELINE------" <<
		"\nName: " << p.pipename <<
		"\nLength: " << p.pipelength <<
		"\nDiameter: " << p.pipediameter <<
		"\nUnder repair? " << p.piperepair <<
		"\n--------------------" << endl;

	cout << "------CS------" <<
		"\nName: " << c.csname <<
		"\nNumber of workshops: " << c.csshop <<
		"\nNumber of working shops: " << c.csworkshop <<
		"\nEfficiency: " << c.csefficiency <<
		"\nWorking? " << c.csstatus <<
		"\n--------------------" << endl;
}



int main()
{
	int choice;
	
	compressorstation c;
	pipeline p;

	std::ofstream save("save.txt");

	
	while (true)
	{

		menu();
		cin >> choice;
		switch (choice)
		{
		case 0: // escape
			break;

		case 1: // add new pipeline

			addpipe(p);
			
			continue;

		case 2: // add new cs

			addcs(c);
			
			continue;

		case 3: // show all objects

			showallobjects(c,p);

			continue;

		case 4: // edit pipe
			while (true)
			{
				cout << "Under repair?\n0. No\n1. Yes\n";
				cin >> p.piperepair;
				if (cin.good())
				{
					break;
				}
				else
				{
					cout << "Incorrect data";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			continue;
		case 5: // edit cs
			while (true)
			{
				cout << "Working?\n0. No\n1. Yes\n";
				if (cin.good())
				{
					break;
				}
				else
				{
					cout << "Incorrect data";
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			break;
		case 6: // save
			std::cout << "File has been saved" << std::endl;
			continue;
		case 7: // load
			break;
		default: // unexpected error
			break;
		}
	}
}