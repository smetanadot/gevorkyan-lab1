#include "compressorstation.h"
#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;

int compressorstation::MaxID = 1;

int compressorstation::get_id()
{
	return id;
}

int compressorstation::get_MaxID()
{
	return MaxID;
}

void compressorstation::add_cs() // add compressors station
{
	cin.ignore(10000, '\n');
	cout << "Choose a name for the cs\n";
	getline(cin, csname);

	cout << "Enter the number of workshops\n";
	csshop = verification(0, 1000);

	cout << "Enter the number of working workshops\n";
	csworkshop = verification(0, csshop);

	csefficiency = double(csworkshop) / csshop;

	id = MaxID;
	MaxID++;
}

void compressorstation::edit() // edit compressor station
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

void compressorstation::show_c(const int& id)
{
	if (csname != "") // show compressors station
	{
		cout << "------CS------" <<
			"\nID: " << id <<
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

void compressorstation::save_c(ofstream& fout) // save compressors station
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

void compressorstation::load_c(ifstream& fin) // load compressor station
{
	string Marker;
	getline(fin >> ws, Marker);
	if (Marker != "CS")
	{
		csname = Marker;
		fin >> csshop;
		fin >> csworkshop;
		fin >> csefficiency;
	}
}