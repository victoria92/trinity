#ifndef BISHOP_H

#include "../chess/piece.h"

class Bishop : public Piece {
public:
    Bishop(Field* field, string fcolor) : Piece(field, "bishop", fcolor) {}

    void possible_moves(vector<Field*>& v) {
        int x = place->x;
        int y = place->y;
        int i, j;
        for(i = ++x, j = ++y; i < 8 && j < 8 && board->board[i][j]->empty; i++, j++) {
            v.push_back(board->board[i][j]);
        }
        if(i < 8, j < 8 && board->board[i][j]->piece->color != color) {
            v.push_back(board->board[i][j]);
        }

        for(i = ++x, j = --y; i < 8 && j >= 0 && board->board[i][j]->empty; i++, j--) {
            v.push_back(board->board[i][y]);
        }
        if(i < 8 && j >= 0 && board->board[i][j]->piece->color != color) {
            v.push_back(board->board[i][j]);
        }

        for(i = --x, j = ++y; i >= 0 && j < 8 && board->board[i][j]->empty; i--, j++) {
            v.push_back(board->board[i][j]);
        }
        if(i >= 0 && j < 8 && board->board[i][j]->piece->color != color) {
            v.push_back(board->board[i][j]);
        }

        for(i = --x, j = --y; i >= 0 && j >= 0 && board->board[x][i]->empty; i--, j--) {
            v.push_back(board->board[i][j]);
        }
        if(i >= 0 && j >= 0 && board->board[i][j]->piece->color != color) {
            v.push_back(board->board[i][j]);
        }
    }
};

#endif // BISHOP_H
