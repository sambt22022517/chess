#ifndef KING
#define KING

#include <bits/stdc++.h>
#include "ChessPiece.cpp"
#include "..\Utility\Point.cpp"

using namespace std;

const int scoreKing = 1000;

class King : public ChessPiece{
private:
	string Lcastling; // Nhập thành trái
	string Rcastling; // Nhập thành phải
public:
	King() : ChessPiece(){
		
	}
	King(char kind, string start) : ChessPiece(kind, start){
		if(kind == 'B'){
			ChessPiece:: score = -scoreKing;
			ChessPiece:: kindPiece = 'k';
		} 
		else{
			ChessPiece:: score = scoreKing;
			ChessPiece:: kindPiece = 'K';
		}

		firstmove = true;
		for(auto i: default_location){ // Xem default_location tại dòng cuối file
			if(i == start){
				firstmove = false;
				break;
			}   
		}
		Lcastling = "";
		Rcastling = "";
	}

	void calValidMove(vector<ChessPiece*> checks = {}) override {
		this->validMoves.clear();
		this->protectPoints.clear();

		vector<Point> director = {Point::EN, Point::ES, Point::WN, Point::WS, Point::E, Point:: S, Point:: N, Point:: W};
		Point current = location;
		for(auto i: director){
			if ((current + i).isValid()){
				ChessPiece* c = get_dataBoard(current + i);
				if(c == nullptr){
					this->validMoves.push_back(current + i);
				} else {
					if (c->get_kind() != kind) {
						this->validMoves.push_back(current + i);
					} else {
						this->protectPoints.push_back(current + i);
					}
				}
			}
		}

		// Làm gì đó để xử lí nhập thành
		if(firstmove == false){//vua chưa đi nước đầu 
			vector<Point> d = {Point::W, Point:: E};
			for(auto i: d){
				Point current = location;
				while((current + i).isValid()){//chạy cho đến khi gặp cột ở biên
					current = current + i;
					if(!(current + i).isValid()){//ô ở ngoài cùng
						if(get_dataBoard(current) != nullptr){//ô không rỗng
							if(get_dataBoard(current) -> get_kind() == kind){//quân cờ ở ô này cùng loại với vua
								if(get_dataBoard(current) -> get_kindPiece() == 'R' || get_dataBoard(current) -> get_kindPiece() == 'r'){//quân này là quân xe
									if(!get_dataBoard(current)->get_firstmove()){//quân xe này chưa đi nước đầu tiên
										this->validMoves.push_back(location + i + i);

										if(i == Point::W){//nhập thành về bên trái
											Lcastling = (location + i + i).location() + kindPiece +
														current.location() + get_dataBoard(current) -> get_kindPiece();
														
										}else{//nhập thành về bên phải
											Rcastling = (location + i + i).location() + kindPiece +
														current.location() + get_dataBoard(current) -> get_kindPiece();
														
										}
									}
								}
							}
						}
					}

					if(get_dataBoard(current) != nullptr) break;
				}
			}
		}

		// Nếu đang là lượt đi của mình thì phải kiểm tra để
		// loại bỏ những nước đi của vua mà nếu đi vào sẽ chết ngay
		std::vector<Point> not_valid_moves;
		for (int i = 0; i < 8; i += 1){
			for (int j = 0; j < 8; j += 1){
				ChessPiece * cp = ChessPiece::get_dataBoard(Point(i, j));
				if (cp != nullptr and cp->get_kind() != this->kind){
					if (cp->get_kindpiecestring() != "king"){
						if (cp->get_kindpiecestring() != "pawn"){
							for (Point p : cp->get_valid_moves()){
								not_valid_moves.push_back(p);
							}
						}
						for (Point p : cp->get_protect_point()){
							not_valid_moves.push_back(p);
						}
						vector<Point> checks = cp->get_check_moves();
						for (int i = 1; i < (int)checks.size(); i += 1){
							not_valid_moves.push_back(checks[i]);
						}
					} else {
						Point p = Point(i, j);
						not_valid_moves.push_back(p + Point::EN);
						not_valid_moves.push_back(p + Point::ES);
						not_valid_moves.push_back(p + Point::WN);
						not_valid_moves.push_back(p + Point::WS);
						not_valid_moves.push_back(p + Point::W);
						not_valid_moves.push_back(p + Point::N);
						not_valid_moves.push_back(p + Point::S);
						not_valid_moves.push_back(p + Point::E);
					}
				}
			}
		}
		for (int i = this->validMoves.size()-1; i > -1; i -= 1){
			for (Point nvm : not_valid_moves){
				if (this->validMoves[i] == nvm){
					this->validMoves.erase(this->validMoves.begin() + i);
					break;
				}
			}
		}

	}

	ChessPiece* move(string end, bool valid) override {
		if (not valid) return nullptr;
		
		ChessPiece* c = ChessPiece:: move(end, valid);

		if(Lcastling != ""){
			if(Point(end) == Point(Lcastling)){
				get_dataBoard(Point(Lcastling.substr(3,3)))->move((Point(Lcastling.substr(0,3)) + Point::E).location(), true);
			} else {
				return nullptr;
			}
		}

		if(Rcastling != ""){
			if(Point(end) == Point(Rcastling)){
				get_dataBoard(Point(Rcastling.substr(3,3)))->move((Point(Rcastling.substr(0,3)) + Point::W).location(), true);
			} else {
				return nullptr;
			}
		}

		return c;
	}

	string get_kindpiecestring() override{
		return "king";
	}

	const static vector<string> default_location;
};
const vector<string> King:: default_location = {"e1K","e8k"};

#endif