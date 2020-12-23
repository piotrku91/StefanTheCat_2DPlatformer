#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include "TPlayer.h"
#include "TPlatform.h"
#include "TParabolic.h"



template <typename T>
void Log(T CmdLine) {
    std::cout << CmdLine << std::endl;
}


sf::Texture Texture[2]; // Tablica tekstur
TPlayer Gracz(100,100,"textures/jeden.jpg",0,0); // Tworzenie playera
std::vector<TPlatform> Platformy;  //Kontener platform



void Gravity()
{
Gracz.MoveDown(5);
};


int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(130,120));

    
    //WCZYTYWANIE TEKSTUR
    Texture[0].loadFromFile("textures/jeden.jpg"); // plik tekstury
    Texture[0].setRepeated(true);
    

    // TWORZENIE PLATFORM
    sf::Texture * Platformy_Textury = Texture;

    Platformy.emplace_back(20,400,Platformy_Textury,512,512);
    Platformy.emplace_back(350,300,Platformy_Textury,512,512);
    Platformy.emplace_back(300,350,Platformy_Textury,512,512);
    Platformy.emplace_back(150,500,Platformy_Textury,512,512);
    TParabolic Parabola;
    Parabola.Recalculate(10,-0.05);
    std::cout << Parabola.getPoint(32)->x;
    //GAME LOOP
    while (window.isOpen())
    {

    // ZMIENNE
        sf::Event event;

        float dX=0;
        float dY=0;
        bool onGround=false;
        bool leftWall=false;
        bool rightWall=false;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
          

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dX=15; };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ dX=-15; };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){  };

        }

         for (TPlatform& Platform: Platformy) { 
                                              if (Gracz.testCollisionDown(Platform))  onGround=true;
                                              if (Gracz.testCollisionLeft(Platform))  leftWall=true;
                                              if (Gracz.testCollisionRight(Platform)) rightWall=true;
                                         };
                                              
         
         if ((dX>0) && (!rightWall) && (onGround)) Gracz.MoveRight(dX); 
         if ((dX<0) && (!leftWall) && (onGround)) Gracz.MoveLeft(dX);    
         if (!onGround) Gravity(); 

      // RYSOWANIE
      window.clear();
      window.draw(Gracz.GetToDraw());

      for (TPlatform& Platform: Platformy) {window.draw(Platform.GetToDraw());}
      window.display();
    }

    return 0;
}
