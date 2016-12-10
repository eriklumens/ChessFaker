#include <vector>
#include <string>

class Game
{
    private:
	std::vector< std::vector< std::vector<int>>> boardAtStart = {{{3,1},{5,1},{4,1},{2,1},{1,1},{4,1},{5,1},{3,1}},
	{{6,1},{6,1},{6,1},{6,1},{6,1},{6,1},{6,1},{6,1}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
	{{6,2},{6,2},{6,2},{6,2},{6,2},{6,2},{6,2},{6,2}},
	{{3,2},{5,2},{4,2},{2,2},{1,2},{4,2},{5,2},{3,2}}};	
	std::vector< std::vector< std::vector <int>>> board{std::vector<std::vector<std::vector<int > > >(0,std::vector<std::vector<int> >(0,std::vector<int>(0)))};
	int turn = 0;
	std::vector< std::vector< std::vector< std::vector <int>>>> history{std::vector<std::vector<std::vector<std::vector<int > > > >(0,std::vector<std::vector<std::vector<int> >>(0,std::vector<std::vector<int>>(0,std::vector<int>(0))))};
	std::vector<std::string> moves;
	
    public:
    Game(std::vector< std::vector< std::vector <int>>> board, int turn,std::vector< std::vector< std::vector< std::vector <int>>>> history, std::vector<std::string> moves);
    ~Game();
    std::vector< std::vector< std::vector <int>>> getBoard();
    std::string getPrintValue(std::vector<int> piece);
    void printBoard();
    
    std::vector< std::vector <int>> piecesOnFile(int file);
    std::vector< std::vector <int>> piecesOnRow(int row);
    std::vector< std::vector <int>> piecesHorseJumpAway(int file, int row);
    std::vector< std::vector< std::vector<int>>> piecesOnDiagonals(int file, int row);
    
    std::vector< std::vector <int>> pawnsThatAttackSquare(int file, int row, int attSide);
    int howManyTimesIsSquareAttackedByPawn(int file, int row, int attSide);
    std::vector< std::vector<int>> horsesThatAttackSquare(int file, int row, int attSide);
    int howManyTimesIsSquareAttackedByHorse(int file, int row, int attSide);
    std::vector< std::vector<int>> bishopsThatAttackSquare(int file, int row, int attSide);
	int howManyTimesIsSquareAttackedByBishop(int file, int row, int attSide);
	std::vector< std::vector<int>> rooksThatAttackSquare(int file, int row, int attSide);
	int howManyTimesIsSquareAttackedByRook(int file, int row, int attSide);
	std::vector< std::vector<int>> queensThatAttackSquare(int file, int row, int attSide);
	int howManyTimesIsSquareAttackedByQueen(int file, int row, int attSide);
	int howManyTimesIsSquareAttackedWithoutKing(int file, int row, int attSide);
	
    int check();
    
    std::vector< std::vector <int>> squaresKingMoveAway(int file, int row);
    
    bool hasARookMoved();
    bool hasHRookMoved();
    bool hasKingMoved();
    bool aPathClear();
    bool hPathClear();
    bool castleLongIsLegal();
    bool castleShortIsLegal();
    
    bool legalMove(std::string move);
    void makeMove(std::string move);  
    bool isFinished();  
};
