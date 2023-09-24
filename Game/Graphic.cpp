#include <SFML/Graphics.hpp>

int main()
{
    // Tạo một cửa sổ với độ phân giải 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Square");

    // Tạo một hình vuông màu đỏ
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
    square.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}