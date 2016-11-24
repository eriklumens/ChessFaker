#include "game.h"
#include <iostream>
int main()
{
	std::vector<std::vector<std::vector<int> > > myBoard = {{{3,1},{5,1},{4,1},{2,1},{1,1},{4,1},{5,1},{3,1}},
	{{6,1},{6,1},{6,1},{6,1},{6,1},{6,1},{6,1},{6,1}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{6,2},{6,2},{6,2},{6,2},{6,2},{6,2},{6,2},{6,2}},
	{{3,2},{5,2},{4,2},{2,2},{1,2},{4,2},{5,2},{3,2}}};
	
	Game game(myBoard, 0);
	game.printBoard();
	game.makeMove("e2e4");
	game.printBoard();
	game.makeMove("e7e5");
	game.printBoard();
	std::vector< std::vector <int>> row = game.piecesHorseJumpAway(3,2);
	for(unsigned int i = 0; i < row.size(); ++i)
	{
		std::cout << row[i][0] << std::endl;
	}
}
