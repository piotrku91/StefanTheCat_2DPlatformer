#pragma once
#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "TCollid.h"
#define MOVE_SPEED 10

extern void Log(std::string);

class TPlatform: public TCollid
{

public:
// Konstruktor
//TPlatform () = delete;
//TPlatform () {};
TPlatform (const int& PosX, const int& PosY, sf::Texture * TextureContainer,  const int& cutX, const int& cutY) 
{
  // TextureContainer->loadFromFile(file,sf::IntRect(cutX, cutY, 500, 32)); // plik tekstury
   TextureContainer->setRepeated(true);
   m_Sprite.setTextureRect(sf::IntRect(cutX, cutY, 500, 32));
   m_Sprite.setTexture(*TextureContainer); 
   m_Sprite.setPosition(PosX,PosY); // pozycjonowanie
  
}

// Funkcje składowe

void Move(const int& x=0, const int& y=0) 
{
m_Sprite.move(x,y);
};

void MoveRight(const int& speed=MOVE_SPEED) {Move(speed,0);};
void MoveLeft(const int& speed=-MOVE_SPEED) {Move(speed,0);};
void MoveDown(const int& speed=MOVE_SPEED) {Move(0,speed);};
void MoveStop() {};



sf::Drawable& GetToDraw()
{
return m_Sprite;
}

};
