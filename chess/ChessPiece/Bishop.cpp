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
        vector<Point> director = {EN, ES, WN, WS};
        vector<Point> output;
        for(auto i: director){
            Point current = coordinate;
            while(Point::checkValid(current.get_i() + i.get_i(), current.get_j() + i.get_j())){
                ChessPiece* c = dataBoard[current.get_i() + i.get_i()][current.get_j() + i.get_j()];
                if(c == nullptr){
                    output.push_back(Point(current.get_i() + i.get_i(), current.get_j() + i.get_j()));

                }else{
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