#include <SFML/Graphics.hpp>
#include "..\ChessPiece\ChessPiece.cpp"
#include "..\ChessPiece\Piece.cpp"
#include "..\Board\Board.cpp"

using namespace sf;

class Graphic{
private:
    RenderWindow* window;
    Texture board;
    Sprite spriteboard;
    int w_window;
    int h_window;
public:
    Graphic(RenderWindow* _window){
        window = _window;
        board.loadFromFile("Image/board.png");

        w_window = board.getSize().x;
        h_window = board.getSize().y;

        window->setSize(Vector2u(h_window, w_window));
        
        spriteboard = Sprite(board);
    }
    static Texture get_image(ChessPiece* chesspiece){
        Texture texture;

        string path = "Image/" + string(1,chesspiece->get_kind()) + string(1,chesspiece->get_kindPiece()) + ".png";

        texture.loadFromFile(path);
        return texture;
    }
    void draw(vector<vector<ChessPiece*>> DataBoard){
        window->clear();
        window->draw(spriteboard);
        for(auto i: DataBoard){
            for(auto j: i){
                if(j != NULL){
                    Texture piece = get_image(j);
                    Vector2u size = piece.getSize();
                    
                    Sprite spritepiece(piece);
                    spritepiece.scale(sf::Vector2f((float)h_window/8/size.x, (float)h_window/8/size.y));
                    
                    Point point = j->get_location().getPoint_WNorigin();
                    int x = point.get_x(), y = point.get_y();
                    spritepiece.setPosition(x * w_window / 8,y * h_window / 8);
                    window->draw(spritepiece);
                }
            }
        }
        window->display();
    }
    RenderWindow* get_window(){
        return window;
    }
};

// int main()
// {
//     // // piece
//     // sf::Texture texturepiece = Graphic::get_image(creatPiece("a1p"));

//     // sf::Sprite piece(texturepiece);
//     // piece.setPosition(0,0);

//     // // Board

//     // sf::Texture textureboard;
//     // textureboard.loadFromFile("Image/board.png");

//     // sf::Sprite board(textureboard);
//     // board.setPosition(0,0);

//     // // set window
//     // float w_window = textureboard.getSize().x;
//     // float h_window = textureboard.getSize().y;
//     // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
//     vector<string> data_Board = {
//         "a1R","b1N","c1B","d1Q","e1K","f1B","g1N","h1R",
//         "a2P","b2P","c2P","d2P","e2P","f2P","g2P","h2P",

//         // "a3.","b3.","c3.","d3.","e3.","f3.","g3.","h3.",
//         // "a4.","b4.","c4.","d4.","e4.","f4.","g4.","h4.",
//         // "a5.","b5.","c5.","d5.","e5.","f5.","g5.","h5.",
//         // "a6.","b6.","c6.","d6.","e6.","f6.","g6.","h6.",

//         "a7p","b7p","c7p","d7p","e7p","f7p","g7p","h7p",
//         "a8r","b8n","c8b","d8q","e8k","f8b","g8n","h8r"
//     };
    
//     vector<vector<ChessPiece*>> db = DataBoard(data_Board);
//     sf::RenderWindow* window = new RenderWindow(sf::VideoMode(711, 712), "Chess");
//     Graphic g(window);

//     while (window->isOpen())
//     {
//         sf::Event event;
//         while (window->pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window->close();
//         }
//         // window->clear();
//         // window->draw(piece);
//         // window->display();
//         g.draw(db);
//     }

//     return 0;
// }