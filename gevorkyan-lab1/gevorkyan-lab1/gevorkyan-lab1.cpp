#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <format>
#include "pipeline.h"
#include "compressorstation.h"
#include "utils.h"

using namespace std;
using namespace chrono;

int main()
{
	int choice;
	string txt;
	unordered_map <int, pipeline> pipelines;
	unordered_map <int, compressorstation> css;

	redirect_output_wrapper cerr_out(cerr);
	string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	while (true)
	{
		menu();
		switch (GetCorrectNumber(0, 9))
		{
		case 0: // escape
		{
			return 0;
		}
		case 1: // add new pipeline
		{
			pipeline p;
			p.add_pipe();
			pipelines.emplace(p.get_id(), p);
			break;
		}
		case 2: // add new cs
		{
			compressorstation c;
			c.add_cs();
			css.emplace(c.get_id(), c);
			break;
		}
		case 3: // show all objects
		{
			for (const auto& [id, p] : pipelines)
			{
				pipelines[id].show_p(id);
			}

			for (const auto& [id, c] : css)
			{
				css[id].show_c(id);
			}

			break;
		}
		case 4: // edit pipe
		{
			ID_verification(pipelines, 0);
			break;
		}
		case 5: // edit cs
		{
			ID_verification(css, 0);
			break;
		}
		case 6: // save 
		{
			cout << "Enter file name: ";
			cin >> txt;

			ofstream fout(txt + ".txt");
			if (fout.is_open())
			{
				//p.save_p(fout);
				//c.save_c(fout);
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

			ifstream fin(txt + ".txt");
			if (fin.is_open())
			{
				//p.load_p(fin);
				//c.load_c(fin);
				fin.close();
				cout << "Loaded" << endl;
			}
			else
			{
				cout << "Failed to load" << endl;
			}
			break;
		}
		case 8: // delete pipeline
		{
			cout
				<< "Delete: \n"
				<< "1. Pipeline \n"
				<< "2. CS" << endl;
			choice = verification(1, 2);
			switch (choice)
			{
			case 1:
			{
				ID_verification(pipelines, 1);
				break;
			}
			case 2:
			{
				ID_verification(css, 1);
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case 9:
		{
			sort_menu();
			choice = verification(0, 4);
			switch (choice)
			{
			case 0:
			{
				break;
			}

			case 1:
			{
				cout << "Enter a name which you want to find" << endl;
				getline(cin, txt);
				pipeline p;

				for (const auto& [id, p] : pipelines)
				{
					if (pipelines[id].search_pipename(id, txt) == false) {
						choice += 1;
					}
				}
				if ((choice - 2) == (p.get_id() - 1)) {
					cout << "Pipe with that name doesnt exist" << endl;
				}

				break;
			}

			case 2:
			{
				cout << "Enter the attribute of pipe" << endl;
				bool inrep;
				cin >> inrep;
				pipeline p;

				for (const auto& [id, p] : pipelines)
				{
					pipelines[id].search_piperepair(id, inrep);
				}

				break;
			}

			case 3:
			{
				break;
			}

			default:
			{
				break;
			}
			}

		default: // unexpected error
		{
			break;
		}
		}
		}
	}
}