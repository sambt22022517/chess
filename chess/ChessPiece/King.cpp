#ifndef KING
#define KING

#include <bits/stdc++.h>
#include "ChessPiece.cpp"
#include "..\Utility\Utility.cpp"

using namespace std;

int scoreKing = 1e9;

class King : public ChessPiece{
public:
    King() : ChessPiece(){
        
    }
    King(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreKing;
            ChessPiece:: kindPiece = 'k';
        } 
        else{
            ChessPiece:: score = scoreKing;
            ChessPiece:: kindPiece = 'K';
        }
    }

    vector<Point> validMove() override{
        return {};
    }

    void move() override{

    }
};


#endif