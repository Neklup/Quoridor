#include "Board.h"

Board::Board()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{

			tiles[j][i] = '0';
			if (j == 0) tiles[j][i] = i + 65;
			else if (j % 2 == 0) tiles[j][i] = ' ';
			if (i == 0) tiles[j][i] = j + 65;
			else if (i % 2 == 0 && j!=0) tiles[j][i] = ' ';
		}
	}
	tiles[x/2][y-1] = '1';
	tiles[x/2][1] = '2';
	/*tiles[5][5] = 1;
	tiles[5][4] = 2;*/

}

std::pair <int, int> Board::getLocation(int player)
{	
	
	for (int i = 1; i < x; i++) {
		for (int j = 1; j < y; j++) {
			if (tiles[j][i] == player+48) return std::make_pair(j, i);
		}
	}
	return std::make_pair(-1,-1);
}
