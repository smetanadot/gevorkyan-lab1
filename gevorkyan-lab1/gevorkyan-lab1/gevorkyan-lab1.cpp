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

int main()
{
	int choice;
	
	std::ofstream save("save.txt");
	
	struct pipeline p;
	struct compressorstation c;

	menu();
	
	while (true)
	{

		cin >> choice;
		switch (choice)
		{
		case 0: // escape
			break;

		case 1: // add new pipeline

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
				}
			}

			cout << "Choose pipe diameter\n";
			cin >> p.pipediameter;

			while (true)
			{
				if (cin.good() && 100 > p.pipelength > 0)
				{
					break;
				}
				else
				{
					cout << "Incorrect data";
				}
			}

			cout << "Under repair?\n0. No\n1. Yes\n";
			cin >> p.piperepair;
			
			while (true)
			{
				if (cin.good())
				{
					break;
				}
				else
				{
					cout << "Incorrect data";
				}
			}

			std::cout << "------PIPELINE------" <<
				"\nName: " <<
				"\nLength: " <<
				"\nDiameter: " <<
				"\nUnder repair? " <<
				"\n--------------------" << std::endl;
			continue;

		case 2: // add new cs
			std::cout << "Choose a name for the cs\n";
			std::cin >> c.csname;
			std::cout << "Enter the number of workshops\n";
			std::cin >> c.csshop;
			std::cout << "Enter the number of working workshops\n";
			std::cin >> c.csworkshop;
			std::cout << "Enter efficiency\n";
			std::cin >> c.csefficiency;
			std::cout << "Working?\n0. No\n1. Yes\n";
			std::cin >> c.csstatus;
			std::cout << "------CS------" <<
				"\nName: " <<
				"\nNumber of workshops: " << 
				"\nNumber of working shops: " <<
				"\nEfficiency: " <<
				"\nWorking? " << 
				"\n--------------------" << std::endl;
			continue;

		case 3: // show all objects

			continue;

		case 4: // edit pipe
			std::cout << "Under repair?\n0. No\n1. Yes\n";
			continue;
		case 5: // edit cs
			std::cout << "Working?\n0. No\n1. Yes\n";
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
