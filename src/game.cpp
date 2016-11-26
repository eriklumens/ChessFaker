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
			myPiece.push_back(file);
			myPiece.push_back(i);
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
			myPiece.push_back(i);
			myPiece.push_back(row);
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
						myPiece.push_back(myX);
						myPiece.push_back(myY);
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
				myPiece.push_back(myX);
				myPiece.push_back(myY);
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
				myPiece.push_back(myX);
				myPiece.push_back(myY);
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
				myPiece.push_back(myX);
				myPiece.push_back(myY);
				mySecondDiagonal.push_back(myPiece);
			}
		}
	}
	else
	{
		for(int i = 0; i < 8- mySecFile; ++i)
		{
			int myX = mySecFile + i;
			int myY = 7 - i;
			std::vector<int> myPiece = myBoard[myY][myX];
			if(myPiece[1] != 0)
			{
				myPiece.push_back(myX);
				myPiece.push_back(myY);
				mySecondDiagonal.push_back(myPiece);
			}
		}	
	}
	myPiecesOnDiagonals.push_back(myFirstDiagonal);
	myPiecesOnDiagonals.push_back(mySecondDiagonal);
	return myPiecesOnDiagonals;
}

std::vector< std::vector <int>> Game::pawnsThatAttackSquare(int file, int row, int attSide)
{
	std::vector< std::vector< std::vector <int>>> myBoard = getBoard();
	std::vector< std::vector <int>> myPawnsThatAttackSquare;
	if(attSide == 1)
	{
		//White is attacking
		int myY = row - 1;
		int myFirstX = file + 1;
		int mySecondX = file - 1;
		
		if(myFirstX < 8 and myY > -1)
		{
			std::vector <int> myPiece = myBoard[myY][myFirstX];
			if(myPiece[0] == 6 and myPiece[1] == 1)
			{
				myPiece.push_back(myFirstX);
				myPiece.push_back(myY);
				myPawnsThatAttackSquare.push_back(myPiece);
			}
		}
		if(mySecondX > -1 and myY > -1)
		{
			std::vector <int> myPiece = myBoard[myY][mySecondX];
			if(myPiece[0] == 6 and myPiece[1] == 1)
			{
				myPiece.push_back(mySecondX);
				myPiece.push_back(myY);
				myPawnsThatAttackSquare.push_back(myPiece);
			}
		}
	}
	else if(attSide == 2)
	{
		//Black is attacking
		int myY = row + 1;
		int myFirstX = file + 1;
		int mySecondX = file - 1;
		
		if(myFirstX < 8 and myY < 8)
		{
			std::vector <int> myPiece = myBoard[myY][myFirstX];
			if(myPiece[0] == 6 and myPiece[1] == 1)
			{
				myPiece.push_back(myFirstX);
				myPiece.push_back(myY);
				myPawnsThatAttackSquare.push_back(myPiece);
			}
		}
		if(mySecondX > -1 and myY < 8)
		{
			std::vector <int> myPiece = myBoard[myY][mySecondX];
			if(myPiece[0] == 6 and myPiece[1] == 1)
			{
				myPiece.push_back(mySecondX);
				myPiece.push_back(myY);
				myPawnsThatAttackSquare.push_back(myPiece);
			}
		}
	}
	return myPawnsThatAttackSquare;
}

int Game::howManyTimesIsSquareAttackedByHorse(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	std::vector< std::vector <int>> myPiecesHorseJumpAway = piecesHorseJumpAway(file,row);
	for(unsigned int i = 0; i < myPiecesHorseJumpAway.size(); ++i)
	{
		std::vector<int> myPiece = myPiecesHorseJumpAway[i];
		if(myPiece[0] == 5 and myPiece[1] == attSide)
		{
			nrOfAttacks = nrOfAttacks + 1;
		} 
	}
	return nrOfAttacks;
}

int Game::howManyTimesIsSquareAttackedByPawn(int file, int row, int attSide)
{	
	std::vector< std::vector <int>> myPawnsThatAttackSquare = pawnsThatAttackSquare(file, row, attSide);
	
	return myPawnsThatAttackSquare.size();
}

int Game::howManyTimesIsSquareAttackedByBishop(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	std::vector< std::vector< std::vector<int>>> myPiecesOnDiagonals = piecesOnDiagonals(file, row);
	std::vector< std::vector<int>> myFirstDiagonal = myPiecesOnDiagonals[0];
	std::vector< std::vector<int>> mySecondDiagonal = myPiecesOnDiagonals[1];
	
	std::vector< std::vector<int>> bishopsOnFirst;
	std::vector< std::vector<int>> bishopsOnSecond;
	for(unsigned int i = 0; i < myFirstDiagonal.size(); ++i)
	{
		std::vector<int> myPiece = myFirstDiagonal[i];
		if(myPiece[0] == 4 and myPiece[1] == attSide)
		{
			bishopsOnFirst.push_back(myPiece);
		}
	}
	
	for(unsigned int i = 0; i < mySecondDiagonal.size(); ++i)
	{
		std::vector<int> myPiece = mySecondDiagonal[i];
		if(myPiece[0] == 4 and myPiece[1] == attSide)
		{
			bishopsOnSecond.push_back(myPiece);
		}
	}
	
	for(unsigned int i = 0; i < bishopsOnFirst.size(); ++i)
	{
		std::vector<int> myPiece = bishopsOnFirst[i];
		int fileOfBishop = myPiece[2];
		bool isBishopBlocked = false;
		if(file > fileOfBishop)
		{
			for(unsigned int j = 0; j < myFirstDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = myFirstDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece > fileOfBishop and fileOfBlockPiece < file)
				{
					isBishopBlocked = true;
				}
			}		
		}
		else if(file < fileOfBishop)
		{
			for(unsigned int j = 0; j < myFirstDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = myFirstDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece < fileOfBishop and fileOfBlockPiece > file)
				{
					isBishopBlocked = true;
				}
			}
		}
		if(isBishopBlocked == false)
		{
			nrOfAttacks = nrOfAttacks + 1;
		}
	}
	
	for(unsigned int i = 0; i < bishopsOnSecond.size(); ++i)
	{
		std::vector<int> myPiece = bishopsOnSecond[i];
		int fileOfBishop = myPiece[2];
		bool isBishopBlocked = false;
		if(file > fileOfBishop)
		{
			for(unsigned int j = 0; j < mySecondDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = mySecondDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece > fileOfBishop and fileOfBlockPiece < file)
				{
					isBishopBlocked = true;
				}
			}		
		}
		else if(file < fileOfBishop)
		{
			for(unsigned int j = 0; j < mySecondDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = mySecondDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece < fileOfBishop and fileOfBlockPiece > file)
				{
					isBishopBlocked = true;
				}
			}
		}
		if(isBishopBlocked == false)
		{
			nrOfAttacks = nrOfAttacks + 1;
		}
	}
	
	return nrOfAttacks;
}

int Game::howManyTimesIsSquareAttackedByRook(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	std::vector< std::vector <int>> myPiecesOnFile = piecesOnFile(file);
    std::vector< std::vector <int>> myPiecesOnRow = piecesOnRow(row);
    std::vector< std::vector<int>> rooksOnFile;
    std::vector< std::vector<int>> rooksOnRow;
    for(unsigned int i = 0; i < myPiecesOnFile.size(); ++i)
    {
    	std::vector <int> myPiece = myPiecesOnFile[i];
    	if(myPiece[0] == 3 and myPiece[1] == attSide)
    	{
    		rooksOnFile.push_back(myPiece);
    	}
    }
    for(unsigned int i = 0; i < myPiecesOnRow.size(); ++i)
    {
    	std::vector<int> myPiece = myPiecesOnRow[i];
    	if(myPiece[0] == 3 and myPiece[1] == attSide)
    	{
    		rooksOnRow.push_back(myPiece);
    	}
    }
    for(unsigned int i = 0; i < rooksOnFile.size(); ++i)
    {
    	std::vector<int> myPiece = rooksOnFile[i];
    	int myRow = myPiece[3];
    	bool rookIsBlocked = false;
    	if(myRow < row)
    	{
    		for(unsigned int j = 0; j < myPiecesOnFile.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnFile[j];
    			int myBlockRow = myBlockPiece[3];
    			if(myBlockRow > myRow and myBlockRow < row)
    			{
    				rookIsBlocked = true;
    			}
    		}
    	}
    	else if(myRow > row)
    	{
    		for(unsigned int j = 0; j < myPiecesOnFile.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnFile[j];
    			int myBlockRow = myBlockPiece[3];
    			if(myBlockRow > row and myBlockRow < myRow)
    			{
    				rookIsBlocked = true;
    			}
    		}
    	}
    	if(rookIsBlocked == false)
    	{
    		nrOfAttacks = nrOfAttacks + 1;
    	}
    }
    
    for(unsigned int i = 0; i < rooksOnRow.size(); ++i)
    {
    	std::vector <int> myPiece = rooksOnRow[i];
    	int myFile = myPiece[2];
    	bool rookIsBlocked = false;
    	if(myFile < file)
    	{
    		for(unsigned int j = 0; j < myPiecesOnRow.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnRow[j];
    			int myBlockFile = myBlockPiece[2];
    			if(myBlockFile > myFile and myBlockFile < file)
    			{
    				rookIsBlocked = true;
    			}
    		}
    	}
    	else if(myFile > file)
    	{
    		for(unsigned int j = 0; j < myPiecesOnRow.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnRow[j];
    			int myBlockFile = myBlockPiece[2];
    			if(myBlockFile > file and myBlockFile < myFile)
    			{
    				rookIsBlocked = true;
    			}
    		}
    	}
    	if(rookIsBlocked == false)
    	{
    		nrOfAttacks = nrOfAttacks + 1;
    	}
    }
    
	return nrOfAttacks;
}

int Game::howManyTimesIsSquareAttackedByQueen(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	
	//First files and rows
	std::vector< std::vector <int>> myPiecesOnFile = piecesOnFile(file);
    std::vector< std::vector <int>> myPiecesOnRow = piecesOnRow(row);
    std::vector< std::vector<int>> queensOnFile;
    std::vector< std::vector<int>> queensOnRow;
    
    for(unsigned int i = 0; i < myPiecesOnFile.size(); ++i)
    {
    	std::vector <int> myPiece = myPiecesOnFile[i];
    	if(myPiece[0] == 2 and myPiece[1] == attSide)
    	{
    		queensOnFile.push_back(myPiece);
    	}
    }
    for(unsigned int i = 0; i < myPiecesOnRow.size(); ++i)
    {
    	std::vector<int> myPiece = myPiecesOnRow[i];
    	if(myPiece[0] == 2 and myPiece[1] == attSide)
    	{
    		queensOnRow.push_back(myPiece);
    	}
    }
    for(unsigned int i = 0; i < queensOnFile.size(); ++i)
    {
    	std::vector<int> myPiece = queensOnFile[i];
    	int myRow = myPiece[3];
    	bool queenIsBlocked = false;
    	if(myRow < row)
    	{
    		for(unsigned int j = 0; j < myPiecesOnFile.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnFile[j];
    			int myBlockRow = myBlockPiece[3];
    			if(myBlockRow > myRow and myBlockRow < row)
    			{
    				queenIsBlocked = true;
    			}
    		}
    	}
    	else if(myRow > row)
    	{
    		for(unsigned int j = 0; j < myPiecesOnFile.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnFile[j];
    			int myBlockRow = myBlockPiece[3];
    			if(myBlockRow > row and myBlockRow < myRow)
    			{
    				queenIsBlocked = true;
    			}
    		}
    	}
    	if(queenIsBlocked == false)
    	{
    		nrOfAttacks = nrOfAttacks + 1;
    	}
    }
    
    for(unsigned int i = 0; i < queensOnRow.size(); ++i)
    {
    	std::vector <int> myPiece = queensOnRow[i];
    	int myFile = myPiece[2];
    	bool queenIsBlocked = false;
    	if(myFile < file)
    	{
    		for(unsigned int j = 0; j < myPiecesOnRow.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnRow[j];
    			int myBlockFile = myBlockPiece[2];
    			if(myBlockFile > myFile and myBlockFile < file)
    			{
    				queenIsBlocked = true;
    			}
    		}
    	}
    	else if(myFile > file)
    	{
    		for(unsigned int j = 0; j < myPiecesOnRow.size(); ++j)
    		{
    			std::vector<int> myBlockPiece = myPiecesOnRow[j];
    			int myBlockFile = myBlockPiece[2];
    			if(myBlockFile > file and myBlockFile < myFile)
    			{
    				queenIsBlocked = true;
    			}
    		}
    	}
    	if(queenIsBlocked == false)
    	{
    		nrOfAttacks = nrOfAttacks + 1;
    	}
    }
    
    //Second, diagonals
    std::vector< std::vector< std::vector<int>>> myPiecesOnDiagonals = piecesOnDiagonals(file, row);
	std::vector< std::vector<int>> myFirstDiagonal = myPiecesOnDiagonals[0];
	std::vector< std::vector<int>> mySecondDiagonal = myPiecesOnDiagonals[1];
	std::vector< std::vector<int>> queensOnFirst;
	std::vector< std::vector<int>> queensOnSecond;
	
	for(unsigned int i = 0; i < myFirstDiagonal.size(); ++i)
	{
		std::vector<int> myPiece = myFirstDiagonal[i];
		if(myPiece[0] == 2 and myPiece[1] == attSide)
		{
			queensOnFirst.push_back(myPiece);
		}
	}
	
	for(unsigned int i = 0; i < mySecondDiagonal.size(); ++i)
	{
		std::vector<int> myPiece = mySecondDiagonal[i];
		if(myPiece[0] == 4 and myPiece[1] == attSide)
		{
			queensOnSecond.push_back(myPiece);
		}
	}
	
	for(unsigned int i = 0; i < queensOnFirst.size(); ++i)
	{
		std::vector<int> myPiece = queensOnFirst[i];
		int fileOfQueen = myPiece[2];
		bool isQueenBlocked = false;
		if(file > fileOfQueen)
		{
			for(unsigned int j = 0; j < myFirstDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = myFirstDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece > fileOfQueen and fileOfBlockPiece < file)
				{
					isQueenBlocked = true;
				}
			}		
		}
		else if(file < fileOfQueen)
		{
			for(unsigned int j = 0; j < myFirstDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = myFirstDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece < fileOfQueen and fileOfBlockPiece > file)
				{
					isQueenBlocked = true;
				}
			}
		}
		if(isQueenBlocked == false)
		{
			nrOfAttacks = nrOfAttacks + 1;
		}
	}
	
	for(unsigned int i = 0; i < queensOnSecond.size(); ++i)
	{
		std::vector<int> myPiece = queensOnSecond[i];
		int fileOfQueen = myPiece[2];
		bool isQueenBlocked = false;
		if(file > fileOfQueen)
		{
			for(unsigned int j = 0; j < mySecondDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = mySecondDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece > fileOfQueen and fileOfBlockPiece < file)
				{
					isQueenBlocked = true;
				}
			}		
		}
		else if(file < fileOfQueen)
		{
			for(unsigned int j = 0; j < mySecondDiagonal.size(); ++j)
			{
				std::vector<int> myBlockPiece = mySecondDiagonal[i];
				int fileOfBlockPiece = myBlockPiece[2];
				if(fileOfBlockPiece < fileOfQueen and fileOfBlockPiece > file)
				{
					isQueenBlocked = true;
				}
			}
		}
		if(isQueenBlocked == false)
		{
			nrOfAttacks = nrOfAttacks + 1;
		}
	}
	
	return nrOfAttacks;
}

int Game::howManyTimesIsSquareAttackedWithoutKing(int file, int row, int attSide)
{
	int nrOfAttacks = 0;
	
	int pawn = howManyTimesIsSquareAttackedByPawn(file, row, attSide);
	int horse = howManyTimesIsSquareAttackedByHorse(file, row, attSide);
	int bishop = howManyTimesIsSquareAttackedByBishop(file, row, attSide);
	int rook = howManyTimesIsSquareAttackedByRook(file, row, attSide);
	int queen = howManyTimesIsSquareAttackedByQueen(file, row, attSide);
	
	nrOfAttacks = pawn + horse + bishop + rook + queen;
	
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
		if(howManyTimesIsSquareAttackedWithoutKing(kingX,kingY,2) != 0)
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
		if(howManyTimesIsSquareAttackedWithoutKing(kingX,kingY,2) != 0)
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
	if(turn % 2== 0 )
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
