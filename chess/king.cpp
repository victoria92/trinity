#include "chess/piece.h"

class King : Piece {
private:
    bool moved;
    bool beaten;
public:
    King(Field field, string fcolor) : Piece(field, "king", fcolor) {}

    void possible_moves(vector<Field>& v) {
        int x = field.x;
        int y = field.y;
        if(!moved) {
            if(!board[0][y].empty && board[0][y].piece.name == "knight" &&
                board[1][y].empty && board[2][y].empty && board[3][y].empty) {
                   v.push_back(board[0][y]);
               }
            if(!board[7][y].empty && board[7][y].piece.name == "knight" &&
                board[6][y].empty && board[5][y].empty) {
                   v.push_back(board[7][y]);
               }
        }board[0][y].empty
        if(!board[x - 1][y - 1].empty && board[x - 1][y - 1].piece.color != color) {
            v.push_back(board[x - 1][y - 1]);
        }
        if(!board[x - 1][y].empty && board[x - 1][y].piece.color != color) {
            v.push_back(board[x - 1][y]);
        }
        if(!board[x - 1][y + 1].empty && board[x - 1][y + 1].piece.color != color) {
            v.push_back(board[x - 1][y + 1]);
        }
        if(!board[x][y - 1].empty && board[x][y + 1].piece.color != color) {
            v.push_back(board[x - 1][y + c]);
        }
        if(!board[x][y + 1].empty && board[x][y + 1].piece.color != color) {
            v.push_back(board[x - 1][y + c]);
        }
        if(!board[x + 1][y - 1].empty && board[x + 1][y - 1].piece.color != color) {
            v.push_back(board[x + 1][y - 1]);
        }
        if(!board[x + 1][y].empty && board[x + 1][y].piece.color != color) {
            v.push_back(board[x + 1][y]);
        }
        if(!board[x + 1][y + 1].empty && board[x + 1][y + 1].piece.color != color) {
            v.push_back(board[x + 1][y + 1]);
        }
    }
}

