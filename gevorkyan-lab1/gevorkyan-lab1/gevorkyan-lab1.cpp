#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

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


void search_pipe()
{

}

class pipeline {
public:

	void add_pipe() // add pipeline
	{
		cout << "Choose a name for the pipeline\n";
		getline(cin, pipename);
		//cin.ignore(10000, '\n');

		cout << "Choose pipe length\n";
		pipelength = verification(0, 2000);

		cout << "Choose pipe diameter\n";
		pipediameter = verification(0, 1000);

		cout << "Under repair?\n0. No\n1. Yes\n";
		piperepair = verificationbool();

	}

	void edit_pipe() // edit pipeline
	{
		if (pipename != "")
		{
			cout << "Under repair?\n0. No\n1. Yes\n";
			piperepair = verificationbool();
		}
		else
		{
			cout << "Create pipeline first" << endl;
		}
	}

	void show_p(const int &id)
	{
		cout << "------PIPELINE------" <<
			"\nID:" << id <<
			"\nName: " << pipename <<
			"\nLength: " << pipelength <<
			"\nDiameter: " << pipediameter <<
			"\nUnder repair? " << piperepair <<
			"\n--------------------" << endl;
	}

	void save_p(ofstream& fout) // save pipeline
	{
		string Marker = "PIPELINE";
		if (pipename == "None") fout << Marker << endl;
		else
		{
			fout << pipename << endl;
			fout << pipelength << endl;
			fout << pipediameter << endl;
			fout << piperepair << endl;
		}
	}

	void load_p(ifstream& fin) // load pipeline
	{
		string Marker;
		getline(fin >> ws, Marker);
		if (Marker != "PIPELINE")
		{
			pipename = Marker;
			fin >> pipelength;
			fin >> pipediameter;
			fin >> piperepair;
		}
	}


private:
	string pipename = "None";
	int pipelength = 0;
	int pipediameter = 0;
	bool piperepair = false;
	
};

class compressorstation {
public:
	void add_cs() // add compressors station
	{
		cout << "Choose a name for the cs\n";
		//cin.ignore(10000, '\n');
		getline(cin, csname);

		cout << "Enter the number of workshops\n";
		csshop = verification(0, 1000);

		cout << "Enter the number of working workshops\n";
		csworkshop = verification(0, csshop);

		csefficiency = double(csworkshop) / csshop;
	}

	void edit_cs() // edit compressor station
	{
		if (csname != "")
		{
			cout << "Enter the number of working workshops\n";
			csworkshop = verification(0, csshop);
		}
		else
		{
			cout << "Create cs first" << endl;
		}
		csefficiency = double(csworkshop) / csshop;
	}

	void show_c()
	{
		if (csname != "") // show compressors station
		{
			cout << "------CS------" <<
				"\nName: " << csname <<
				"\nNumber of workshops: " << csshop <<
				"\nNumber of working shops: " << csworkshop <<
				"\nEfficiency: " << csefficiency <<
				"\n--------------------" << endl;
		}
		else
		{
			cout << "Create cs first" << endl;
		}
	}

	void save_c(ofstream& fout) // save compressors station
	{
		string Marker = "CS";
		if (csname == "None") fout << Marker << endl;
		else
		{
			fout << csname << endl;
			fout << csshop << endl;
			fout << csworkshop << endl;
			fout << csefficiency << endl;
		}
	}

	void load_c(ifstream& fin) // load compressor station
	{
		string Marker;
		getline(fin >> ws, Marker);
		if (Marker != "CS")
		{
			csname = Marker;
			fin >> csshop;
			fin >> csworkshop;
			fin >> csefficiency;		}
	}
	
private:
	string csname = "None";
	int csshop = 0;
	int csworkshop = 0;
	double csefficiency = 0.0;
};

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
		"7. Load \n" << 
		"8. Delete pipeline" << endl;
};

void sort_menu()
{
	cout <<
		"0. Escape\n" <<
		"1. Sort pipelines by name \n" <<
		"2. Sort pipelines by repair \n" <<
		"3. Sort CS by name \n" <<
		"4. Sort CS by workshops \n" << endl;
}

int main()
{
	int choice;
	int id;
	id = 1;
	string txt;
	compressorstation c;
	pipeline p;
	unordered_map <int, pipeline> pipelines;

	while (true)
	{
		menu();
		choice = verification(0,8);
		switch (choice)
		{
		case 0: // escape
			return 0;

		case 1: // add new pipeline

			pipelines[id].add_pipe();
			id++;
			break;

		case 2: // add new cs

			c.add_cs();
			
			break;

		case 3: // show all objects

			for (int i = 1; i < id; i++)
			{
				pipelines[i].show_p(i);
			}
			c.show_c();

			break;

		case 4: // edit pipe

			cout << "Input ID of pipeline: " << endl;
			choice = verification(1, id);
			pipelines[choice].edit_pipe();

			break;

		case 5: // edit cs

			c.edit_cs();

			break;
			
		case 6: // save 
		{
			cout << "Enter file name: ";
			cin >> txt;

			ofstream fout(txt+".txt");
			if (fout.is_open())
			{
				p.save_p(fout);
				c.save_c(fout);
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
			cout << "Enter file name: ";
			cin >> txt;

			ifstream fin(txt+".txt");
			if (fin.is_open())
			{
				p.load_p(fin);
				c.load_c(fin);
				fin.close();
				cout << "Loaded" << endl;
			}
			else
			{
				cout << "Failed to load" << endl;
			}
			break;
		}
		
		//case 8: // delete pipe
		//{
		//	cout << "Input pipe ID to delete: " << endl;
		//	choice = verification(1, id);
		//	pipelines.erase(choice);
		//	break;

		//}
		
		case 9:
		{
			sort_menu();
			choice = verification(0, 4);
			switch (choice) {
				case 0:
				{
					break;
				}
				case 1:
				{
					break;
				}
				case 2:
				{
					break;
				}
				case 3:
				{
					break;
				}
				case 4:
				{
					break;
				}
			}
		
		}

		default: // unexpected error
			break;
		}
	}
}