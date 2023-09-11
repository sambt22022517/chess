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

    Point(int i, int j){
        this -> i = i;
        this -> j = j;
    }

    bool point_char(char i, char j){
        if(!(i >= 'a' && i <= 'h')) return false;
        if(!(j >= '1' && j <= '8')) return false;

        charPoint(i, j);
        return true;
    }

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
};

#endif