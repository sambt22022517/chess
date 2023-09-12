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
    
    vector<Point> validMove() override {  
        vector<Point> director = {E, S, W, N};
        vector<Point> output;
        for(auto i: director){
            Point current = coordinate;
            while(Point::checkValid(current.get_i() + i.get_i(), current.get_j() + i.get_j())){
                ChessPiece* c = dataBoard[current.get_i() + i.get_i()][current.get_j() + i.get_j()];
                if(c == nullptr){
                    output.push_back(Point(current.get_i() + i.get_i(), current.get_j() + i.get_j()));

                } else {
                    if(c->getkind() != kind){
                        output.push_back(Point(current.get_i() + i.get_i(), current.get_j() + i.get_j()));
                    }
                    break;
                }
                current = output.back();
            }
        }
        return output;
    }
};

#endif