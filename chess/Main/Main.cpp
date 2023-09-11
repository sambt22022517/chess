#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "..\Board\Board.cpp"
#include "..\ChessPiece\Pawn.cpp"

using namespace std;

int main(){
    // char i = 'a';
    // char j = '2';

    // Point a = Point::to_int(i, j);

    // cout<< a.get_i()<< " "<< a.get_j();
    Board b;
    b.setup_board();
    b.displayBoard();

    // ChessPiece c;
    // string start = "a2P";
    // c = creatPiece(start);
    // c.getCorrdinate().print();
    // cout<< " "<<c.getkindPiece();

    // vector<string> start = {
    //     "a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
    //     "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

    //     "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
    //     "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
    //     "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
    //     "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

    //     "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
    //     "a8r","b8n","c8b","d8q","e8k","f8b","g8n","h8r"
    // };
    // for(auto i: start){
    //     ChessPiece* c = creatPiece(i);
    //     c -> getCorrdinate().print();
    //     cout<< " "<<c -> getkindPiece()<< endl;
    // }

    // ChessPiece* c = creatPiece("a2P");
    // for(auto i: c -> validMove()){
    //     i.print();
    //     cout<<" ";
    // }
// Point a;
    // a.point_char('a', '2');
    // cout<< a.get_i()<< " "<< a.get_j();

    // dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));
    // cout<< dataBoard[7][7];
}