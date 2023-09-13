#ifndef UTILITY
#define UTILITY

#include <bits/stdc++.h>

using namespace std;

// phương chiều gốc tọa độ của bàn cờ giống như hệ trục tọa độ đề các

class Point{
private:
    int i;
    int j;
    void charPoint(char i, char j){
        this -> i = j - '0' - 1;
        this -> j = i - 'a';
    }
public:
    Point(){

    }

    // tạo 1 point với 2 biến i, j là vị trí(số) trên bàn cờ
    Point(int i, int j){
        this -> i = i;
        this -> j = j;
    }

    // đầu vào là các kí tự trên bàn cờ, nếu hợp lệ thì ta sẽ có 1 point và được trả về true
    // nếu không sẽ trả về true
    // vd: point a;
    // a.point_char('a','1'): hợp lệ, ta sẽ có a.i = ...
    bool point_char(char i, char j){
        if(!(i >= 'a' && i <= 'h')) return false;
        if(!(j >= '1' && j <= '8')) return false;

        charPoint(i, j);
        return true;
    }

    // dùng hàm này để tạo 1 point với các kí tự
    static Point to_int(char i, char j){
        Point a;
        a.charPoint(i,j);
        return a;
    }

    int get_i(){
        return i;
    }

    int get_j(){
        return j;
    }

    char get_ci(){
        return j + 'a';
    }

    char get_cj(){
        return i + '0' + 1;
    }

    void print(){
        cout<< get_ci()<< " "<< get_cj();
    }

    // kiểm tra đầu vào có hợp lệ
    static bool checkValid(int i, int j){
        if(!(i >= 0 && i <= 7)) return false;
        if(!(j >= 0 && j <= 7)) return false;
        return true;
    }
    // so sánh 2 điểm, vector
    static bool compare(Point a, Point b){
        return a.i == b.i && a.j == b.j;
    }

    // dùng để cộng các vector
    static Point add(vector<Point> p){
        Point po(0,0);
        for(auto i: p){
            po.i += i.i;
            po.j += i.j;
        }
        return po;
    }
};

Point WN(1, -1), WS(-1, -1), EN(1, 1), ES(-1, 1);
Point W(0, -1), E(0, 1), N(1, 0), S(-1, 0); 
#endif