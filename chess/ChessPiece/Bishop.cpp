#ifndef BISHOP
#define BISHOP

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"
using namespace std;

int scoreBishop = 3;

class Bishop : public ChessPiece{
public:
    Bishop() : ChessPiece(){
        
    }
    Bishop(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreBishop;
            ChessPiece::kindPiece = 'b';
        } 
        else{
            ChessPiece:: score = scoreBishop;
            ChessPiece::kindPiece = 'B';
        } 
    }

    vector<Point> validMove() override{
        
        return {};
    }

    bool move(string end) override{
        return true;
    }
};


#endif