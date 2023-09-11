#ifndef PIECE
#define PIECE

#include "Bishop.cpp"
#include "King.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "Queen.cpp"
#include "Rock.cpp"
#include "Null.cpp"

ChessPiece* creatPiece(string start){
    char kind;
    if(start[2] >= 'A' && start[2] <= 'Z') kind = 'W';
    else kind = 'B';

    if(start[2] == 'P' || start[2] == 'p') return new Pawn(kind ,start.substr(0,2));
    else if(start[2] == 'K' || start[2] == 'k') return new King(kind ,start.substr(0,2));
    else if(start[2] == 'N' || start[2] == 'n') return new Knight(kind ,start.substr(0,2));
    else if(start[2] == 'B' || start[2] == 'b') return new Bishop(kind ,start.substr(0,2));
    else if(start[2] =='Q' || start[2] == 'q') return new Queen(kind ,start.substr(0,2));
    else if(start[2] =='R' || start[2] == 'r') return new Rock(kind ,start.substr(0,2));
    else return new Null(kind, start.substr(0,2));
    
}

#endif
