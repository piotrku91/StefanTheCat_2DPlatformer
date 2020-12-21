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
std::vector<TPlatform> Platformy;



int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(130,120));

    Platformy.emplace_back(20,400,"textures/jeden.jpg",512,512);
    Platformy.emplace_back(350,300,"textures/jeden.jpg",512,512);
   // TPlatform Platform(0,400,"textures/jeden.jpg",512,512);
  //  TPlatform Platform2(350,Platform.m_Sprite.getPosition().y-40,"textures/jeden.jpg",512,512);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
          

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
            
              for (TPlatform& Platform : Platformy) {
              if ((!Gracz.testCollisionRight(Platform)) && (!Gracz.testCollisionRight(Platform))) {Gracz.MoveRight(); } else {Gracz.MoveStop(); Gracz.CanJump=false;};
              };
               
            };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
           for (TPlatform& Platform : Platformy) {
              if ((!Gracz.testCollisionLeft(Platform)) && (!Gracz.testCollisionLeft(Platform))) {Gracz.MoveLeft(); } else {Gracz.MoveStop(); Gracz.CanJump=false;};
                 };
             
              
                
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

        if (Gracz.isJumping) Gracz.Fly(); 

         for (TPlatform& Platform: Platformy) {
        if (Gracz.isCollision(Platform)) {Gracz.CanJump=true; } else { Gracz.MoveDown(5); Gracz.CanJump=false;};
         };
                

      window.clear();
      window.draw(Gracz.GetToDraw());
      for (TPlatform& Platform: Platformy) {window.draw(Platform.GetToDraw());};
      //window.draw(Platform.GetToDraw());
      //window.draw(Platform2.GetToDraw());
      //window.draw(Wall.GetToDraw());
      window.display();
    }

    return 0;
}
