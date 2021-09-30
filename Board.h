#pragma once
#include <iostream> 
#include <utility> 

class Board {
public:
	static const int x = 18;
	static const int y = 18;
	char tiles[x][y];
	Board();
	 std::pair<int,int> getLocation(int player);
};