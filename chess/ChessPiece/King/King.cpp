#ifndef KING
#define KING

#include <bits/stdc++.h>
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class King : ChessPiece{

};

class BlackKing : King, Black{

};

class WhiteKing : King, White{

};

#endif