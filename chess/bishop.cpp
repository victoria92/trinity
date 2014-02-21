#include "chess/piece.h"

class Bishop : Piece {
public:
    Bishop(Field field, string fcolor) : Piece(field, "bishop", fcolor) {}

    void possible_moves(vector<Field>& v) {
        int x = field.x;
        int y = field.y;
        int i, j;
        for(i = ++x, j = ++y; i < 8 && j < 8 && board[i][j].empty; i++, j++) {
            v.push_back(board[i][j])
        }
        if(i < 8, j < 8 && board[i][j].piece->color != color) {
            v.push_back(board[i][j]);
        }

        for(i = ++x, j = --y; i < 8 && j >= 0 && board[i][j].empty; i++, j--) {
            v.push_back(board[i][y])
        }
        if(i < 8 && j >= 0 && board[i][j].piece->color != color) {
            v.push_back(board[i][j]);
        }

        for(i = --x, j = ++y; i >= 0 && j < 8 && board[i][j].empty; i--, j++) {
            v.push_back(board[i][j])
        }
        if(i >= 0 && j < 8 && board[i][j].piece->color != color) {
            v.push_back(board[i][j]);
        }

        for(i = --x, j = --y; i >= 0 && j >= 0 && board[x][i].empty; i--, j--) {
            v.push_back(board[i][j])
        }
        if(i >= 0 && j >= 0 && board[i][j].piece->color != color) {
            v.push_back(board[i][j]);
        }
    }
}

