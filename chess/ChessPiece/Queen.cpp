#ifndef QUEEN
#define QUEEN

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"

using namespace std;

int scoreQueen = 9;

class Queen : public ChessPiece{
public:
    Queen() : ChessPiece(){
        
    }
    Queen(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreQueen;
            ChessPiece:: kindPiece = 'q';
        } 
        else{
            ChessPiece:: score = scoreQueen;
            ChessPiece:: kindPiece = 'Q';
        }
    }
    
    vector<Point> validMove() override{
        return {};
    }

    void move() override{

    }
};


#endif