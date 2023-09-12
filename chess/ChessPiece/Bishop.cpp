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
            Point current = corrdinate;
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

    bool move(string end) override{
        for(auto i: validMove()){
            if(Point::compare(i, Point::to_int(end[0], end[1]))){
                firstmove = true;
                Point old_corrdinate = corrdinate;
                corrdinate = Point::to_int(end[0], end[1]);

                // xóa quân cờ ở ô cần đến(nếu có)
                if(dataBoard[corrdinate.get_i()][corrdinate.get_j()] != nullptr){
                    // delete(dataBoard[corrdinate.get_i()][corrdinate.get_j()]);
                }
                
                // chuyển quân cờ từ ô cũ sang ô mới
                dataBoard[corrdinate.get_i()][corrdinate.get_j()] = dataBoard[old_corrdinate.get_i()][old_corrdinate.get_j()];

                // cho ô cũ là rỗng
                dataBoard[old_corrdinate.get_i()][old_corrdinate.get_j()] = nullptr;
                
            }
        }
        return false;
    }
};


#endif