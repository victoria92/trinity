#include "chess/piece.h"

class Rook : Piece {
private:
    bool moved;

public:
    Rook(Field field, string rcolor, string rname = "rook") : color(rcolor), name(rname), place(field), board(field.board) {
        field.piece = this;
        field.empty = false;
        moved = false;
    }

    void possible_moves(vector<Field>& v) {
        int x = field.x;
        int y = field.y;
        int i;
        for(i = ++x; i < 8 && board[i][y].empty; i++) {
            v.push_back(board[i][y])
        }
        if(i < 8 && board[i][y].piece->color != color) {
            v.push_back(board[i][y]);
        }

        for(i = --x; i >= 0 && board[i][y].empty; i--) {
            v.push_back(board[i][y])
        }
        if(i >= 0 && board[i][y].piece->color != color) {
            v.push_back(board[i][y]);
        }

        for(i = ++y; i < 8 && board[x][i].empty; i++) {
            v.push_back(board[x][i])
        }
        if(i < 8 && board[x][i].piece->color != color) {
            v.push_back(board[x][i]);
        }

        for(i = --y; i >= 0 && board[x][i].empty; i--) {
            v.push_back(board[x][i])
        }
        if(i >= 0 && board[x][i].piece->color != color) {
            v.push_back(board[x][i]);
        }
    }

    void move(Field field)
        field.piece = this;
        place.piece = NULL;
        place.empty = true;
        place = field;
    }
}
