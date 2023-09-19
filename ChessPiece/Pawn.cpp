#ifndef PAWN
#define PAWN

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"
#include "Queen.cpp"

using namespace std;

const int scorePawn = 1;

class Pawn : public ChessPiece{
public:
    Pawn() : ChessPiece(){
        
    }
    Pawn(char kind, string start) : ChessPiece(kind, start){
        if(kind == 'B'){
            ChessPiece:: score = -scorePawn;
            ChessPiece:: kindPiece = 'p';
        } 
        else{
            ChessPiece:: score = scorePawn;
            ChessPiece:: kindPiece = 'P';
        }
    }
    
    vector<Point> validMove() override{
        Point N, WN, EN;
        if(kind == 'W'){
            N = Point:: N;
            WN = Point:: WN;
            EN = Point:: EN;
        }else{
            N = Point:: S;
            WN = Point:: WS;
            EN = Point:: ES;
        }

        vector<Point> output;
        Point current = location;
        
        if((current + N).isValid() and get_dataBoard(current + N) == nullptr){
            output.push_back(current + N);
        }
        
        if((current + N + N).isValid() and !firstmove && get_dataBoard(current + N + N) == nullptr && get_dataBoard(current + N) == nullptr){
            output.push_back(current + N + N);
        }

        vector<Point> d = {WN, EN};
        for(auto i: d){
            if((current + i).isValid() and get_dataBoard(current + i) != nullptr){
                if(get_dataBoard(current + i)->get_kind() != kind){
                    output.push_back(current + i);
                }
            }
        }

        // bắt tốt qua đường

        // phong quân:
        

        return output;
    }
    bool move(string end, bool valid) override{
        // cout<< "hi";
        ChessPiece:: move(end, valid);
        // cout<< "hello";
        Point N, WN, EN;
        if(kind == 'W'){
            N = Point:: N;
            WN = Point:: WN;
            EN = Point:: EN;
        }else{
            N = Point:: S;
            WN = Point:: WS;
            EN = Point:: ES;
        }
        Point current = location;

        if(!(current + N).isValid()){
            int x = Point(location).get_x(), y = Point(location).get_y();
            char _kind = kind;

            delete(dataBoard[x][y]);

            dataBoard[x][y] = new Queen(_kind, Point(x, y).location());
        }
        return true;
    }
    const static vector<string> default_location;
};

const vector<string> Pawn:: default_location = {
    "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",
    "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p"
};
#endif