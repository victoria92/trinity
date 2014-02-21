class Piece;

struct Field {
    //bool empty;
    Piece* piece;
}

class Piece {
    string name;
    Field place;
    Piece(Field, name);
    virtual Fields* possible_moves();
    virtual void move();
}
