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

    vector<Point> validMove() override {  
        vector<Point> director = {EN, ES, WN, WS, W, E, N, S};
        vector<Point> output;
        Point current = coordinate;
        for(auto i: director){
            if (Point::checkValid(current.get_i() + i.get_i(), current.get_j() + i.get_j())){
                ChessPiece* c = dataBoard[current.get_i() + i.get_i()][current.get_j() + i.get_j()];
                if(c == nullptr){
                    output.push_back(Point(current.get_i() + i.get_i(), current.get_j() + i.get_j()));
                } else {
                    if (c->getkind() != kind) {
                        output.push_back(Point(current.get_i() + i.get_i(), current.get_j() + i.get_j()));
                    }
                }
            }
        }
        return output;
    }
};


#endif