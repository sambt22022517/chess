#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\Board\Board.cpp"
#include "..\Utility\Point.cpp"

using namespace std;

class GAME{
	private:
		std::vector<string> data_board = {
		"a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
		"a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

		// "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
		// "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
		// "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
		// "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

		"a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
		"a8r","b8n","c8b","d8q","e8k","f8b","g8n","h8r"
		};

		string introduce = "This chess game is just for ...\nType your moving by this fomat:\n\n<curr_col><curr_row> <next_col><next_row>.\n\nGood luck!\n\n";

	public:
		GAME(){
			ChessPiece::set_DataBoard(DataBoard(data_board));
			std::cout << this->introduce;
			displayBoard();
		}

		void RUN(){
			bool running = true;
			bool white_turn = true;
			string curr_pos, next_pos;

			while (running){
				if (white_turn){
					std::cout << "White's turn: ";
				} else {
					std::cout << "Black's turn: ";
				}
				
				std::cin >> curr_pos >> next_pos;

				if (curr_pos == "exit"){
					break;
				}

				// Kiểm tra xem next_pos có hợp lệ không:
				// Nếu có: Di chuyển -> Đổi lượt
				// Nếu không: Chọn lại
				std::vector<Point> valid_moves = ChessPiece::get_dataBoard(Point(curr_pos))->validMove();
				ChessPiece * cp = ChessPiece::get_dataBoard(Point(curr_pos));
				bool valid_player = not (bool)(white_turn ^ ('A' <= cp->get_kindPiece() and cp->get_kindPiece() <= 'Z'));
				for (Point i : valid_moves){
					if (cp->move(next_pos, (valid_player and next_pos == i.location()))){
						white_turn = not white_turn;
						break;
					}
				}

				displayBoard();
			}
		}
};

int main(){
	GAME chess;
	chess.RUN();

	// bool a = true;
	// bool b = true;
	// bool c = ~(a^b);
	// std::cout << c;

	return 0;
}