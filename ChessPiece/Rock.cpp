#ifndef ROCK
#define ROCK

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"

using namespace std;

const int scoreRock = 5;

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
    
    vector<Point> validMove(bool my_turn = true) override {  
        vector<Point> director = {Point::E, Point:: S, Point:: N, Point:: W};
        vector<Point> output;
        for(auto i: director){
            Point current = location;
            while((current + i).isValid()){
                ChessPiece* c = get_dataBoard(current + i);
                if(c == nullptr){
                    output.push_back(current + i);

                } else {
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
    string get_kindpiecestring() override{
        return "rock";
    }
    const static vector<string> default_location;
};
const vector<string> Rock:: default_location = {"a1R","h1R","a8r","h8r"};
#endif