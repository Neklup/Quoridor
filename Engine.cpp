#include "Engine.h"
#include <windows.h>  
Board Engine::board;

Engine::Engine() :Game() 
{
	
	currentPlayer = 1;
}

void Engine::render()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	for (int i = 0; i < board.x; i++) {
		for (int j = 0; j < board.y; j++) {
			if (j == 0 || i == 0)  SetConsoleTextAttribute(hConsole, 11);
			else if (board.tiles[j][i] == '#') SetConsoleTextAttribute(hConsole, 42);
			else if (board.tiles[j][i] != '0') {
				board.tiles[j][i] == '1' ? SetConsoleTextAttribute(hConsole, 2) : SetConsoleTextAttribute(hConsole, 12);
			}
			
			cout << board.tiles[j][i];

			SetConsoleTextAttribute(hConsole, 15);
		}
		cout << endl;
	}
}

void Engine::updateState(int player, int x, int y)
{
	x = x - 65;
	y = y - 65;
	pair<int, int> location = board.getLocation(player);
	pair<int, int> location2= board.getLocation(player == 1 ? 2 : 1);
	bool validMove = abs(location.first - x) == 2 && abs(location.second - y) == 0 || abs(location.first - x) == 0 && abs(location.second - y) == 2;
	if (abs(location.second - location2.second) == 2 && location.first==location2.first)
	{
		validMove =
			((abs(location.first - x) == 0 && abs(location.second - y) == 4 && abs(location2.second-y)==2)|| abs(location.first - x) == 2 && abs(location.second - y) == 0)||validMove;
	

	}
	else if (abs(location.first - location2.first) == 2 && location.second == location2.second)
	{
		validMove =
			(
				(abs(location.second - y) == 0 && abs(location.first - x) == 4 && abs(location2.first - x) == 2)
				||
				abs(location.second - y) == 2 && abs(location.first - x) == 0
			) || validMove;


	}
	if (location2.first == x && location2.second == y)
	{
		cout << "Niepoprawny ruch" << endl;
	}
	else if (validMove) {
		for (int i = 1; i < board.x; i++) {
			for (int j = 1; j < board.y; j++) {
				if (board.tiles[j][i] == player+48) {
					board.tiles[j][i] = '0';
				}
			}
		}

		board.tiles[x][y] = player+48;
		if (isWon()) {
			system("cls");
			cout << "Wygral gracz numer: " << currentPlayer << endl;
			winner = true;
			system("PAUSE");			
		}

		else changePlayer();		
	}
	else 
	{
		cout << "Niepoprawny ruch" << endl;
	}
}

void Engine::changePlayer()
{
	currentPlayer == 1 ? currentPlayer = 2 : currentPlayer = 1;
	render();
}

void Engine::placeWall(int player, int x, int y)
{
	x = x - 65;
	y = y - 65;
	if ((x % 2 == 1 && y % 2 == 0)) //|| (x % 2 == 1 && y % 2 == 0))
	{
		if (board.tiles[x][y] == '#' || board.tiles[x + 1][y] == '#' || board.tiles[x + 2][y] == '#')
			cout << "niepoprawny ruch" << endl;
		else
		{
			board.tiles[x][y] = '#';
			board.tiles[x + 1][y] = '#';
			board.tiles[x + 2][y] = '#';
			changePlayer();
		}
	}
	else if (x%2==0&& y%2==1)
	{
		if(board.tiles[x][y] == '#' || board.tiles[x][y+1] == '#' || board.tiles[x][y+2] == '#')
			cout << "niepoprawny ruch" << endl;
		else
		{
			board.tiles[x][y] = '#';
				board.tiles[x][y + 1] = '#';
				board.tiles[x][y + 2] = '#';
				changePlayer();
		}
	}
	
}

pair<int, int> Engine::getBoardSize()
{
	return make_pair(board.x,board.y);
}

bool Engine::isWon()
{
	for (int i = 1; i < board.x; i++)
	{
		if (board.tiles[i][1] == '1') return true;
	}
	for (int i = 1; i < board.x; i++)
	{
		if (board.tiles[i][17] == '2') return true;
	}
	return false;
}

void Engine::saveToFile(string fileName)
{
	
	ofstream file;
	file.open(fileName);
	file << currentPlayer << endl;
	for (int i = 0; i < board.x; i++)
	{
		for (int j = 0; j < board.y; j++)
		{
			file << board.tiles[j][i] << endl;
		}

	}
	file.close();
}

Engine::Engine(string fileName):Game()
{
	ifstream file;
	file.open(fileName);
	string line;
	getline(file, line);
	currentPlayer = stoi(line);
	int i = 0;
	int j = 0;
	while (getline(file, line) && j!=board.y)
	{
		board.tiles[i][j] = stoi(line);
		i++;
		if (i == board.x)
		{
			i = 0; j++;
		}
		
	}
	

}
