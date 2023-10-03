#include <bits/stdc++.h>
#include "..\ChessPiece\Piece.cpp"
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\Board\Board.cpp"
#include "..\Utility\Point.cpp"
#include "..\Graphic\graphic.cpp"
#include "..\ChessAI\ChessAI.cpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
using namespace std;

class GAME
{
private:
	std::vector<string> data_board = {
		"a1R", "b1N", "c1B", "d1Q", "e1K", "f1B", "g1N", "h1R",
		"a2P", "b2P", "c2P", "d2P", "e2P", "f2P", "g2P", "h2P",

		// "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
		// "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
		// "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
		// "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

		"a7p", "b7p", "c7p", "d7p", "e7p", "f7p", "g7p", "h7p",
		"a8r", "b8n", "c8b", "d8q", "e8k", "f8b", "g8n", "h8r"};

	vector<string> data_board2 = {
		"a1R", "b1N", "c1B", "d1Q", "e1K", "f1B", "g1N", "h1R",
		"a2.", "b2P", "c2P", "d2P", "e2P", "f2P", "g2P", "h2P",

		"a3.", "b3.", "c3.", "d3.", "e3.", "f3.", "g3.", "h3.",
		"a4.", "b4.", "c4.", "d4.", "e4.", "f4.", "g4.", "h4p",
		"a5.", "b5.", "c5.", "d5.", "e5.", "f5.", "g5.", "h5.",
		"a6.", "b6.", "c6.", "d6.", "e6.", "f6.", "g6.", "h6.",

		"a7p", "b7P", "c7p", "d7p", "e7p", "f7p", "g7p", "h7p",
		"a8r", "b8n", "c8b", "d8q", "e8k", "f8b", "g8n", "h8r"};

	string introduce = "This chess game is just for ...\nType your moving by this fomat:\n\n<curr_col><curr_row> <next_col><next_row>.\n\nGood luck!\n\n";
	sf::Vector2i mousePos; // lấy vị trí của chuột
	bool click = false;	   // kiểm tra đã nhấn chọn ô hay chưa

public:
	GAME()
	{
		ChessPiece::set_DataBoard(DataBoard(data_board));
		// std::cout << this->introduce;
		// displayBoard();
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

	void RUN()
	{
		sf::RenderWindow *window = new RenderWindow(sf::VideoMode(712, 712), "Chess");
		Graphic g(window);


		ChessAI ca;
		int depth = 2;
		int count = 0;

		// chạy tính toán game
		string curr_pos = "", next_pos = "";


		char player = 'B';

		while (window->isOpen())
		{
			window->clear();
			g.draw(ChessPiece::get_Board());
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();
				}

				else if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						// Lấy vị trí khi this->click chuột và đổi sang tọa độ i , j
						this->mousePos = sf::Mouse::getPosition(*window);
						this->mousePos.x = (int)(this->mousePos.x * 8) / (window->getSize().x);
						this->mousePos.y = ((int)(window->getSize().y - (this->mousePos.y)) * 8) / (window->getSize().y);
						// sf::sleep(sf::seconds(0.3)); // sleep 0.3 giây
						this->click = true;
					}
				} 
			}

			// kiểm tra chọn quân cờ và nước đi
			if (player == 'W'){
				if (curr_pos == "" && this->click == false)
					continue;
				else if (next_pos == "" && this->click == false)
					continue;
				else if (curr_pos == "" && this->click == true)
				{
					curr_pos = Point(this->mousePos.y, this->mousePos.x).location();
					this->click = false;
				}

				else if (next_pos == "" && this->click == true)
				{
					next_pos = Point(this->mousePos.y, this->mousePos.x).location();
					this->click = false;
				}
			} else {
				auto start = std::chrono::system_clock::now();
				pair<string, string> MOVE = ca.minimax(-20000, 20000, depth, player, "oooo").second;
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> time = end - start;
				std::cout << time.count();
				curr_pos = MOVE.first;
				next_pos = MOVE.second;
			}

			ChessPiece *cp = ChessPiece::get_dataBoard(Point(curr_pos));
			if (cp == nullptr){ // Chọn phải ô trống
				curr_pos = "";
				continue;
			}
			if (curr_pos == next_pos){
				next_pos = "";
				continue;
			}

			// Kiểm tra xem hiện có đang bị chiếu không
			// Nếu có thì xác định những quân cờ đối phương đang chiếu mình
			pair<ChessPiece*, ChessPiece*> checks = this->isChecking(cp->get_kind());
			ChessPiece * check1 = checks.first;
			ChessPiece * check2 = checks.second;

			// Tính toán nước đi hợp lệ của quân cờ đang chọn
			// Kiểm tra xem next_pos có hợp lệ không:
			// Nếu có: Di chuyển -> Đổi lượt
			// Nếu không: Chọn lại
			// std::cout << check2 << check1;
			std::cout << (player == 'W' ? "white_turn\n" : "black_turn\n");
			if (check2)
				cp->calValidMove({check1, check2});
			else if (check1)
				cp->calValidMove({check1});
			else
				cp->calValidMove();
			
			std::vector<Point> valid_moves = cp->get_valid_moves();

			for (Point i : valid_moves)
				std::cout << i.location() << ' ';

			bool valid_player = not (bool)((player == 'W') ^ (cp->get_kind() == 'W'));
			for (Point i : valid_moves)
			{
				if (valid_player and next_pos == i.location())
				{
					ChessPiece * pp = cp->move(next_pos, true);
					cp->firstmove = true;
					delete pp;



					player = player ^ 'W' ^ 'B';

					count += 1;
					if (count == 15) depth = 4;
					


					break;
				}
			}

			if (curr_pos != "" && next_pos != "")
			{
				curr_pos = "";
				next_pos = "";
				sf::sleep(sf::seconds(0.15)); // sleep 0.15 giây
			}
			// window->clear();
			//  window->draw(piece);
			g.draw(ChessPiece::get_Board());
		}
	}
};

int main()
{
	GAME chess;
	chess.RUN();

	return 0;
}