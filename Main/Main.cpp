#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"
#include "..\Board\Board.cpp"

using namespace std;

int main(){
    vector<string> data_Board = {
        "a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
        "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

        // "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
        // "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
        // "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
        // "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

        "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
        "a8r","b8n","c8b","d8q","e8k","f8b","g8n","h8r"
    };
    // ChessPiece::set_DataBoard(DataBoard(data_Board));
    // ChessPiece::get_dataBoard(Point("c8b"))->validMove();

    // ChessPiece::get_dataBoard(Point("c8b"))->move("d7b", true);
    vector<string> data_Board2 = {
        "a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
        "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

        // "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
        // "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
        // "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
        // "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

        "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
        "a8r"                  ,"e8k",            "h8r"
    };

    
    ChessPiece::set_DataBoard(DataBoard(data_Board));
    displayBoard();
    ChessPiece::get_dataBoard(Point("e8k"))->validMove();

    // ChessPiece::get_dataBoard(Point("e8k"))->getRR()->first.location();

    // Point p1("e8k");
    // Point p2 = p1 + Point::E + Point::E;
    // cout<< p1.location()<< " "<< p2.location();
    
    // ChessPiece::get_dataBoard(Point("e8k"))->move("g8kh8r", true);
    // ChessPiece::get_dataBoard(Point("e8k"))->move("g8kh8r", true);
    // ChessPiece::get_dataBoard(Point("h8r"))->move("f8", true);
    // cout<< ChessPiece::get_dataBoard(Point("h8r"))->get_firstmove();

    // ChessPiece::get_dataBoard(Point("c7p"))->move("c5p", true);
    // ChessPiece::get_dataBoard(Point("d2P"))->move("d4P", true);
    // ChessPiece::get_dataBoard(Point("c5p"))->move("d4P", true);

    ChessPiece::get_dataBoard(Point("e1K"))->move("e4K", true);

    displayBoard();
    // ChessPiece::get_dataBoard(Point("c5p"))->move("d4p", true);
    for(auto i: ChessPiece::get_dataBoard(Point("e4K"))->validMove()){
        cout<< i.location()<< " ";
    }

    // displayBoard();
}