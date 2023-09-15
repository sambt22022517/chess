#ifndef KING
#define KING

#include <bits/stdc++.h>
#include "ChessPiece.cpp"
#include "..\Utility\Point.cpp"

using namespace std;

int scoreKing = 1e9;

class King : public ChessPiece{
private:
    string Lcastling;
    string Rcastling;
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

        firstmove = true;
        for(auto i: default_location){
            if(i == start){
                firstmove = false;
                break;
            }   
        }
        Lcastling = "";
        Rcastling = "";
    }

    vector<Point> validMove() override {  
        vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS, Point::E, Point:: S, Point:: N, Point:: W};
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

        if(firstmove == false){
            vector<Point> d = {Point::W, Point:: E};
            for(auto i: d){
                Point current = location;
                while((current + i).isValid()){
                    current = current + i;
                    if(!(current + i).isValid()){
                        if(get_dataBoard(current) != nullptr){
                            if(get_dataBoard(current) -> get_kind() == kind){
                                if(get_dataBoard(current) -> get_kindPiece() == 'R' || get_dataBoard(current) -> get_kindPiece() == 'r'){
                                    if(!get_dataBoard(current)->get_firstmove()){
                                        output.push_back(location + i + i);

                                        if(i == Point::W){
                                            Lcastling = (location + i + i).location() + kindPiece +
                                                        current.location() + get_dataBoard(current) -> get_kindPiece();
                                                        
                                        }else{
                                            Rcastling = (location + i + i).location() + kindPiece +
                                                        current.location() + get_dataBoard(current) -> get_kindPiece();
                                                        
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if(get_dataBoard(current) != nullptr) break;
                }
            }
        }
        return output;
    }

    bool move(string end, bool valid) override{
        
        ChessPiece:: move(end, valid);

        if(Lcastling != ""){
            if(Point(end) == Point(Lcastling)){
                if(end.substr(3,3) != "" && end.substr(0,3) != "")
                get_dataBoard(end.substr(3,3))->move((Point(end.substr(0,3)) + Point::E).location(), true);
                else return false;
            }
        }
        if(Rcastling != ""){
            if(Point(end) == Point(Rcastling)){
                if(end.substr(3,3) != "" && end.substr(0,3) != "")
                get_dataBoard(end.substr(3,3))->move((Point(end.substr(0,3)) + Point::W).location(), true);
                else return false;
            }
        }

        return true;
    }

    const static vector<string> default_location;
};
const vector<string> King:: default_location = {"e1K","e8k"};

#endif