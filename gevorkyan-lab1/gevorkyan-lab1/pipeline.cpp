#include <iostream>
#include <string>
#include <fstream>
#include "pipeline.h"
#include "utils.h"


using namespace std;

int pipeline::MaxID = 1;

int pipeline::get_id()
{
	return id;
} 

int pipeline::get_MaxID()
{
	return MaxID;
}

void pipeline::add_pipe() // add pipeline
{
	cout << "Choose a name for the pipeline\n";
	cin.ignore(10000, '\n');
	getline(cin, pipename);
	
	cout << "Choose pipe length\n";
	pipelength = verification(0, 2000);

	cout << "Choose pipe diameter\n";
	pipediameter = verification(0, 1000);

	cout << "Under repair?\n0. No\n1. Yes\n";
	piperepair = verificationbool();
	
	id = MaxID;
	MaxID++;
}

void pipeline::edit() // edit pipeline
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

void pipeline::show_p(const int& id)
{
	cout << "------PIPELINE------" <<
		"\nID:" << id <<
		"\nName: " << pipename <<
		"\nLength: " << pipelength <<
		"\nDiameter: " << pipediameter <<
		"\nUnder repair? " << piperepair <<
		"\n--------------------" << endl;
}

void pipeline::save_p(ofstream & fout) // save pipeline
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

void pipeline::load_p(ifstream & fin) // load pipeline
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

bool pipeline::search_pipename(const int& id, const string& name)
{
	if (name == pipename) {
		show_p(id);
	}
	else {
		return false;
	}
}

bool pipeline::search_piperepair(const int& id, const bool& inrep)
{
	if (inrep == piperepair) {
		show_p(id);
	}
	else {
		return false;
	}
}