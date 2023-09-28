#ifndef ROCK
#define ROCK

#include <bits/stdc++.h>
#include "..\Utility\Point.cpp"
#include "ChessPiece.cpp"

using namespace std;

const int scoreRock = 5;

class Rock : public ChessPiece{
public:
	Rock() : ChessPiece(){
		
	}
	Rock(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scoreRock;
			ChessPiece:: kindPiece = 'r';
		} 
		else{
			ChessPiece:: score = scoreRock;
			ChessPiece:: kindPiece = 'R';
		}
	}
	
	void calValidMove(vector<ChessPiece*> checks = {}) override {
		this->validMoves.clear();
		this->checkMoves.clear();
		this->checkMoves.push_back(this->location);
		this->protectPoints.clear();
		bool getKing = false;
		
		vector<Point> director = {Point::E, Point:: S, Point:: N, Point:: W};
		for(auto i: director){
			Point current = location;
			while((current + i).isValid()){
				ChessPiece* c = get_dataBoard(current + i);
				if(c == nullptr){
					this->validMoves.push_back(current + i);
					if (not getKing) this->checkMoves.push_back(current + i);

				} else {
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
		return "rock";
	}

	const static vector<string> default_location;
};
const vector<string> Rock:: default_location = {"a1R","h1R","a8r","h8r"};
#endif