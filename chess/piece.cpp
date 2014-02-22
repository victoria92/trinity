#include "piece.h"

Field::Field(int _x, int _y) : x(_x), y(_y) {}

bool Field::operator==(const Field& f) {
    if(x == f.x && y == f.y)
        return true;
    return false;
}

Board::Board() {
    for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++) {
        board[i][j] = new Field(i, j);
    }
}

void Board::get_all_pieces(vector<Piece*>& v) {
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            if(board[i][j]->piece) {
                v.push_back(board[i][j]->piece);
            }
        }
    }
}

bool Board::is_threatened() {
    vector<Piece*> pieces;
    get_all_pieces(pieces);
    Piece* king;
    for(int i = 0; i < pieces.size(); i++) {
        if(pieces[i]->name == "king") {
            king = pieces[i];
            break;
        }
    }
    for(int i = 0; i < pieces.size(); i++) {
        vector<Field*> v;
        pieces[i]->possible_moves(v);
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == king->place) {
                return true;
            }
        }
    }
    return false;
}

Piece::Piece(Field* field, string fname, string fcolor) :
    name(fname),
    color(fcolor),
    place(field),
    board(field->board) {
    field->piece = this;
    field->empty = false;
    moved = false;
    beaten = false;
}

bool Piece::move(Field& field) {
    vector<Field*> moves;
    possible_moves(moves);
    bool flag = false;
    for(int i = 0; i < moves.size(); i++) {
        if(*moves[i] == field) {
            flag = true;
        }
    }
    if(flag) {
        Piece* beated_piece = field.piece;
        Field* start_place = place;
        if(field.piece) {
            if(name == "king" && board->is_threatened() && field.piece->name == "rook" && color == field.piece->color) {
                if(field.x == 0)
                    field.piece->place = board->board[3][place->y];
                else
                    field.piece->place = board->board[5][place->y];
            }
            else {
                field.piece->beaten = true;
                //field.piece->place = nullptr;
            }
        }
        field.piece = this;
        place->piece = NULL;
        place->empty = true;
        place = &field;
        if(board->is_threatened()) {
            start_place->piece = this;
            place = start_place;
            field.piece = beated_piece;
            beated_piece->place = &field;
        }
        moved = true;
        return true;
    }
    return false;
}
