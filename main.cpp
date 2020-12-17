#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>


void Log(std::string text) {

    std::cout << text << std::endl;
}

int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(640, 480), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(130,120));

    // Kształty

    sf::CircleShape shape(100.f,60);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(20,20));
    //shape.setOrigin(sf::Vector2f(50,5)); punkt zaczepienia

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
          

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
             sf::Thread th1(Log,"bstsk");
             th1.launch();
            }
             
        }

        window.clear();
        
       window.draw(shape);
        window.display();
    }

    return 0;
}
