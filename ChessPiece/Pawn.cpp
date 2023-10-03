#ifndef PAWN
#define PAWN

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"
#include "Queen.cpp"

using namespace std;

const int scorePawn = 1;

class Pawn : public ChessPiece{
public:

	Pawn() : ChessPiece(){
		pos_score = {
		{0,0,0,0,0,0,0,0},
		{0.5,1,1,-2,-2,1,1,0.5},
		{0.5,-0.5,-1.0,0,0,-1,-0.5,0.5},
		{0,0,0,2,2,0,0,0},
		{0.5,0.5,1,2.5,2.5,1,0.5,0.5},
		{1,1,2,3,3,2,1,1},
		{5,5,5,5,5,5,5,5},
		{0,0,0,0,0,0,0,0}
	};
	}
	Pawn(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scorePawn;
			ChessPiece:: kindPiece = 'p';
		} 
		else{
			ChessPiece:: score = scorePawn;
			ChessPiece:: kindPiece = 'P';
		}
		pos_score = {
		{0,0,0,0,0,0,0,0},
		{0.5,1,1,-2,-2,1,1,0.5},
		{0.5,-0.5,-1.0,0,0,-1,-0.5,0.5},
		{0,0,0,2,2,0,0,0},
		{0.5,0.5,1,2.5,2.5,1,0.5,0.5},
		{1,1,2,3,3,2,1,1},
		{5,5,5,5,5,5,5,5},
		{0,0,0,0,0,0,0,0}
	};
	}
	
	void calValidMove(vector<ChessPiece*> checks = {}) override{
		// Xoá thông tin cũ trước khi tính
		this->validMoves.clear();
		this->checkMoves.clear();
		this->checkMoves.push_back(this->location);
		this->protectPoints.clear();
		bool getKing = false;

		Point N, WN, EN;
		if(kind == 'W'){
			N = Point:: N;
			WN = Point:: WN;
			EN = Point:: EN;
		}else{
			N = Point:: S;
			WN = Point:: WS;
			EN = Point:: ES;
		}

		Point current = location;
		
		if((current + N).isValid() and get_dataBoard(current + N) == nullptr){
			this->validMoves.push_back(current + N);
		}
		
		if((current + N + N).isValid() and !firstmove && get_dataBoard(current + N + N) == nullptr && get_dataBoard(current + N) == nullptr){
			this->validMoves.push_back(current + N + N);
		}

		vector<Point> d = {WN, EN};
		for(auto i: d){
			if((current + i).isValid()){
				this->protectPoints.push_back(current + i);
				if (get_dataBoard(current + i) != nullptr){
					ChessPiece * c = get_dataBoard(current + i);
					if(c->get_kind() != kind){
						this->validMoves.push_back(current + i);

						if (c->get_kindpiecestring() == "king"){
							this->checkMoves.push_back(current + i);
							getKing = true;
						}
					}
				}
			}

			if (not getKing) {
				this->checkMoves.clear();
				this->checkMoves.push_back(this->location);
			}
		}

		if (not getKing) {
			this->checkMoves.clear();
		}

		if (checks.size() == 2){
			this->validMoves.clear();
		} else if (checks.size() == 1){
			vector<Point> temp;
			vector<Point> check = checks[0]->get_check_moves();

			for (Point i : this->validMoves){
				for (Point j : check){
					if (i == j) {
						temp.push_back(i);
					}
				}
			}

			this->validMoves.clear();
			this->validMoves = temp;
		}

		// bắt tốt qua đường

		// phong quân:
		

	}
	
	ChessPiece* move(string end, bool valid) override{
		if (not valid) return nullptr;
		ChessPiece* c = ChessPiece:: move(end, valid);
		Point N, WN, EN;
		if(kind == 'W'){
			N = Point:: N;
			WN = Point:: WN;
			EN = Point:: EN;
		}else{
			N = Point:: S;
			WN = Point:: WS;
			EN = Point:: ES;
		}
		Point current = location;

		if(!(current + N).isValid()){
			int x = Point(location).get_x(), y = Point(location).get_y();
			char _kind = kind;

			delete(dataBoard[x][y]);

			dataBoard[x][y] = new Queen(_kind, Point(x, y).location());
		}
		return c;
	}

	string get_kindpiecestring() override{
		return "pawn";
	}

	const static vector<string> default_location;
};

const vector<string> Pawn:: default_location = {
	"a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",
	"a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p"
};
#endif