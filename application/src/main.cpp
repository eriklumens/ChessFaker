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
	
	std::cout << game.check() << std::endl;
	std::vector< std::vector <int>> pawns = game.pawnsThatAttackSquare(4, 0, 2);
	for(unsigned int i = 0; i < pawns.size(); ++i)
	{
		std::vector <int> myPawn = pawns[i];
		std::cout << "Pawn info:" << std::endl;
		std::cout << myPawn[0] << myPawn[1] << myPawn[2] << myPawn[3] << std::endl;
	}
	
	std::string moveString;
	while(game.isFinished() == false)
	{
		game.printBoard();
		std::cout << "Move: ";
		std::cin >> moveString;
		game.makeMove(moveString);
	}
}
