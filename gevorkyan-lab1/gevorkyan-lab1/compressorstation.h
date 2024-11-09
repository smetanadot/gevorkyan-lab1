#pragma once
#include <iostream>
#include <fstream>
#include <string>

class compressorstation{
public:

	void add_cs();

	void edit();

	void show_c(const int& id);

	void save_c(std::ofstream& fout);

	void load_c(std::ifstream& fin);

	int get_id();

	static int get_MaxID();

private:

	static int MaxID;
	int id;
	std::string csname = "None";
	int csshop = 0;
	int csworkshop = 0;
	double csefficiency = 0.0;

};

