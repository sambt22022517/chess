#ifndef QUEEN
#define QUEEN

#include <bits/stdc++.h>
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class Queen : ChessPiece{

};

class BlackQueen : Black, Queen{
    
};

class WhiteQueen : White, Queen{
    
};
#endif