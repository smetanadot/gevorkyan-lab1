
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
	double csefficiency = 0.0;
};

int verification(int minvalue, int maxvalue) // verification of int data
{
	int value;
	while (true)
	{
		if ((cin >> value).good() && value >= minvalue && value <= maxvalue)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			return value;
		}
		else
		{
			cout << "Incorrect data. Please, try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

bool verificationbool() // verification of bool data
{
	bool value;
	while (true)
	{
		if ((cin >> value).good())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			return value;
		}
		else
		{
			cout << "Incorrect data. Please, try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

void add_pipe(pipeline& p) // add pipeline
{
	cout << "Choose a name for the pipeline\n";
	cin.ignore(10000,'\n');
	getline(cin, p.pipename);

	cout << "Choose pipe length\n";
	p.pipelength = verification(0, 2000);

	cout << "Choose pipe diameter\n";
	p.pipediameter = verification(0, 1000);

	cout << "Under repair?\n0. No\n1. Yes\n";
	p.piperepair = verificationbool();
}

void edit_pipe(pipeline& p) // edit pipeline
{
	if (p.pipename != "")
	{
		cout << "Under repair?\n0. No\n1. Yes\n";
		p.piperepair = verificationbool();
	}
	else
	{
		cout << "Create pipeline first" << endl;
	}
}

void add_cs(compressorstation& c) // add compressors station
{
	cout << "Choose a name for the cs\n";
	cin.ignore(10000, '\n');
	getline(cin, c.csname);

	cout << "Enter the number of workshops\n";
	c.csshop = verification(0, 1000);

	cout << "Enter the number of working workshops\n";
	c.csworkshop = verification(0, c.csshop);//!!!

	c.csefficiency = double(c.csworkshop) / c.csshop;
}
void edit_cs(compressorstation& c) // edit compressor station
{
	if (c.csname != "")
	{
		cout << "Enter the number of working workshops\n";
		c.csworkshop = verification(0, c.csshop);
	}
	else
	{
		cout << "Create cs first" << endl;
	}
	c.csefficiency = double(c.csworkshop) / c.csshop;
}

void menu() // menu
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

void show_p(const pipeline& p)
{
	if (p.pipename != "") // show pipeline
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
}

void show_c(const compressorstation& c)
{
	if (c.csname != "") // show compressors station
	{
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

void save_p(ofstream& fout, const pipeline& p) // save pipeline
{
	string Marker = "PIPELINE";
	if (p.pipename == "None") fout << Marker << endl;
	else
	{
		fout << p.pipename << endl;
		fout << p.pipelength << endl;
		fout << p.pipediameter << endl;
		fout << p.piperepair << endl;
	}
}

void save_c(ofstream& fout, const compressorstation& c) // save compressors station
{
	string Marker = "CS";
	if (c.csname == "None") fout << Marker << endl;
	else
	{
		fout << c.csname << endl;
		fout << c.csshop << endl;
		fout << c.csworkshop << endl;
		fout << c.csefficiency << endl;
	}
}

pipeline load_p(ifstream& fin, pipeline& p) // load pipeline
{
	string Marker;
	getline(fin >> ws, Marker);
	if (Marker == "PIPELINE")
	{
		return p = { "None", 0, 0, 0 };
	}
	else 
	{
		p.pipename = Marker;
		fin >> p.pipelength;
		fin >> p.pipediameter;
		fin >> p.piperepair;
		return p;
	}
}

compressorstation load_c(ifstream& fin, compressorstation& c) // load compressor station
{
	string Marker;
	getline(fin >> ws, Marker);
	if (Marker == "CS")
	{
		return c = { "None", 0, 0, 0 };
	}
	else
	{
		c.csname = Marker;
		fin >> c.csshop;
		fin >> c.csworkshop;
		fin >> c.csefficiency;
		return c;
	}
}

int main()
{
	int choice;
	
	compressorstation c;
	pipeline p;

	while (true)
	{
		menu();
		choice = verification(0,7);
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
			
			show_p(p);
			show_c(c);

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
				p = load_p(fin, p);
				c = load_c(fin, c);
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