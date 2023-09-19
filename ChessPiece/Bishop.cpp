#ifndef BISHOP
#define BISHOP

#include <bits/stdc++.h>
#include "ChessPiece.cpp"
#include "..\Utility\Point.cpp"

using namespace std;

const int scoreBishop = 3;

class Bishop : public ChessPiece{
public:
    Bishop() : ChessPiece(){}

    Bishop(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scoreBishop;
            ChessPiece::kindPiece = 'b';
        } 
        else{
            ChessPiece:: score = scoreBishop;
            ChessPiece::kindPiece = 'B';
        } 

        firstmove = true;
        for(auto i: default_location){ // Xem default_location tại dòng cuối file
            if(i == start){
                firstmove = false;
                break;
            }   
        }
    }

    vector<Point> validMove(bool my_turn = true) override{
        // Trả về một mảng các vị trí mà quân cờ có thể đi
        vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS};
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
const vector<string> Bishop:: default_location = {"c1B","f1B","c8b","f8b"};

#endif