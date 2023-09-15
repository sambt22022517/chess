#ifndef KNIGHT
#define KNIGHT

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
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

        firstmove = true;
        for(auto i: default_location){
            if(i == start){
                firstmove = false;
                break;
            }   
        }
    }

    vector<Point> validMove() override {  
        vector<Point> director = {Point(2, 1), Point(1, 2), 
                                  Point(2, -1), Point(1, -2), 
                                  Point(-2, 1), Point(-1, 2), 
                                  Point(-2, -1), Point(-1, -2)};
        vector<Point> output;
        Point current = location;
        for(auto i: director){
            if ((current + i).isValid()){
                ChessPiece* c = get_dataBoard(current + i);
                if(c == nullptr){
                    output.push_back(current + i);
                } else {
                    if (c->get_kind() != kind) {
                        output.push_back(current + i);
                    }
                }
            }
        }
        return output;
    }
    const static vector<string> default_location;
};
const vector<string> Knight:: default_location = {"b1N","g1N","b8n","g8n"};


#endif