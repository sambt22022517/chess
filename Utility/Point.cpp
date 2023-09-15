#ifndef POINT
#define POINT

#include <bits/stdc++.h>

using namespace std;

/*
    phương chiều gốc tọa độ của bàn cờ giống như hệ trục tọa độ đề các
*/

class Point{
private:
    int x;
    int y;
public:
    Point(){}
    
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }

    Point(string location){
        x = location[1] - '0' - 1;
        y = location[0] - 'a';
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
    
    string location(){
        return string({(char)(y + 'a'), (char)(x + '0' + 1)});
    }

    // check valid for chess
    bool isValid(){
        if(!(x >= 0 && x <= 7)) return false;
        if(!(y >= 0 && y <= 7)) return false;
        return true;
    }

    Point operator+(const Point &other) const{
        return Point(x + other.x, y + other.y);
    }

    int get_x() {return x;}

    int get_y() {return y;}

    static const Point WN, WS, EN, ES;
    static const Point W, E, N, S;
};
const Point Point:: WN(1, -1), Point::WS(-1, -1), Point::EN(1, 1), Point::ES(-1, 1);
const Point Point::W(0, -1), Point::E(0, 1), Point::N(1, 0), Point::S(-1, 0);

#endif