#include "game.h"

#include <iostream>

int fileLetterIntoInt(std::string file)
{
	int intOfFile = 0;
	if(file.compare("a") == 0)
	{
		intOfFile = 0;
	}
	else if(file.compare("b") == 0)
	{
		intOfFile = 1;
	}
	else if(file.compare("c") == 0)
	{
		intOfFile = 2;
	}
	else if(file.compare("d") == 0)
	{
		intOfFile = 3;
	}
	else if(file.compare("e") == 0)
	{
		intOfFile = 4;
	}
	else if(file.compare("f") == 0)
	{
		intOfFile = 5;
	}
	else if(file.compare("g") == 0)
	{
		intOfFile = 6;
	}
	else if(file.compare("h") == 0)
	{
		intOfFile = 7;
	}
	return intOfFile;
}

Game::Game(std::vector< std::vector< std::vector <int>>> _board, int _turn)
{
    board = _board;
    turn = _turn;
}

Game::~Game(){}

std::vector< std::vector< std::vector <int>>> Game::getBoard()
{
	return board;
}

std::string Game::getPrintValue(std::vector<int> piece)
{
	std::string output = "";
	if(piece[1] == 1)
	{
		//white
		if(piece[0] == 1)
		{
			output = "K";
		}
		else if(piece[0] == 2)
		{
			output = "Q";
		}
		else if(piece[0] == 3)
		{
			output = "R";
		}
		else if(piece[0] == 4)
		{
			output = "B";
		}
		else if(piece[0] == 5)
		{
			output = "N";
		}
		else if(piece[0] == 6)
		{
			output = "P";
		}
	}
	else if(piece[1] == 2)
	{
		//black
		if(piece[0] == 1)
		{
			output = "k";
		}
		else if(piece[0] == 2)
		{
			output = "q";
		}
		else if(piece[0] == 3)
		{
			output = "r";
		}
		else if(piece[0] == 4)
		{
			output = "b";
		}
		else if(piece[0] == 5)
		{
			output = "n";
		}
		else if(piece[0] == 6)
		{
			output = "p";
		}
	}
	else if(piece[1] == 0)
	{
		//no piece on square
		output = " ";
	}
	return output;
}

void Game::printBoard()
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::cout << "  -----------------"<< std::endl;
	for(int i = 0; i < 8; ++i)
	{	
		std::cout << 8-i << " ";	
		for(int j = 0; j < 8; ++j)
		{
			std::cout << "|" << getPrintValue(myBoard[7-i][j]);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "  -----------------"<< std::endl;
	std::cout << "   A B C D E F G H "<< std::endl;
	return;
}

bool Game::check()
{
	bool check = false;
	// checks whether the player who is moving this turn is in check
	return check;
}

bool Game::legalMove(std::string move)
{
	bool legal = true;
	// check, blocking, moving range -- no legal move will mean check mate
	return legal;
}

void Game::makeMove(std::string move)
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::string fileStart = move.substr(0,1);
	std::string rowStart = move.substr(1,1);
	std::string fileFinish = move.substr(2,1);
	std::string rowFinish = move.substr(3,1);
	
	int xStart = fileLetterIntoInt(fileStart);
	int yStart = std::stoi(rowStart) - 1;
	int xFinish = fileLetterIntoInt(fileFinish);
	int yFinish = std::stoi(rowFinish) - 1;
	
	std::vector<int> pieceAtStart = myBoard[yStart][xStart];
	if(turn == 0 % 2)
	{
		//white's turn
		if(pieceAtStart[1] == 1 and legalMove(move))
		{
			std::vector<int> emptySquare = {0,0};
			myBoard[yStart][xStart] = emptySquare;
			myBoard[yFinish][xFinish] = pieceAtStart;
			board = myBoard;
			turn += 1;
		}
		else
		{
			std::cout << "Not a legal move!" << std::endl;
		}
	}
	else
	{
		//black's turn
		if(pieceAtStart[1] == 2 and legalMove(move))
		{
			std::vector<int> emptySquare = {0,0};
			myBoard[yStart][xStart] = emptySquare;
			myBoard[yFinish][xFinish] = pieceAtStart;
			board = myBoard;
			turn += 1;
		}
		else
		{
			std::cout << "Not a legal move!" << std::endl;
		}
	}
	
	return;
}
