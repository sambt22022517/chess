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
    Point coordinate;// vị trí trên bàn cờ
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

        coordinate = Point::to_int(start[0], start[1]);
    }

    virtual vector<Point> validMove(){
        // trả về một chuỗi các điểm mà quân cờ có thể đi tới
        return {Point(7,7)};
    }

    bool move(string end){
        // kiểm tra nước đi có hợp lệ ko, nếu ko trả về false
        // di chuyển quân cờ tới ô hợp lệ
        
        for(auto i: validMove()){
            if(Point::compare(i, Point::to_int(end[0], end[1]))){
                firstmove = true;
                Point old_coordinate = coordinate;
                coordinate = Point::to_int(end[0], end[1]);

                // xóa quân cờ ở ô cần đến(nếu có)
                if(dataBoard[coordinate.get_i()][coordinate.get_j()] != nullptr){
                    ChessPiece* c = dataBoard[coordinate.get_i()][coordinate.get_j()];
                    dataBoard[coordinate.get_i()][coordinate.get_j()] = nullptr;
                    delete(c);
                }
                
                // chuyển quân cờ từ ô cũ sang ô mới
                dataBoard[coordinate.get_i()][coordinate.get_j()] = dataBoard[old_coordinate.get_i()][old_coordinate.get_j()];

                // cho ô cũ là rỗng
                dataBoard[old_coordinate.get_i()][old_coordinate.get_j()] = nullptr;
            }
        }
        return false;

        // return end != "";
    }

    char getkindPiece(){
        return kindPiece;
    }

    char getkind(){
        return kind;
    }

    Point getcoordinate(){
        return coordinate;
    }
};

/*
thông tin bàn cờ: mọi cập nhật, lấy dữ liệu bàn cờ đều thông qua biến này
*/
vector<vector<ChessPiece*>> dataBoard;
#endif