#ifndef PAWN
#define PAWN

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"

using namespace std;

int scorePawn = 1;

class Pawn : public ChessPiece{
public:
    Pawn() : ChessPiece(){
        
    }
    Pawn(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scorePawn;
            ChessPiece:: kindPiece = 'p';
        } 
        else{
            ChessPiece:: score = scorePawn;
            ChessPiece:: kindPiece = 'P';
        }
    }
    
    vector<Point> validMove() override{
        /*
        code test
        */
        int i = corrdinate.get_i(), j = corrdinate.get_j();
        return {Point(i + 1, j), Point(i + 2, j)};

        /*
        new code here
        */
    }

    void move() override{

    }
};


#endif