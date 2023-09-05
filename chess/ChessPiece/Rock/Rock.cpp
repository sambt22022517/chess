#ifndef ROCK
#define ROCK

#include <bits/stdc++.h>
#include "chess\Utility\Utility.cpp"
#include "chess\ChessPiece\ChessPiece.cpp"
#include "chess\ChessPiece\Black.cpp"
#include "chess\ChessPiece\White.cpp"
using namespace std;

class Rock : ChessPiece{

};

class BlackRock : Black, Rock{

};

class WhiteRock : White, Rock{

};

#endif