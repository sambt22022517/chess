#ifndef BOARD
#define BOARD

#include <bits/stdc++.h>
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\ChessPiece\Piece.cpp"

using namespace std;

class Board{
private:
    vector<ChessPiece> chessPiece;
    /*
    thông tin bàn cờ: mọi cập nhật, lấy dữ liệu bàn cờ đều thông qua biến này
    */
    vector<vector<ChessPiece*>> dataBoard;
public:
    Board(){

    }
    void setup_board(){
        vector<string> start = {
            "a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
            "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

            // "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
            // "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
            // "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
            // "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

            "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
            "a8r","b8n","c8b","d8q","e8k","f8b","g8n","h8r"
        };
        dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));

        for(auto i: start){
            Point a;
            a.point_char(i[0],i[1]);
            dataBoard[a.get_i()][a.get_j()] = creatPiece(i);
        }
        ChessPiece::set_DataBoard(dataBoard);
        chessPiece = {};

    }

    void selfSetup_Board(vector<string> start){
        dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));

        for(auto i: start){
            Point a;
            a.point_char(i[0],i[1]);
            dataBoard[a.get_i()][a.get_j()] = creatPiece(i);
        }
        ChessPiece::set_DataBoard(dataBoard);
    }
    
    void displayBoard(){
        for(auto i: ChessPiece::get_Board()){
            for(auto j: i){
                if(j != nullptr) cout<< j -> getkindPiece()<< " ";
                else cout<< ". ";
            }
            cout<< endl;
        }
    }

    ChessPiece* get_dataBoard(int i, int j){
        return ChessPiece::get_dataBoard(i,j);
    }

};

#endif