#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>

#define MOVE_SPEED 10


void Log(std::string text) {

    std::cout << text << std::endl;
}


void RysujOgon(sf::RenderWindow& RW,sf::CircleShape& CS, int kierunek, bool rysuj=true)
{
    if (rysuj) {
      std::vector<sf::CircleShape> ogon(40);

        for (int i=1; (i < ogon.size()); i++) 
        {
        ogon[i] = sf::CircleShape(20.f);
        ogon[i].setFillColor(sf::Color(0,255,0,100-i));

switch (kierunek)
{
case 1: ogon[i].setPosition(sf::Vector2f(CS.getPosition().x-2*i,CS.getPosition().y)); break;
case 2: ogon[i].setPosition(sf::Vector2f(CS.getPosition().x+2*i,CS.getPosition().y)); break;
case 3: ogon[i].setPosition(sf::Vector2f(CS.getPosition().x,CS.getPosition().y+2*i)); break;
case 4: ogon[i].setPosition(sf::Vector2f(CS.getPosition().x,CS.getPosition().y-2*i)); break;
default:  ogon[i].setPosition(sf::Vector2f(CS.getPosition().x,CS.getPosition().y)); break;




}

        
        RW.draw(ogon[i]);

        } ;
        
        };



};

int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(640, 480), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(130,120));
  int tmpkier=0;
    // Kształty

    sf::CircleShape shape(20.f,60);
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
          

        

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                shape.setFillColor(sf::Color::Red);
                shape.setPosition(sf::Vector2f(shape.getPosition().x+MOVE_SPEED,shape.getPosition().y));
                tmpkier=1;
               
            };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                shape.setFillColor(sf::Color::Red);
                shape.setPosition(sf::Vector2f(shape.getPosition().x-MOVE_SPEED,shape.getPosition().y));
                tmpkier=2;
                
            };

            if ( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) )
            {
                shape.setFillColor(sf::Color::Green);
                tmpkier=0;
          
            };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                shape.setFillColor(sf::Color::Red);
                shape.setPosition(sf::Vector2f(shape.getPosition().x,shape.getPosition().y-MOVE_SPEED));
                tmpkier=3;
            }

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                shape.setFillColor(sf::Color::Red);
                shape.setPosition(sf::Vector2f(shape.getPosition().x,shape.getPosition().y+MOVE_SPEED));
                tmpkier=4;
            }
            

            
             
        }

        window.clear();

       RysujOgon(window,shape,tmpkier);
        
       window.draw(shape);
        window.display();
    }

    return 0;
}
