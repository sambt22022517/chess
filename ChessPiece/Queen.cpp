#ifndef QUEEN
#define QUEEN

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"

using namespace std;

const int scoreQueen = 9;

class Queen : public ChessPiece{
public:
	Queen() : ChessPiece(){
		
	}
	Queen(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scoreQueen;
			ChessPiece:: kindPiece = 'q';
		} 
		else{
			ChessPiece:: score = scoreQueen;
			ChessPiece:: kindPiece = 'Q';
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
		
		vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS, Point::E, Point:: S, Point:: N, Point:: W};

		for(auto i: director){
			Point current = location;
			while((current + i).isValid()){
				ChessPiece* c = get_dataBoard(current + i);
				
				if(c == nullptr){
					this->validMoves.push_back(current + i);
					if (not getKing) this->checkMoves.push_back(current + i);

				}else{
					if(c->get_kind() != kind){
						this->validMoves.push_back(current + i);

						if (c->get_kindpiecestring() == "king"){
							this->checkMoves.push_back(current + i);
							if ((current + i + i).isValid() and get_dataBoard(current + i + i) == nullptr){
								this->checkMoves.push_back(current + i + i);
							}
							getKing = true;
						}
					} else {
						this->protectPoints.push_back(current + i);
					}
					break;
				}
				current = current + i;
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
		return "queen";
	}

	const static vector<string> default_location;
};
const vector<string> Queen:: default_location = {"d1Q", "d8q"};

#endif