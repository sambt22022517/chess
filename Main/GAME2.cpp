#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\Board\Board.cpp"
#include "..\Utility\Point.cpp"
#include "..\Graphic\graphic.cpp"

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

		

		vector<string> data_board2 = {
		"a1.", "b1.", "c1.", "d1.", "e1K", "f1.", "g1.", "h1r",
		"a2r", "b2.", "c2.", "d2.", "e2.", "f2.", "g2.", "h2.",

		"a3.", "b3.", "c3.", "d3.", "e3k", "f3.", "g3.", "h3.",
		"a4.", "b4.", "c4.", "d4.", "e4.", "f4.", "g4.", "h4.",
		"a5.", "b5.", "c5.", "d5.", "e5.", "f5.", "g5.", "h5.",
		"a6.", "b6.", "c6.", "d6.", "e6.", "f6.", "g6.", "h6.",

		"a7.", "b7.", "c7.", "d7.", "e7.", "f7.", "g7.", "h7.",
		"a8.", "b8.", "c8.", "d8.", "e8.", "f8.", "g8.", "h8."};

		string introduce = "This chess game is just for ...\nType your moving by this fomat:\n\n<curr_col><curr_row> <next_col><next_row>.\n\nGood luck!\n\n";



	public:
		GAME(){
			ChessPiece::set_DataBoard(DataBoard(data_board2));
			std::cout << this->introduce;
			displayBoard();
		}

		void RUN(){
			bool running = true;
			bool white_turn = true;
			string curr_pos = "", next_pos = "";

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

				ChessPiece * cp = ChessPiece::get_dataBoard(Point(curr_pos));

				if (cp == nullptr) continue;

				// Kiểm tra xem hiện có đang bị chiếu không
				// Nếu có thì xác định những quân cờ đối phương đang chiếu mình
				bool test = true;
				ChessPiece* check1 = NULL, *check2 = NULL;
				for (int i = 0; i < 8 and test; i += 1){
					for (int j = 0; j < 8 and test; j += 1){
						ChessPiece * op = ChessPiece::get_dataBoard(Point(i, j)); // opponent
						if (op != nullptr and op->get_kind() != cp->get_kind()){
							op->calValidMove();
							if (op->get_check_moves().size() > 1){
								if (not check1) check1 = op;
								else {
									check2 = op;
									test = false;
								}
							}
						}
					}
				}
				
				// Tính toán nước đi hợp lệ của quân cờ đang chọn
				// Kiểm tra xem next_pos có hợp lệ không:
				// Nếu có: Di chuyển -> Đổi lượt
				// Nếu không: Chọn lại
				if (check2) cp->calValidMove({check1, check2});
				else if (check1) cp->calValidMove({check1});
				else cp->calValidMove();
				std::vector<Point> valid_moves = cp->get_valid_moves();

				for (Point i : valid_moves) std::cout << i.location() << ' ';

				bool valid_player = not (bool)(white_turn ^ (cp->get_kind() == 'W'));
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

	return 0;
}