#include "game.h"
#include "chessFakerEngine.cpp"
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
	
	std::vector<std::vector<std::vector<std::vector<int> > > > myHistory;
	myHistory.push_back(myBoard);
	std::vector<std::string> myMoves;
	
	Game game(myBoard, 0, myHistory, myMoves);
	std::cout << "Choose side (0 Analysis / 1 White / 2 Black): ";
	int side = 0;
	int depth = 1;
	std::cin >> side;
	if(side != 0)
	{
		std::cout << "Choose depth (1 - ...): ";
		std::cin >> depth; 
	}
	std::string moveString;
	while(game.isFinished(game.getBoard(), game.getTurn()) == false)
	{
		game.printBoard();
		int myTurn = game.getTurn();
		int attSide = 0;
		if(myTurn % 2 == 0)
		{
			attSide = 1;
		}
		else
		{
			attSide = 2;
		}
		
		if((side == 1 and attSide == 1) or (side == 2 and attSide == 2) or side == 0)
		{
			std::cout << "Move: ";
			std::cin >> moveString;
		}
		else
		{
			moveString = engineOutput(game, side, depth);
		}
		game.makeMove(moveString);
	}
	game.printBoard();
}
