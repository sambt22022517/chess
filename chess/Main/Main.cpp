#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
#include "..\Board\Board.cpp"
#include "..\ChessPiece\Pawn.cpp"

using namespace std;

int main(){
    Board b;
    b.setup_board();
    b.displayBoard();

    
    ChessPiece* c = creatPiece("a2P");// c tự động cập nhật nó là tốt trắng
    for(auto i: c -> validMove()){
        i.print();
        cout<<" ";
    }
}