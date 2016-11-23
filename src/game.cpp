#include "game.h"

#include <iostream>

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
	std::cout << "----------------"<< std::endl;
	for(int i = 0; i < 8; ++i)
	{		
		for(int j = 0; j < 8; ++j)
		{
			std::cout << "|" << getPrintValue(myBoard[i][j]);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "----------------"<< std::endl;
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
	bool legal = false;
	// check, blocking, moving range -- no legal move will mean check mate
	return legal;
}

void Game::makeMove(std::string move)
{
	if(turn == 0 % 2)
	{
		//white's turn
		
	}
	else
	{
		//black's turn
	}
	turn += 1;
	return;
}
