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
	
	std::vector<std::vector<std::vector<std::vector<int> > > > myHistory;
	myHistory.push_back(myBoard);
	std::vector<std::string> myMoves;
	
	Game game(myBoard, 0, myHistory, myMoves);
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
		std::vector< std::string> myLegalMoves = game.legalMoveList(game.getBoard(), attSide);
		for(unsigned int i = 0; i < myLegalMoves.size(); ++i)
		{
			std::cout << myLegalMoves[i] << ", ";		
		}
		std::cout << "Move: ";
		std::cin >> moveString;
		game.makeMove(moveString);
	}
	game.printBoard();
}
