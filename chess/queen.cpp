#include "chess/piece.h"

class Queen : Piece {
public:
    Queen(Field field, string fcolor) : Piece(field, "queen", fcolor) {}

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

        int j;
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

