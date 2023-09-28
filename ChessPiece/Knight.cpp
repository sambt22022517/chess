#ifndef KNIGHT
#define KNIGHT

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"

using namespace std;

const int scoreKnight = 3;

class Knight : public ChessPiece{
public:
	Knight() : ChessPiece(){
		
	}
	Knight(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scoreKnight;
			ChessPiece:: kindPiece = 'n';
		} 
		else {
			ChessPiece:: score = scoreKnight;
			ChessPiece:: kindPiece = 'N';
		}

		firstmove = true;
		for(auto i: default_location){
			if(i == start){
				firstmove = false;
				break;
			}   
		}
	}

	void calValidMove(vector<ChessPiece*> checks = {}) override {
		this->validMoves.clear();
		this->checkMoves.clear();
		this->checkMoves.push_back(this->location);
		this->protectPoints.clear();
		bool getKing = false;

		vector<Point> director = {Point(2, 1), Point(1, 2), 
								  Point(2, -1), Point(1, -2), 
								  Point(-2, 1), Point(-1, 2), 
								  Point(-2, -1), Point(-1, -2)};

		Point current = location;
		for(auto i: director){
			if ((current + i).isValid()){
				ChessPiece* c = get_dataBoard(current + i);
				if(c == nullptr){
					this->validMoves.push_back(current + i);
					if (not getKing) this->checkMoves.push_back(current + i);
				} else {
					if (c->get_kind() != kind) {
						this->validMoves.push_back(current + i);

						if (c->get_kindpiecestring() == "king"){
							this->checkMoves.push_back(current + i);
							getKing = true;
						}
					} else {
						this->protectPoints.push_back(current + i);
					}
				}
			}

			if (not getKing) {
				this->checkMoves.clear();
				this->checkMoves.push_back(this->location);
			}
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
	}

	string get_kindpiecestring() override{
		return "knight";
	}

	const static vector<string> default_location;
};
const vector<string> Knight:: default_location = {"b1N","g1N","b8n","g8n"};


#endif