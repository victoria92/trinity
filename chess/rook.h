#ifndef ROOK_H

#include "../chess/piece.h"

class Rook : public Piece {
public:
    Rook(Field* field, string fcolor) : Piece(field, "rook", fcolor) {}

    void possible_moves(vector<Field*>& v) {
        int x = place->x;
        int y = place->y;
        int i;
        for(i = ++x; i < 8 && board->board[i][y]->empty; i++) {
            v.push_back(board->board[i][y]);
        }
        if(i < 8 && board->board[i][y]->piece->color != color) {
            v.push_back(board->board[i][y]);
        }

        for(i = --x; i >= 0 && board->board[i][y]->empty; i--) {
            v.push_back(board->board[i][y]);
        }
        if(i >= 0 && board->board[i][y]->piece->color != color) {
            v.push_back(board->board[i][y]);
        }

        for(i = ++y; i < 8 && board->board[x][i]->empty; i++) {
            v.push_back(board->board[x][i]);
        }
        if(i < 8 && board->board[x][i]->piece->color != color) {
            v.push_back(board->board[x][i]);
        }

        for(i = --y; i >= 0 && board->board[x][i]->empty; i--) {
            v.push_back(board->board[x][i]);
        }
        if(i >= 0 && board->board[x][i]->piece->color != color) {
            v.push_back(board->board[x][i]);
        }
    }
};

#endif
