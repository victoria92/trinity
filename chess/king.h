#ifndef KING_H

#include "../chess/piece.h"

class King : public Piece {
public:
    King(Field* field, string fcolor) : Piece(field, "king", fcolor) {}

    void possible_moves(vector<Field*>& v) {
        int x = place->x;
        int y = place->y;
        if(!moved) {
            if(!board->board[0][y]->empty && board->board[0][y]->piece->name == "rook" && color == board->board[0][y]->piece->color && !board->board[0][y]->piece->moved &&
                board->board[1][y]->empty && board->board[2][y]->empty && board->board[3][y]->empty) {
                   v.push_back(board->board[2][y]);
               }
            if(!board->board[7][y]->empty && board->board[7][y]->piece->name == "rook" && color == board->board[7][y]->piece->color && !board->board[0][y]->piece->moved &&
                board->board[6][y]->empty && board->board[5][y]->empty) {
                   v.push_back(board->board[6][y]);
               }
        }
        if(!board->board[x - 1][y - 1]->empty && board->board[x - 1][y - 1]->piece->color != color) {
            v.push_back(board->board[x - 1][y - 1]);
        }
        if(!board->board[x - 1][y]->empty && board->board[x - 1][y]->piece->color != color) {
            v.push_back(board->board[x - 1][y]);
        }
        if(!board->board[x - 1][y + 1]->empty && board->board[x - 1][y + 1]->piece->color != color) {
            v.push_back(board->board[x - 1][y + 1]);
        }
        if(!board->board[x][y - 1]->empty && board->board[x][y + 1]->piece->color != color) {
            v.push_back(board->board[x][y - 1]);
        }
        if(!board->board[x][y + 1]->empty && board->board[x][y + 1]->piece->color != color) {
            v.push_back(board->board[x][y + 1]);
        }
        if(!board->board[x + 1][y - 1]->empty && board->board[x + 1][y - 1]->piece->color != color) {
            v.push_back(board->board[x + 1][y - 1]);
        }
        if(!board->board[x + 1][y]->empty && board->board[x + 1][y]->piece->color != color) {
            v.push_back(board->board[x + 1][y]);
        }
        if(!board->board[x + 1][y + 1]->empty && board->board[x + 1][y + 1]->piece->color != color) {
            v.push_back(board->board[x + 1][y + 1]);
        }
    }
};

#endif // KING_H
