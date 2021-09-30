// Quoridor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include<time.h>
using namespace std;
int main()
{
	string a;
	int wybor;
	bool pc = false;
	cout << "Czy chcesz grac z komputerem?" << std::endl;
	do {
		cin >> a;
	} while (a.compare("tak")!=0 && a.compare("nie")!=0);
	if (a.compare("tak")==0) {
		pc = true;

	}
	srand(time(NULL));
	char x, y;
	Engine *engine = new Engine;
	string nazwaPliku;
	engine->render();
	do {


		std::cout << "Aktualny gracz: " << engine->currentPlayer << std::endl;
		if (engine->currentPlayer == 2 && pc)
		{
			while (engine->currentPlayer == 2)
			{
				x = rand() % 9 + 1;
				y = rand() % 9 + 1;
				engine->updateState(engine->currentPlayer, x, y);
			}
		}
		else
			cout << "1- ruch, 2-postawienie sciany" << endl;
		cin >> wybor;
		if (wybor == 2)
		{
			cout << "xd";
			cout << "podaj x: " << endl;
			cin >> x;
			cout << "podaj y: " << endl;
			cin >> y;

			engine->placeWall(engine->currentPlayer, x, y);

		}
		else if (wybor == 1) {

				do {

					std::cout << "Podaj x lub wpisz 99 aby zapisac lub 55 aby wczytac:";
					std::cin >> x;
					if (cin.good())
					{
						if (x == 99)
						{
							cout << "Podaj nazwe pliku:" << endl;
							cin >> nazwaPliku;

							engine->saveToFile(nazwaPliku);
						}
						if (x == 55)
						{
							cout << "Podaj nazwe pliku:" << endl;
							cin >> nazwaPliku;
							engine = new Engine(nazwaPliku);
							system("cls");
							engine->render();
							std::cout << "Aktualny gracz: " << engine->currentPlayer << std::endl;
						}
					}
					else
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}

				} while (x - 65 < 1 || x - 65 > engine->getBoardSize().first);
				do {
					if (cin.good())
					{
						std::cout << "Podaj y:";
						std::cin >> y;
					}
					else
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
				} while (y - 65 < 1 || y - 65 > engine->getBoardSize().second);

				engine->updateState(engine->currentPlayer, x, y);
			}

		
	} while (!engine->winner);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
