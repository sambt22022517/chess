#ifndef BISHOP
#define BISHOP

#include <bits/stdc++.h>
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class Bishop : ChessPiece{

};

class BlackBishop : Bishop, Black{

};

class WhiteBishop : Bishop, White{

};

#endif