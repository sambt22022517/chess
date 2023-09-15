#ifndef PIECE
#define PIECE

#include "Bishop.cpp"
#include "King.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "Queen.cpp"
#include "Rock.cpp"


ChessPiece* creatPiece(string start){
    char kind;
    if(start[2] >= 'A' && start[2] <= 'Z') kind = 'W';
    else kind = 'B';

    if(start[2] == 'P' || start[2] == 'p') return new Pawn(kind ,start);
    else if(start[2] == 'K' || start[2] == 'k') return new King(kind ,start);
    else if(start[2] == 'N' || start[2] == 'n') return new Knight(kind ,start);
    else if(start[2] == 'B' || start[2] == 'b') return new Bishop(kind ,start);
    else if(start[2] =='Q' || start[2] == 'q') return new Queen(kind ,start);
    else if(start[2] =='R' || start[2] == 'r') return new Rock(kind ,start);
    else return nullptr;

}

#endif
