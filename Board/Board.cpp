#ifndef BOARD
#define BOARD

#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"

using namespace std;

void displayBoard(){
    for(auto i: ChessPiece::get_Board()){
        for(auto j: i){
            if(j != nullptr) cout<< j -> get_kindPiece()<< " ";
            else cout<< ". ";
        }
        cout<< endl;
    }
}
vector<vector<ChessPiece*>> DataBoard(vector<string> &_dataBoard){
    vector<vector<ChessPiece*>> dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));
    for(auto i: _dataBoard){
        Point p(i);
        dataBoard[p.get_x()][p.get_y()] = creatPiece(i);
    }
    return dataBoard;
}

#endif