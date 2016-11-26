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

std::vector< std::vector <int>> Game::piecesOnFile(int file)
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::vector< std::vector <int>> myPiecesOnFile;
	for(int i = 0; i < 8; ++i)
	{
		std::vector<int> myPiece = myBoard[i][file];
		if(myPiece[1] != 0)
		{
			myPiecesOnFile.push_back(myPiece);
		}
	}
	return myPiecesOnFile;
}

std::vector< std::vector <int>> Game::piecesOnRow(int row)
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::vector< std::vector <int>> myPiecesOnRow;
	for(int i = 0; i < 8; ++i)
	{
		std::vector<int> myPiece = myBoard[row][i];
		if(myPiece[1] != 0)
		{
			myPiecesOnRow.push_back(myPiece);
		}
	}
	return myPiecesOnRow;
}

std::vector< std::vector <int>> Game::piecesHorseJumpAway(int file, int row)
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::vector< std::vector <int>> myPiecesHorseJumpAway;
	std::vector<int> addValues = {1,2,-1,-2};
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if((j%2) != (i%2))
			{
				int myX = file + addValues[i];
				int myY = row + addValues[j];
				if(myX > -1 and myY > -1 and myX < 8 and myY < 8)
				{
					//Position lies inside the board
					std::vector<int> myPiece = myBoard[myY][myX];
					if(myPiece[1] != 0)
					{
						myPiecesHorseJumpAway.push_back(myPiece);
					}
				}
			}
		}
	}
	return myPiecesHorseJumpAway;
}

std::vector< std::vector< std::vector<int>>> Game::piecesOnDiagonals(int file, int row)
{
	std::vector< std::vector< std::vector<int>>> myPiecesOnDiagonals;
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	
	//First diagonal direction is A1 to H8, second diagonal direction is A8 to H1
	std::vector< std::vector<int>> myFirstDiagonal;
	std::vector< std::vector<int>> mySecondDiagonal;
	
	bool onBoard = true;
	int myFile = file;
	int myRow = row;
	int mySecFile = file;
	int mySecRow = row;

	//1st diagonal
	while(onBoard)
	{
		myFile = myFile - 1;
		myRow = myRow -1;
		if(myFile < 0 or myRow < 0)
		{
			onBoard = false;
		} 
	}
	myFile = myFile + 1;
	myRow = myRow + 1;

	//2nd diagonal
	onBoard = true;
	while(onBoard)
	{
		mySecFile = mySecFile - 1;
		mySecRow = mySecRow + 1;
		if(mySecFile < 0 or mySecRow > 7)
		{
			onBoard = false;
		} 
	}	
	mySecFile = mySecFile + 1;
	mySecRow = mySecRow - 1;

	if(myFile <= myRow)
	{
		for(int i = 0; i < 8- myRow; ++i)
		{
			int myX = i;
			int myY = myRow + i;
			std::vector<int> myPiece = myBoard[myY][myX];
			if(myPiece[1] != 0)
			{
				myFirstDiagonal.push_back(myPiece);
			}
		}
	}
	else
	{
		for(int i = 0; i < 8- myFile; ++i)
		{
			int myX = myFile + i;
			int myY = i;
			std::vector<int> myPiece = myBoard[myY][myX];
			if(myPiece[1] != 0)
			{
				myFirstDiagonal.push_back(myPiece);
			}
		}
	}	
	if(mySecFile == 0)
	{
		for(int i = 0; i < mySecRow + 1; ++i)
		{
			int myX = i;
			int myY = mySecRow - i;
			std::vector<int> myPiece = myBoard[myY][myX];
			if(myPiece[1] != 0)
			{
				mySecondDiagonal.push_back(myPiece);
			}
		}
	}
	else
	{
		for(int i = 0; i < 8- mySecFile; ++i)
		{
			std::cout << "i = " <<i <<  std::endl;
			int myX = mySecFile + i;
			int myY = 7 - i;
			std::vector<int> myPiece = myBoard[myY][myX];
			if(myPiece[1] != 0)
			{
				mySecondDiagonal.push_back(myPiece);
			}
		}	
	}
	myPiecesOnDiagonals.push_back(myFirstDiagonal);
	myPiecesOnDiagonals.push_back(mySecondDiagonal);
	return myPiecesOnDiagonals;
}

int Game::howManyTimesIsSquareAttacked(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	//First horse, is square attacked by horse of opposing side?
	std::vector< std::vector <int>> myPiecesHorseJumpAway = piecesHorseJumpAway(file,row);
	for(unsigned int i = 0; i < myPiecesHorseJumpAway.size(); ++i)
	{
		std::vector<int> myPiece = myPiecesHorseJumpAway[i];
		if(myPiece[0] == 5 and myPiece[1] == attSide)
		{
			nrOfAttacks = nrOfAttacks + 1;
		} 
	}
	//Next pawn, is square attacked by pawn of opposing side?
	return nrOfAttacks;
}

bool Game::check()
{
	bool check = false;
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	if(turn % 2 == 0)
	{
		//White's turn, is white in check?
		//First, where is the king?
		bool kingIsNotFound = true;
		int kingX = 0;
		int kingY = 0;
		for(int i = 0; i < 8 and kingIsNotFound; ++i)
		{
			for(int j = 0; j < 8 and kingIsNotFound; ++j)
			{
				std::vector <int> myPos = myBoard[j][i];
				if(myPos[0] == 1 and myPos[1] == 1)
				{
					kingY = j;
					kingX = i;
					kingIsNotFound = false;
				} 
			}
		}
		if(howManyTimesIsSquareAttacked(kingX,kingY,2) != 0)
		{
			check = true;
		}
	}
	else
	{
		//Black's turn, is black in check?
		//First, where is the king?
		bool kingIsNotFound = true;
		int kingX = 0;
		int kingY = 0;
		for(int i = 0; i < 8 and kingIsNotFound; ++i)
		{
			for(int j = 0; j < 8 and kingIsNotFound; ++j)
			{
				std::vector <int> myPos = myBoard[j][i];
				if(myPos[0] == 1 and myPos[1] == 2)
				{
					kingY = j;
					kingX = i;
					kingIsNotFound = false;
				} 
			}
		}
		if(howManyTimesIsSquareAttacked(kingX,kingY,2) != 0)
		{
			check = true;
		}
	}
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
