#include "chess/piece.h"

class Knight : Piece {
public:
    Knight(Field field, string fcolor) : Piece(field, "knight", fcolor) {}

    void possible_moves(set<Field>& v) {
        int x = field.x;
        int y = field.y;
        if(x + 1 < 8 && y + 2 < 8 && (board[x + 1][y + 2].empty || board[x + 1][y + 2].piece.color != color)) {
            v.insert(board[x + 1][y + 2]);
        }
        if(x + 1 < 8 && y - 2 >= 0 && (board[x + 1][y - 2].empty || board[x + 1][y - 2].piece.color != color)) {
            v.insert(board[x + 1][y - 2]);
        }
        if(x - 1 >= 0 && y + 2 < 8 && (board[x - 1][y + 2].empty || board[x - 1][y + 2].piece.color != color)) {
            v.insert(board[x - 1][y + 2]);
        }
        if(x - 1 >= 0 && y - 2 >= 0 && (board[x - 1][y - 2].empty || board[x - 1][y - 2].piece.color != color)) {
            v.insert(board[x - 1][y - 2]);
        }
        if(x + 2 < 8 && y + 1 < 8 && (board[x + 2][y + 1].empty || board[x + 2][y + 1].piece.color != color)) {
            v.insert(board[x + 2][y + 1]);
        }
        if(x + 2 < 8 && y - 1 >= 0 && (board[x + 2][y - 1].empty || board[x + 2][y - 1].piece.color != color)) {
            v.insert(board[x + 2][y - 1]);
        }
        if(x - 2 >= 0 && y + 1 < 8 && (board[x - 2][y + 1].empty || board[x - 2][y + 1].piece.color != color)) {
            v.insert(board[x - 2][y + 1]);
        }
        if(x - 2 >= 0 && y - 1 >= 0 && (board[x - 2][y - 1].empty || board[x - 2][y - 1].piece.color != color)) {
            v.insert(board[x - 2][y - 1]);
        }
    }
}
