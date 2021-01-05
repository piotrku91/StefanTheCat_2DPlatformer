#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "TPlatform.h"
#include "math.h"

#define MOVE_SPEED 10

extern void Log(std::string);


class TPlayer: public TCollid
{

public:

bool isJumping=false;
bool CanJump=true;
// Konstruktor
TPlayer () = delete;
TPlayer (const int& PosX, const int& PosY, const std::string file, const int& cutX, const int& cutY) 
{
   m_Texture.loadFromFile(file,sf::IntRect(cutX, cutY, 16, 16)); // plik tekstury
   m_Texture.setRepeated(true);
   m_Sprite.setTexture(m_Texture); 
   m_Sprite.setTextureRect(sf::IntRect(cutX, cutY, 16, 16));
   m_Sprite.setPosition(PosX,PosY); // pozycjonowanie
  
}

// Funkcje składowe

void Move(const int& x=0, const int& y=0) 
{
m_Sprite.move(x,y);
};

void MoveRight(const int& speed=MOVE_SPEED) {Move(speed,0);};
void MoveLeft(const int& speed=-MOVE_SPEED) {Move(speed,0);};
//void MoveUp(const int& speed=-MOVE_SPEED) {Move(0,speed);};
void MoveDown(const int& speed=MOVE_SPEED) {Move(0,speed);};
void MoveStop() {};


sf::Vector2f Baza;



sf::Drawable& GetToDraw()
{
return m_Sprite;
}

};
