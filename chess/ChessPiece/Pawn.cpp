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
        // /*
        // code test
        // */
        int i = coordinate.get_i(), j = coordinate.get_j();
        vector<Point> output;
        output.push_back(Point(i + 1, j));
        if (not firstmove) {
            output.push_back(Point(i + 2, j));
        }
        ChessPiece* c1 = dataBoard[i + 1][j + 1];
        if (c1 != nullptr and c1->getkind() != this->kind) output.push_back(Point(i + 1, j + 1));

        ChessPiece* c2 = dataBoard[i + 1][j - 1];
        if (c2 != nullptr and c2->getkind() != this->kind) output.push_back(Point(i + 1, j - 1));

        return output;
        /*
        new code here
        */
       // return {};
    }
};


#endif