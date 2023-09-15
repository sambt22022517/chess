#ifndef QUEEN
#define QUEEN

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
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

        firstmove = true;
        for(auto i: default_location){
            if(i == start){
                firstmove = false;
                break;
            }   
        }
    }
    
    vector<Point> validMove() override {  
        vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS, Point::E, Point:: S, Point:: N, Point:: W};
        vector<Point> output;
        for(auto i: director){
            Point current = location;
            while((current + i).isValid()){
                ChessPiece* c = get_dataBoard(current + i);
                
                if(c == nullptr){
                    output.push_back(current + i);

                }else{
                    if(c->get_kind() != kind){
                        output.push_back(current + i);
                    }
                    break;
                }
                current = current + i;
            }
        }
        return output;
    }
    const static vector<string> default_location;
};
const vector<string> Queen:: default_location = {"d1Q", "d8q"};

#endif