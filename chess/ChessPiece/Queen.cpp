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
    
    vector<Point> validMove() override {  
        vector<Point> director = {EN, ES, WN, WS, E, W, S, N};
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