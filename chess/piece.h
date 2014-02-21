class Piece;
struct Board;

struct Field {
    bool empty;
    int x;
    int y;
    Piece* piece;
    Board* board;
}

struct Board {
    Field board[8][8];
};

class Piece {
    string color;
    string name;
    Field place;
    Board board;
    Piece(Field, string, string);
    virtual void possible_moves(vector&);
    virtual void move(Field&);
}
