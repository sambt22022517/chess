#ifndef KNIGHT
#define KNIGHT

#include <bits/stdc++.h>
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class Knight : ChessPiece{

};

class BlackKnight : Knight, Black{

};

class WhiteKnight : Knight, White{

};

#endif