#include <set>
#include <vector>
#include <string>

using namespace std;

class Piece;
class Board;

class Field {
public:
    bool empty;
    int x;
    int y;
    Piece* piece;
    Board* board;
    bool operator==(const Field&);
};

class Board {
public:
    Field* board[8][8];
    Board(const Board&);
    void get_all_pieces(vector<Piece*>&);
    bool is_threatened();
};

class Piece {
public:
    bool moved;
    bool beaten;
    string color;
    string name;
    Field* place;
    Board* board;
    Piece(Field*, string, string);
    virtual void possible_moves(vector<Field>&) = 0;
    bool move(Field&);
};
