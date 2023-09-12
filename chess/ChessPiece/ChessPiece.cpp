/*
Quân cờ: vị trí trên bảng, điểm số,trạng thái, cách di chuyển
*/
#ifndef CHESSPIECE
#define CHESSPIECE

#include <bits/stdc++.h>
#include "..\Utility\Utility.cpp"
using namespace std;

/*
thông tin bàn cờ: mọi cập nhật, lấy dữ liệu bàn cờ đều thông qua biến này
*/

const char nullsquare = '.';

class ChessPiece{
protected:
    Point corrdinate;// vị trí trên bàn cờ
    int score;// diểm của quân cờ
    bool firstmove;// kiểm tra đã đi nước đầu tiên hay chưa
    char kind;// loại quân cờ trắng hay đen hay null
    char kindPiece;//là quân cờ nào
public:
    ChessPiece(){
        
    }

    ChessPiece(char kind, string start){
        this -> kind = kind;

        firstmove = false;

        corrdinate = Point::to_int(start[0], start[1]);
    }

    virtual vector<Point> validMove(){
        // trả về một chuỗi các điểm mà quân cờ có thể đi tới
        return {Point(7,7)};
    }

    virtual bool move(string end){
        // kiểm tra nước đi có hợp lệ ko, nếu ko trả về false
        // di chuyển quân cờ tới ô hợp lệ

        return end != "";
    }

    char getkindPiece(){
        return kindPiece;
    }

    char getkind(){
        return kind;
    }

    Point getCorrdinate(){
        return corrdinate;
    }
};

/*
thông tin bàn cờ: mọi cập nhật, lấy dữ liệu bàn cờ đều thông qua biến này
*/
vector<vector<ChessPiece*>> dataBoard;
#endif