#ifndef NULL_
#define NULL_

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"

using namespace std;

int scoreNull = 0;

class Null : public ChessPiece{
public:
    Null() : ChessPiece(){
        
    }
    Null(char kind, string start) : ChessPiece(kind, start){
        ChessPiece:: score = scoreNull;
        ChessPiece:: kindPiece = nullsquare;
    }
    
    vector<Point> validMove() override{
        return {};
    }

    void move() override{

    }
};



#endif