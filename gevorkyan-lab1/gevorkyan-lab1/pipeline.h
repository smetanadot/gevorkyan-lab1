#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

class pipeline{
public:

	void add_pipe();

	void edit();

	void show_p(const int& id);

	void save_p(std::ofstream& fout);

	void load_p(std::ifstream& fin);
	
	int get_id();

	static int get_MaxID();

	bool search_pipename(const int& id, const std::string& name);

	bool search_piperepair(const int& id, const bool& inrep);


private:

	static int MaxID;
	int id;
	std::string pipename = "None";
	int pipelength = 0;
	int pipediameter = 0;
	bool piperepair = false;
};

