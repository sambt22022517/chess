#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "..\Board\Board.cpp"
#include "..\ChessPiece\Pawn.cpp"

using namespace std;

int main(){
    Board b;
    b.selfSetup_Board({"c1B","f4r"});
    b.displayBoard();

    // for(auto i: dataBoard[0][2]->validMove()){
    //     i.print();
    //     cout<< endl;
    // }
    cout<< endl;
    dataBoard[0][2]->move("e3");

    b.displayBoard();
    
    // ChessPiece* c = creatPiece("a2P");// c tự động cập nhật nó là tốt trắng
    // for(auto i: c -> validMove()){
    //     i.print();
    //     cout<<" ";
    // }

    
}