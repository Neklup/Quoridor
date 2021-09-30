#pragma once
#include "Board.h"
#include"Game.h"
#include<fstream>
#include<string>
using namespace std;
class Engine:public Game {
private:
	static Board board;
public:
	Engine();
	int currentPlayer;
	void render();
	void updateState(int player, int x, int y);
	void changePlayer();
	void placeWall(int player, int x, int y);
	pair<int, int> getBoardSize();
	bool isWon();
	void saveToFile(string fileName);
	Engine(string fileName);
	
};