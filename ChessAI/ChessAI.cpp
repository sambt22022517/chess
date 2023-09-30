#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\Board\Board.cpp"
#include "..\Utility\Point.cpp"
#include "..\Graphic\graphic.cpp"
#include <SFML/Graphics.hpp>
using namespace std;

class ChessAI {
	private:
		vector<vector<ChessPiece*>> *dataBoard;

	public:
		ChessAI(){}

		ChessAI(vector<vector<ChessPiece*>> *_dataBoard){
			this->dataBoard = _dataBoard;
		}

		int getBoardScore(){
			int score = 0;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){
					if ((*this->dataBoard)[i][j] != nullptr){
						std::cout << (*this->dataBoard)[i][j]->get_score() << ' ';
						score += (*this->dataBoard)[i][j]->get_score();
					}
				}
			}
			return score;
		}

		bool isLostKing(){
			int score = 0;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){
					if ((*this->dataBoard)[i][j] != nullptr and (*this->dataBoard)[i][j]->get_kindpiecestring() == "king"){
						score += 1;
					}
				}
			}
			return (score < 2);
		}

		pair<int, pair<string, string>> minimax(int alpha, int beta, int depth, char player){
			if (isLostKing()) {
				std::cout << this->getBoardScore();
				return {this->getBoardScore(), {"", ""}};
			}
			if (depth == 0) {
				

				for (int i = 0; i < 8; i += 1){
					for (int j = 0; j < 8; j += 1){
						std::cout << ((*this->dataBoard)[i][j] == nullptr ? '.' : (*this->dataBoard)[i][j]->get_kindPiece()) << ' ';
					}
					std::cout << std::endl;
				}

				return {this->getBoardScore(), {"", ""}};
			}

			int score = 2000;
			pair<string, string> move = {"", ""};
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){

					if ((*this->dataBoard)[i][j] != nullptr){

						if ((*this->dataBoard)[i][j]->get_kind() == player){

							(*this->dataBoard)[i][j]->calValidMove();
							vector<Point> validMove = (*this->dataBoard)[i][j]->get_valid_moves();

							ChessPiece * cp = (*this->dataBoard)[i][j];
							string current = Point(i, j).location();
							for (Point nextMove : validMove){

								cp->move(nextMove.location(), true);

								pair<int, pair<string, string>> data = minimax(alpha, beta, depth-1, player ^ 'W' ^ 'B');
								int nextScore = data.first;
								if (player == 'W'){
									if ((score == 2000) or (score != 2000 and score < nextScore)){
										score = nextScore;
										move = {current, nextMove.location()};
										// if (score > beta) return;
									}
								} else if (player == 'B'){
									if ((score == 2000) or (score != 2000 and score > nextScore)){
										score = nextScore;
										move = {current, nextMove.location()};
									}
								}

								cp->move(current, true);
							}
						}
					}
				}
			}
			return {score, move};
		}
};

int main(){

	vector<string> data_board2 = {
		"a1.", "b1.", "c1.", "d1.", "e1.", "f1.", "g1.", "h1.",
		"a2.", "b2.", "c2.", "d2.", "e2.", "f2.", "g2.", "h2.",

		"a3.", "b3.", "c3.", "d3.", "e3k", "f3.", "g3.", "h3.",
		"a4.", "b4.", "c4.", "d4.", "e4b", "f4.", "g4.", "h4.",
		"a5.", "b5.", "c5.", "d5K", "e5.", "f5R", "g5.", "h5.",
		"a6.", "b6.", "c6.", "d6.", "e6.", "f6.", "g6.", "h6.",

		"a7.", "b7.", "c7.", "d7.", "e7.", "f7.", "g7.", "h7.",
		"a8.", "b8.", "c8.", "d8.", "e8.", "f8.", "g8.", "h8."};

	 // = DataBoard(data_board2);
	ChessPiece::set_DataBoard(DataBoard(data_board2));
	vector<vector<ChessPiece*>> _dataBoard = ChessPiece::get_Board();
	vector<vector<ChessPiece*>> *dataBoard = &_dataBoard;
	ChessAI ca = ChessAI(dataBoard);
	pair<string, string> MOVE = ca.minimax(1, 1, 1, 'B').second;
	std::cout << MOVE.first << ' ' << MOVE.second;

// 	Point p = Point(MOVE.first);
// 	(*dataBoard)[p.get_x()][p.get_y()]->move(MOVE.second, true);

// for (int i = 0; i < 8; i += 1){
// 					for (int j = 0; j < 8; j += 1){
// 						std::cout << (ChessPiece::get_Board()[i][j] == nullptr ? '.' : ChessPiece::get_Board()[i][j]->get_kindPiece()) << ' ';
// 					}
// 					std::cout << std::endl;
// 				}
	return 0;
}