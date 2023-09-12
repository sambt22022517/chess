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

    vector<Point> validMove() override {  
        vector<Point> director = {Point(2, 1), Point(1, 2), 
                                  Point(2, -1), Point(1, -2), 
                                  Point(-2, 1), Point(-1, 2), 
                                  Point(-2, -1), Point(-1, -2)};
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