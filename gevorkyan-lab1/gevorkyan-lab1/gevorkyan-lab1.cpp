
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct pipeline // pipe
{
	string pipename = "None";
	int pipelength = 0;
	int pipediameter = 0;
	bool piperepair = false;
};

struct compressorstation //cs
{
	string csname = "None";
	int csshop = 0;
	int csworkshop = 0;
	double csefficiency = 0;
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
		"6. Save \n" << 
		"7. Load" << endl;
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

void save_p(ofstream& fout, const pipeline& p)
{
	if (!(p.pipename == ""))
	{
		fout << p.pipename << endl;
		fout << p.pipelength << endl;
		fout << p.pipediameter << endl;
		fout << p.piperepair << endl;
	}
	else
	{
		fout << "There is none pipe" << endl;
	}
}

void save_c(ofstream& fout, const compressorstation& c)
{
	if (!(c.csname == ""))
	{
		fout << c.csname << endl;
		fout << c.csshop << endl;
		fout << c.csworkshop << endl;
		fout << c.csefficiency << endl;
	}
	else
	{
		fout << "There is none CS" << endl;
	}
}

bool load_p(ifstream& fin, pipeline& p)
{
	if (!(getline(fin, p.pipename)))
	{
		return false;
	}
	if (!(fin >> p.pipelength))
	{
		return false;
	}
	if (!(fin >> p.pipediameter))
	{
		return false;
	}
	if (!(fin >> p.piperepair))
	{
		return false;
	}
	return true;
}
	
bool load_c(ifstream& fin, compressorstation& c)
{
	if (!(getline(fin, c.csname)))
	{
		return false;
	}
	if (!(fin >> c.csshop))
	{
		return false;
	}
	if (!(fin >> c.csworkshop))
	{
		return false;
	}
	if (!(fin >> c.csefficiency))
	{
		return false;
	}
	return true;
}

int main()
{
	int choice;
	
	compressorstation c;
	pipeline p;

	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 0: // escape
			return 0;

		case 1: // add new pipeline

			add_pipe(p);
			
			break;

		case 2: // add new cs

			add_cs(c);
			
			break;

		case 3: // show all objects

			show_all_objects(c,p);

			break;

		case 4: // edit pipe
			
			edit_pipe(p);

			break;
		case 5: // edit cs

			edit_cs(c);

			break;
			
		case 6: // save 
		{
			ofstream fout("save_data.txt");
			if (fout.is_open())
			{
				save_p(fout, p);
				save_c(fout, c);
				fout.close();
				cout << "Saved" << endl;
			}
			else
			{
				cout << "Failed to save" << endl;
			}
			break;
		}
		case 7: // load
		{
			ifstream fin("save_data.txt");
			if (fin.is_open())
			{
				load_p(fin, p);
				load_c(fin, c);
				fin.close();
				cout << "Loaded" << endl;
			}
			else
			{
				cout << "Failed to load" << endl;
			}
			break;
		}
		
		default: // unexpected error
			break;
		}
	}
}