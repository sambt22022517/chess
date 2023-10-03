#ifndef CHESSAI
#define CHESSAI

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

	public:
		ChessAI(){}

		double getBoardScore(){
			double score = 0;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){
					if (ChessPiece::get_Board()[i][j] != nullptr){
						int c = ChessPiece::get_Board()[i][j]->get_score();
						char k = ChessPiece::get_Board()[i][j]->get_kind();
						int row = (k == 'W' ? i : 7-i);
						score += (c + c/abs(c)*ChessPiece::get_Board()[i][j]->pos_score[row][j]);
					}
				}
			}
			return score;
		}

		bool isLossKing(){
			int score = 0;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){
					ChessPiece * cp = ChessPiece::get_Board()[i][j];
					if (cp != nullptr and cp->get_kindpiecestring() == "king"){
						score += 1;
					}
				}
			}
			return score < 2;
		}

		bool isCheckMate(char player){
			int a = 0;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){
					ChessPiece * cp = ChessPiece::get_Board()[i][j];
					if (cp != nullptr){
						if (cp->get_kind() == player){
							cp->calValidMove();
							if (cp->get_valid_moves().size() > 0){
								a += 1;
							}
						}
					}
				}
			}
			return (a == 0 ? true : false);
		}

		pair<ChessPiece*, ChessPiece*> isChecking(char kind){
			bool test = true;
			ChessPiece *check1 = NULL, *check2 = NULL;
			for (int i = 0; i < 8 and test; i += 1)
			{
				for (int j = 0; j < 8 and test; j += 1)
				{
					ChessPiece *op = ChessPiece::get_dataBoard(Point(i, j)); // opponent
					if (op != nullptr and op->get_kind() != kind)
					{
						op->calValidMove();
						if (op->get_check_moves().size() > 0)
						{
							if (not check1)
								check1 = op;
							else
							{
								check2 = op;
								test = false;
							}
						}
					}
				}
			}
			return {check1, check2};
		}

		pair<pair<double, int>, pair<string, string>> minimax(int _alpha, int _beta, int depth, char player, string prev){
			if (depth == -1) {
				return {{this->getBoardScore(), depth}, {"", ""}};
			}

			int alpha = _alpha;
			int beta = _beta;


			bool checkMate = true;

			int score = 2000;
			pair<string, string> MOVE = {"", ""};
			int max_depth = -1;
			for (int i = 0; i < 8; i += 1){
				for (int j = 0; j < 8; j += 1){

					if (ChessPiece::get_Board()[i][j] != nullptr){

						if (ChessPiece::get_Board()[i][j]->get_kind() == player){
							ChessPiece * cp = ChessPiece::get_Board()[i][j];


							pair<ChessPiece*, ChessPiece*> checks = this->isChecking(cp->get_kind());
							ChessPiece * check1 = checks.first;
							ChessPiece * check2 = checks.second;


							if (check2)
								cp->calValidMove({check1, check2});
							else if (check1)
								cp->calValidMove({check1});
							else
								cp->calValidMove();
							vector<Point> validMove = cp->get_valid_moves();

							string current = Point(i, j).location();
							for (Point nextMove : validMove){
								checkMate = false;

								if (current == prev.substr(0, 2) and nextMove.location() == prev.substr(2, 2)) continue;

								ChessPiece * oldPiece = cp->move(nextMove.location(), true);

								pair<pair<double, int>, pair<string, string>> data = minimax(alpha, beta, depth-1, player ^ 'W' ^ 'B', current+nextMove.location());
								double nextScore = data.first.first;
								int DEPTH = data.first.second;

								if (player == 'W'){
									if ((score == 2000) or (score <= nextScore and max_depth < DEPTH)){
										score = nextScore;
										MOVE = {current, nextMove.location()};
										max_depth = DEPTH;

										if (score > beta){
											cp->move(current, true);
											ChessPiece::dataBoard[nextMove.get_x()][nextMove.get_y()] = oldPiece;
											return {{score, max_depth}, MOVE};
										}
										alpha = max(score, alpha);
									}
								} else if (player == 'B'){
									if ((score == 2000) or (score >= nextScore and max_depth < DEPTH)){
										score = nextScore;
										MOVE = {current, nextMove.location()};
										max_depth = DEPTH;

										if (score < alpha) {
											cp->move(current, true);
											ChessPiece::dataBoard[nextMove.get_x()][nextMove.get_y()] = oldPiece;
											return {{score, max_depth}, MOVE};
										}
										beta = min(score, beta);
									}
								}

								cp->move(current, true);
								ChessPiece::dataBoard[nextMove.get_x()][nextMove.get_y()] = oldPiece;
							}
						}
					}
				}
			}

			// std::cout << player;
			if (checkMate){
				int minus = (player == 'W' ? -20000 : 20000);
				// std::cout << depth;
				return {{minus, depth}, {"", ""}};
			}
			return {{score, max_depth}, MOVE};
		}
};

// int main(){

// 	vector<string> data_board2 = {
// 		"a1.", "b1.", "c1.", "d1.", "e1K", "f1.", "g1.", "h1.",
// 		"a2.", "b2r", "c2.", "d2.", "e2.", "f2.", "g2.", "h2.",

// 		"a3.", "b3.", "c3.", "d3.", "e3k", "f3.", "g3.", "h3.",
// 		"a4.", "b4.", "c4.", "d4.", "e4.", "f4.", "g4.", "h4.",
// 		"a5.", "b5.", "c5.", "d5.", "e5.", "f5.", "g5.", "h5.",
// 		"a6.", "b6.", "c6.", "d6.", "e6.", "f6.", "g6.", "h6.",

// 		"a7.", "b7.", "c7.", "d7.", "e7.", "f7.", "g7.", "h7.",
// 		"a8.", "b8.", "c8.", "d8.", "e8.", "f8.", "g8.", "h8."};

// 	 // = DataBoard(data_board2);
// 	ChessPiece::set_DataBoard(DataBoard(data_board2));



// 	for (int i = 0; i < 8; i += 1){
// 		for (int j = 0; j < 8; j += 1){
// 			std::cout << (ChessPiece::get_Board()[i][j] == nullptr ? '.' : ChessPiece::get_Board()[i][j]->get_kindPiece()) << ' ';
// 		}
// 		std::cout << std::endl;
// 	}

// 	vector<vector<ChessPiece*>> _dataBoard = ChessPiece::get_Board();
// 	vector<vector<ChessPiece*>> *dataBoard = &_dataBoard;
// 	ChessAI ca = ChessAI(dataBoard);
// 	pair<string, string> MOVE = ca.minimax(-20000, 20000, 5, 'B').second;
// 	std::cout << MOVE.first << ' ' << MOVE.second << '\n';

// 	Point p = Point(MOVE.first);
// 	(*dataBoard)[p.get_x()][p.get_y()]->move(MOVE.second, true);

// 	for (int i = 0; i < 8; i += 1){
// 		for (int j = 0; j < 8; j += 1){
// 			std::cout << (ChessPiece::get_Board()[i][j] == nullptr ? '.' : ChessPiece::get_Board()[i][j]->get_kindPiece()) << ' ';
// 		}
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }

#endif