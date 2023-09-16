#ifndef BOARD
#define BOARD

#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"

using namespace std;

void displayBoard(){
    // In bàn cờ ra màn hình console
    // Đây là hàm tiền thân của hệ thống đồ hoạ (nếu có thời gian phát triển)

    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){

            if(ChessPiece::get_dataBoard(Point(i,j)) != nullptr) {
                cout << ChessPiece::get_dataBoard(Point(i,j))-> get_kindPiece() << " ";
            } else {
                cout << ". ";
            }

        }
        cout << endl;
    }
    cout << endl << endl;


    // for(auto i: ChessPiece::get_Board()){
    //     for(auto j: i){
    //         if(j != nullptr) cout << j -> get_kindPiece()<< " ";
    //         else cout << ". ";
    //     }
    //     cout << endl;
    // }
}

vector<vector<ChessPiece*>> DataBoard(vector<string> &_dataBoard){
    // Xây dựng bàn cờ từ một mảng các string đã có sẵn là _dataBoard
    // Mỗi phần tử trong _dataBoard là một string có dạng <cột><hàng><tên dạng quân cờ>
    // Ví dụ: a1R: Xe trắng ở vị trí hàng 1 cột a trên bàn cờ
    // Lưu ý: cột = {a, b, c, d, e, f, g, h}
    //        hàng = {1, 2, 3, 4, 5, 6, 7, 8}
    // Hàm trả về bàn cờ sau khi đã xây dựng xong

    vector<vector<ChessPiece*>> dataBoard;
    dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));

    for(string i: _dataBoard){
        Point p(i);
        dataBoard[p.get_x()][p.get_y()] = creatPiece(i);
    }
    return dataBoard;
}

#endif