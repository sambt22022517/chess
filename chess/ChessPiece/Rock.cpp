#ifndef ROCK
#define ROCK

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "ChessPiece.cpp"

using namespace std;

int scoreRock = 5;

class Rock : public ChessPiece{
public:
    Rock() : ChessPiece(){
        
    }
    Rock(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreRock;
            ChessPiece:: kindPiece = 'r';
        } 
        else{
            ChessPiece:: score = scoreRock;
            ChessPiece:: kindPiece = 'R';
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