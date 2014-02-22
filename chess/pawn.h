#ifndef PAWN_H

#include "../chess/piece.h"

class Pawn : public Piece {
public:
    Pawn(Field* field, string fcolor) : Piece(field, "pawn", fcolor) {}

    void possible_moves(vector<Field*>& v) {
        int c = 1;
        if(color == "white") {
            c = -1;
        }
        int x = place->x;
        int y = place->y;
        if(board->board[x][y + c] == NULL) {
            v.push_back(board->board[x][y + c]);
            if(moved && board->board[x][y + 2*c] != NULL) {
                v.push_back(board->board[x][y + 2*c]);
            }
        }
        if(board->board[x - 1][y + c] != NULL && board->board[x - 1][y + c]->piece->color != color) {
            v.push_back(board->board[x - 1][y + c]);
        }
        if(board->board[x + 1][y + c] != NULL && board->board[x + 1][y + c]->piece->color != color) {
            v.push_back(board->board[x + 1][y + c]);
        }
    };
};

#endif // PAWN_H
