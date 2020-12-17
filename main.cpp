#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>

#define MOVE_SPEED 10

template <typename T>
void Log(T CmdLine) {
    std::cout << CmdLine << std::endl;
}


class TPlayer
{
private:
sf::Texture m_Texture;
sf::Sprite m_Sprite;

public:
// Konstruktor
TPlayer () 
{
   m_Texture.loadFromFile("textures/jeden.jpg",sf::IntRect(0, 0, 32, 32)); // plik tekstury
   m_Texture.setRepeated(false);
   m_Sprite.setTexture(skora); 
   m_Sprite.setPosition(30,175); // pozycjonowanie
  
}

// Funkcje składowe

void Move(const int& x=0, const int& y=0) 
{
m_Sprite.setPosition(sf::Vector2f(duszek.getPosition().x+x,duszek.getPosition().y+y));
  
};

void MoveRight(const int& speed=MOVE_SPEED) 
{
Move(speed,0);
};

void MoveLeft(const int& speed=-MOVE_SPEED) 
{
Move(speed,0);
};

void MoveUp(const int& speed=-MOVE_SPEED) 
{
Move(0,speed);
};

void MoveDown(const int& speed=MOVE_SPEED) 
{
Move(0,speed);
};

void Stop() 
{

};

sf::Drawable& GetToDraw()
{
return m_Sprite;
}

};




TPlayer Gracz;
int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(640, 480), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(130,120));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
          

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
              
                Gracz.MoveRight();
               
               
            };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
              Gracz.MoveLeft();
             
              
                
            };

               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              Gracz.MoveUp();
           
              
            }

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
              Gracz.MoveDown();
             
            
            }

            if ( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) )
            {
              Gracz.Stop();
        
          
            };

        
             
        }

      window.clear();
      window.draw(Gracz.GetToDraw());
      window.display();
    }

    return 0;
}
