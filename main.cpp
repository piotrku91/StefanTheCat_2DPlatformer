#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include "TPlayer.h"
#include "TPlatform.h"
#include "TWall.h"



template <typename T>
void Log(T CmdLine) {
    std::cout << CmdLine << std::endl;
}


TPlayer Gracz(100,100,"textures/jeden.jpg",0,0);
TPlatform Platform(50,400,"textures/jeden.jpg",512,512);
TPlatform Platform2(150,Platform.m_Sprite.getPosition().y-40,"textures/jeden.jpg",512,512);
TWall Wall(20,Platform.m_Sprite.getPosition().y-50,"textures/jeden.jpg",200,600);

int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "Stefan");
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
              // if (Gracz.isCollision(Wall)) {} else Gracz.MoveRight();

            //  if (Gracz.isCollision(Platform) && (!Gracz.isCollision(Wall))) {Gracz.MoveRight();}
           //   if (!Gracz.isCollision(Platform) && (Gracz.isCollision(Wall))) {Gracz.MoveRight();}
              if ((!Gracz.testCollisionRight(Platform)) && (!Gracz.testCollisionRight(Platform2))) {Gracz.MoveRight(); Gracz.CanJump=true;} else {Gracz.MoveStop(); Gracz.CanJump=false;};
               
               
            };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
             // if (Gracz.isCollision(Platform) && (!Gracz.isCollision(Wall))) {Gracz.MoveLeft();}
           //   if (!Gracz.isCollision(Platform) && (Gracz.isCollision(Wall))) {Gracz.MoveLeft();}
              if ((!Gracz.testCollisionLeft(Platform)) && (!Gracz.testCollisionLeft(Platform2))) {Gracz.MoveLeft(); Gracz.CanJump=true;} else {Gracz.MoveStop(); Gracz.CanJump=false;};
                
             
              
                
            };

               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
              
              if (Gracz.CanJump) Gracz.MoveJump();
           
              
            }

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
              //Gracz.MoveDown();
             
            
            }

            if ( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) )
            {
              Gracz.MoveStop();
        
          
            };

        
             
        }

        if (Gracz.isCollision(Platform) || Gracz.isCollision(Platform2)) {} else Gracz.MoveDown(5);
        if (Gracz.isJumping) Gracz.Fly(); 
                

      window.clear();
      window.draw(Gracz.GetToDraw());
      window.draw(Platform.GetToDraw());
      window.draw(Platform2.GetToDraw());
      window.draw(Wall.GetToDraw());
      window.display();
    }

    return 0;
}
