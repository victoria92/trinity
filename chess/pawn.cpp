#include "chess/piece.h"

class Pawn : Piece {
private:
    bool moved;

public:
    Pawn(Field field, string rcolor, string rname = "pawn") : color(rcolor), name(rname), place(field), board(field.board) {
        field.piece = this;
        field.empty = false;
        moved = false;
    }

    void possible_moves(vector<Field>& v) {
        int c = 1;
        if(color = "white") {
            c = -1;
        }
        int x = field.x;
        int y = field.y;
        if(board[x][y + c].empty) {
            v.push_back(board[x][y + c]);
            if(!moved && board[x][y + 2*c].empty) {
                v.push_back(board[x][y + 2*c]);
            }
        }
        if(!board[x - 1][y + c].empty && board[x - 1][y + c].piece.color != color) {
            v.push_back(board[x - 1][y + c]);
        }
        if(!board[x + 1][y + c].empty && board[x + 1][y + c].piece.color != color) {
            v.push_back(board[x + 1][y + c]);
        }
    }

    void move(Field field)
        field.piece = this;
        place.piece = NULL;
        place.empty = true;
        place = field;
    }
}
