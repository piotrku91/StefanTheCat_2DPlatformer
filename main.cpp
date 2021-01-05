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
TParabolic Parabola;
int flydir=0;


void Gravity(float& dY)
{
    if (dY<0) Gracz.MoveDown(dY);
    dY--;
};

void Gravity()
{
    Gracz.MoveDown(10);
    Gracz.isJumping=false;
};

void Fly()
{
    if (Parabola.isPointToGo) {
if (flydir>0)
Gracz.m_Sprite.setPosition(Gracz.Baza-Parabola.nextPoint()->toV2f_xrev());
else Gracz.m_Sprite.setPosition(Gracz.Baza-Parabola.nextPoint()->toV2f_x());
Parabola.Inc();
std::cout << "x: " << Gracz.m_Sprite.getPosition().x << " y:" <<  Gracz.m_Sprite.getPosition().y << std::endl;
    }
     else 
     { Gracz.isJumping=false;
     std::cout << "koniec paraboli - dryf" <<std::endl;
     };
};


void JumpStart()
{
    Parabola.ResetIterator();
    Gracz.Baza = Gracz.m_Sprite.getPosition();
    Fly();
Gracz.isJumping=true;
};


int main()
{
   // Okno
    sf::RenderWindow window(sf::VideoMode(800, 600), "Stefan");
    window.setActive(true);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    window.setPosition(sf::Vector2i(230,120));

    
    //WCZYTYWANIE TEKSTUR
    Texture[0].loadFromFile("textures/jeden.jpg"); // plik tekstury
    Texture[0].setRepeated(true);
    

    // TWORZENIE PLATFORM
    sf::Texture * Platformy_Textury = Texture;

    Platformy.emplace_back(20,400,Platformy_Textury,512,512);
    Platformy.emplace_back(350,300,Platformy_Textury,512,512);
    Platformy.emplace_back(300,350,Platformy_Textury,512,512);
    Platformy.emplace_back(150,500,Platformy_Textury,512,512);
    
    Parabola.Recalculate(12,-1);
     float dX=0;
     float dY=0;

  //  std::cout << Parabola.nextPoint()->x;
   // sf::Vector2f a = Parabola.firstPoint()->toV2f();

    //GAME LOOP
    while (window.isOpen())
    {

    // ZMIENNE
        sf::Event event;

        
        bool onGround=false;
        bool leftWall=false;
        bool rightWall=false;


        while (window.pollEvent(event))
        {
            if ( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
          

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dX=6; };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ dX=-6; };
            

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))) { dX=8; };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))) { dX=-8; };
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!Gracz.isJumping) && (Gracz.CanJump)) { 
                flydir=1;
                JumpStart(); 
                dX=6;
                
                };

              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (!Gracz.isJumping) && (Gracz.CanJump)) { 
                flydir=0;
                JumpStart(); 
                dX=6;
                
                };

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (!Gracz.isJumping) && (Gracz.CanJump) ) { JumpStart();};

        }

        //COLLISION CHECKS SECTION
         
         for (TPlatform& Platform: Platformy) { 
                                              if (Gracz.testCollisionDown(Platform))  { onGround=true; Gracz.isJumping=false; };
                                              if (Gracz.testCollisionLeft(Platform)) { leftWall=true; Gracz.isJumping=false; };
                                              if (Gracz.testCollisionRight(Platform)) { rightWall=true; Gracz.isJumping=false; };
                                         };
                                              
        
         if ((Gracz.isJumping) && (!onGround)) { Fly(); }; // Parabolic jump step

         if ((rightWall) && (!onGround)) { Gracz.MoveRight(-6); Gracz.CanJump=false;}; // Slide from Edge
         if ((leftWall) && (!onGround)) { Gracz.MoveRight(6); Gracz.CanJump=false;}; // Slide from Edge

         // Right / Left movements
         if ((dX>0) && (!rightWall) && (onGround)) Gracz.MoveRight(dX); 
         if ((dX<0) && (!leftWall) && (onGround)) Gracz.MoveLeft(dX); 

         if ((!onGround) && (!Gracz.isJumping))  { Gravity(); Gracz.CanJump=false;} else {Gracz.CanJump=true;}
         // Gravity movement
        // if ((onGround) && (Gracz.isJumping)) Gravity(dY);

         dX=0;
         
      // DRAWING SECTION
      window.clear();
      

      for (TPlatform& Platform: Platformy) {window.draw(Platform.GetToDraw());};
      window.draw(Gracz.GetToDraw());
      window.display();

    }

    return 0;
}
