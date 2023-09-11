#ifndef KNIGHT
#define KNIGHT

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"

using namespace std;

int scoreKnight = 3;

class Knight : public ChessPiece{
public:
    Knight() : ChessPiece(){
        
    }
    Knight(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreKnight;
            ChessPiece:: kindPiece = 'n';
        } 
        else {
            ChessPiece:: score = scoreKnight;
            ChessPiece:: kindPiece = 'N';
        }
    }

    vector<Point> validMove() override{
        return {};
    }

    void move() override{

    }
};



#endif