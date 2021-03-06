#include "evaluation.cpp"
#include "game.h"
#include <iostream>
#include <algorithm>

std::string engineOutput(Game game, int side, int depth)
{
	std::string engineMove = "";
	
	std::vector< std::vector< std::vector <int>>> currentBoard = game.getBoard();
	
	Game moveGame = game;
	
	std::vector<Game> gamesPerDepthLevel[depth + 1];
	std::vector< std::vector< std::string>> movesPerDepthLevel[depth];
	std::vector<int> nrOfBranchesPerNode[depth];
	
	gamesPerDepthLevel[0] = {moveGame};
	
	for(int i = 0; i < depth; ++i)
	{	
		std::vector<Game> gamesThisDepth = gamesPerDepthLevel[i];
		std::vector<Game> correspondingGames;
		std::vector< std::vector<std::string> > movesForThisDepth;
		std::vector<int> nrOfBranchesForThisLevel;
		for(unsigned int x = 0; x < gamesThisDepth.size(); ++x) //Look at every game in tree level
		{
			Game myGame = gamesThisDepth[x];
			
			//Find all moves for particular game in this tree level
			//myGame.printBoard();
			std::vector<std::string> movesCurrentTurn = myGame.legalMoveList(myGame.getBoard(), myGame.getTurn());			
			movesForThisDepth.push_back(movesCurrentTurn);
			nrOfBranchesForThisLevel.push_back(movesCurrentTurn.size());
			for(unsigned int j = 0; j < movesCurrentTurn.size(); ++j) //perform all moves for this particular level
			{
				Game testGame = myGame;
				testGame.makeMove(movesCurrentTurn[j]);
				//testGame.printBoard();
				correspondingGames.push_back(testGame);
			}
		}
		//Set moves and corresponding games in next tree level
		movesPerDepthLevel[i] = movesForThisDepth;
		gamesPerDepthLevel[i+1] = correspondingGames;
		nrOfBranchesPerNode[i] = nrOfBranchesForThisLevel;
	}
	
	std::vector< float> evaluationsPerDepthLevel[depth];
	std::vector<Game> gamesLastDepth = gamesPerDepthLevel[depth];
	std::vector<float> myEvaluations;
	for(unsigned int x = 0; x < gamesLastDepth.size(); ++x)
	{
		Game myGame = gamesLastDepth[x];
		float myEvaluation = evaluationFunction(myGame);
		myEvaluations.push_back(myEvaluation);
	}
	evaluationsPerDepthLevel[depth - 1] = myEvaluations;
	for(int i = 0; i < depth; ++i)
	{
		std::vector<float> evaluationsForThisDepth = evaluationsPerDepthLevel[depth - i - 1]; 
		std::vector<float> newEvaluations;
		std::vector<int> nrOfBranchesForThisDepth = nrOfBranchesPerNode[depth - i - 1];
		int sum = 0;
		int intValueFirstMove = 0;
		for(unsigned int j = 0; j < nrOfBranchesForThisDepth.size(); ++j)//nr of times we need to max or min
		{
			std::vector<float>::iterator result;
			int nrOfBranches = nrOfBranchesForThisDepth[j];
			
			if((i%2 == 0 and game.getTurn()%2 != 0) or (i%2 != 0 and game.getTurn()%2 == 0))//Black's turn, we want to minimize over evaluation values bigger branch
			{
				result = std::min_element(std::begin(evaluationsForThisDepth) + sum, std::begin(evaluationsForThisDepth) + sum + nrOfBranches - 1);
    			
			}
			else if((i%2 == 0 and game.getTurn()%2 == 0) or (i%2 != 0 and game.getTurn()%2 != 0))//White's turn, we want to maximize over evaluation values bigger branch
			{
				result = std::min_element(std::begin(evaluationsForThisDepth) + sum, std::begin(evaluationsForThisDepth) + sum + nrOfBranches - 1);
			}
			float resultForThisNode = evaluationsForThisDepth.at(std::distance(evaluationsForThisDepth.begin(), result));
			intValueFirstMove = std::distance(evaluationsForThisDepth.begin(), result);
			newEvaluations.push_back(resultForThisNode); 
			sum += nrOfBranches;	
		}
		if(i != depth - 1)
		{
			evaluationsPerDepthLevel[depth - i - 2] = newEvaluations;
		}
		else
		{
			std::vector< std::vector< std::string>> firstMoves = movesPerDepthLevel[0];
			std::vector<std::string > choicesForFirstMove = firstMoves[0];
			engineMove = choicesForFirstMove.at(intValueFirstMove);
		}
	}
	
	return engineMove;
}
