#ifndef PAWN
#define PAWN

#include <bits/stdc++.h>
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class Pawn : ChessPiece{

};

class BlackPawn : Black, Pawn{

};

class WhitePawn : White, Pawn{

};

#endif