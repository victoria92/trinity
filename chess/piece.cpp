#include "piece.h"


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
        set<Field> s;
        pieces[i]->possible_moves(s);
        if(s.find(king->place) != s.end())
            return true;
    }
    return false;
}

Piece::Piece(Field& field, string fname, string fcolor) :
    name(fname),
    color(fcolor),
    place(field),
    board(field.board) {
    field.piece = this;
    field.empty = false;
    moved = false;
    beaten = false;
}

bool Piece::move(Field& field) {
    set<Field> moves;
    possible_moves(moves);
    if(moves.find(field) != moves.end()) {
        Piece* beated_piece = field.piece;
        Field start_place = place;
        if(field.piece) {
            if(name == "king" && board->is_threatened() && field.piece->name == "rook" && color == field.piece->color) {
                if(field.x = 0)
                    field.piece->place = board[3][place.y];
                else
                    field.piece->place = board[5][place.y];
            }
            else {
                field.piece.beaten = true;
                field.piece.place = NULL;
            }
        }
        field.piece = this;
        place.piece = NULL;
        place.empty = true;
        place = field;
        if(board.is_threatened()) {
            start_place.piece = this;
            piece.place = start_place;
            field.piece = beated_piece;
            beated_piece.place = field;
        }
        moved = true;
        return true;
    }
    return false;
}
