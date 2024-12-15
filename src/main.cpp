#include <SFML/Graphics.hpp>
#include <cmath> // For sqrt()

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Equilateral Triangle");

    float sideLength = 200.0f;
    float height = std::sqrt(3.0f) / 2.0f * sideLength;

    float topX = 400.0f;  
    float topY = 100.0f; 

    sf::Vector2f point0(topX, topY);
    sf::Vector2f point1(topX - sideLength / 2.0f, topY + height);
    sf::Vector2f point2(topX + sideLength / 2.0f, topY + height);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, point0); 
    triangle.setPoint(1, point1); 
    triangle.setPoint(2, point2); 
    triangle.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(triangle);

        window.display();
    }

    return 0;
}
