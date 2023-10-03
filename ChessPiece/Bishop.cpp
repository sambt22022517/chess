#ifndef BISHOP
#define BISHOP

#include <bits/stdc++.h>
#include "ChessPiece.cpp"
#include "..\Utility\Point.cpp"

using namespace std;

const int scoreBishop = 3;

class Bishop : public ChessPiece{
public:
public:
	Bishop() : ChessPiece(){
		
		pos_score = {
				{-2,-1,-1,-1,-1,-1,-1,-2},
				{-1,0.5,0,0,0,0,0.5,-1},
				{-1,1,1,1,1,1,1,-1},
				{-1,0,1,1,1,1,0,-1},
				{-1,0.5,0.5,1,1,0.5,0.5,-1},
				{-1,0,0.5,1,1,0.5,0,-1},
				{-1,0,0,0,0,0,0,-1},
				{-2,-1,-1,-1,-1,-1,-1,-2}
				};
	}

	Bishop(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scoreBishop;
			ChessPiece::kindPiece = 'b';
		} 
		else{
			ChessPiece:: score = scoreBishop;
			ChessPiece::kindPiece = 'B';
		} 

		firstmove = true;
		for(auto i: default_location){ // Xem default_location tại dòng cuối file
			if(i == start){
				firstmove = false;
				break;
			}   
		}
		pos_score = {
				{-2,-1,-1,-1,-1,-1,-1,-2},
				{-1,0.5,0,0,0,0,0.5,-1},
				{-1,1,1,1,1,1,1,-1},
				{-1,0,1,1,1,1,0,-1},
				{-1,0.5,0.5,1,1,0.5,0.5,-1},
				{-1,0,0.5,1,1,0.5,0,-1},
				{-1,0,0,0,0,0,0,-1},
				{-2,-1,-1,-1,-1,-1,-1,-2}
				};
	}

	void calValidMove(vector<ChessPiece*> checks = {}) override{
		// Xoá thông tin cũ trước khi tính toán
		this->validMoves.clear();
		this->checkMoves.clear();
		this->checkMoves.push_back(this->location);
		this->protectPoints.clear();
		bool getKing = false; // Kiểm tra xem có gặp vua hay chưa

		vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS};

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
	}

	string get_kindpiecestring() override{
		return "bishop";
	}

	const static vector<string> default_location;
};
const vector<string> Bishop:: default_location = {"c1B","f1B","c8b","f8b"};

#endif