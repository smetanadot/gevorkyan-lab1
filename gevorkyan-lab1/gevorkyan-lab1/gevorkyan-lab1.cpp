// gevorkyan-lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int pipelines(std::string name, std::string length, std::string diameter, std::string repair)
{
	
	return 0;
}

int main()
{
	std::cout << "Welcome back!\n " <<
		"0. Escape\n" <<
		"1. Add new pipeline\n" <<
		"2. Add new cs\n" <<
		"3. Show all objects\n" <<
		"4. Edit pipeline\n" <<
		"5. Edit cs\n" <<
		"6. Save\n" <<
		"7. Load\n" << std::endl;

	int choice;
	
	// pipe characteristics
	std::string pipename;
    std::string pipelength;
	std::string pipediameter;
	std::string piperepair;

	std::string slovo;
	std::cin >> choice;
	switch (choice)
	{
	case 0: // escape
		break;
	case 1: // add new pipeline
		std::cout << "Choose a name for the pipeline";
		std::cin >>
		break;
	case 2: // add new cs
		break;
	case 3: // show all objects
		
		break;
	case 4: // edit pipe
		break;
	case 5: // edit cs
		break;
	case 6: // save
		break;
	case 7: // load
		break;
	default: // unexpected error
		break;
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
