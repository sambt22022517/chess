/*
Quân cờ: vị trí trên bảng, điểm số,trạng thái, cách di chuyển
*/
#ifndef CHESSPIECE
#define CHESSPIECE

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"

using namespace std;

/*
    quy ước: đầu vào của vị trí là string phải đầy đủ 3 kí tự
    vd: "a2P"...
*/


const char nullsquare = '.';

class ChessPiece{
protected:
    Point location;         // Vị trí trên bàn cờ
    int score;              // Điểm của quân cờ
    bool firstmove;         // kiểm tra đã đi nước đầu tiên hay chưa
    char kind;              // loại quân cờ trắng hay đen hay null
    char kindPiece;         // là quân cờ nào
    static vector<vector<ChessPiece*>> dataBoard; // mảng chứa dữ liệu của bàn cờ
    static bool isSetdataBoard; // kiểm tra xem đã tạo bàn cờ chưa (?)
public:
    ChessPiece(){}
    virtual ~ChessPiece(){}

    ChessPiece(char _kind, string start){
        kind = _kind;

        location = Point(start);
    }

    static ChessPiece* get_dataBoard(Point location) {
        // Lấy dữ liệu về một ô trên bàn cờ, có quân hay không, quân bên nào...
        return dataBoard[location.get_x()][location.get_y()];
    }

    static vector<vector<ChessPiece*>> get_Board() {
        // Trả về dữ liệu bàn cờ
        return dataBoard;
    }

    static void set_DataBoard(vector<vector<ChessPiece*>> _dataBoard){
        // Cài đặt bàn cờ nếu chưa cài đặt
        if(isSetdataBoard) return;

        dataBoard = _dataBoard;
        isSetdataBoard = true;
    }


    // trả về một chuỗi các điểm mà quân cờ có thể đi tới
    virtual vector<Point> validMove(bool my_turn = true){
        return {};
    }

    virtual bool move(string end, bool valid){
        // kiểm tra nước đi có hợp lệ ko, nếu ko trả về false
        // di chuyển quân cờ tới ô hợp lệ
        if (valid == false) return false;
        
        // Đánh dấu đã đi nước đầu tiên
        firstmove = true;
        Point pre_location = location;
        location = Point(end);

        // xóa quân cờ ở ô cần đến(nếu có)
        if(get_dataBoard(location) != nullptr){
            ChessPiece* c = dataBoard[location.get_x()][location.get_y()];
            dataBoard[location.get_x()][location.get_y()] = nullptr;
            delete(c);
        }
        
        // chuyển quân cờ từ ô cũ sang ô mới
        dataBoard[location.get_x()][location.get_y()] = dataBoard[pre_location.get_x()][pre_location.get_y()];

        // cho ô cũ là rỗng
        dataBoard[pre_location.get_x()][pre_location.get_y()] = nullptr;

        return true;
    }

    char get_kindPiece() const{
        return kindPiece;
    }

    char get_kind() const{
        return kind;
    }

    Point get_location() const{
        return location;
    }

    bool get_firstmove(){
        return firstmove;
    }

    int get_score(){
        return score;
    }
 
};

/*
thông tin bàn cờ: mọi cập nhật, lấy dữ liệu bàn cờ đều thông qua biến này
*/
vector<vector<ChessPiece*>> ChessPiece:: dataBoard = vector<vector<ChessPiece*>> (8, vector<ChessPiece*> (8, nullptr));
bool ChessPiece:: isSetdataBoard = false;

#endif