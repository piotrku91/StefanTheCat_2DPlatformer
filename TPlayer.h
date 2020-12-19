#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "TPlatform.h"
#include "math.h"

#define MOVE_SPEED 10

extern void Log(std::string);


class TPlayer: public TCollid
{

public:

bool CanJump=false;
bool isJumping=false;
// Konstruktor
TPlayer () = delete;
TPlayer (const int& PosX, const int& PosY, const std::string file, const int& cutX, const int& cutY) 
{
   m_Texture.loadFromFile(file,sf::IntRect(cutX, cutY, 32, 32)); // plik tekstury
   m_Texture.setRepeated(true);
   m_Sprite.setTexture(m_Texture); 
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


int FCounter=0;
int para_arr[60][2];
sf::Vector2f Baza;
sf:: Vector2f lastPos;
bool Falling=false;

void MoveJump()
{
Baza = m_Sprite.getPosition();

for (int i=0; i<60; i++)
{
para_arr[i][0]=i;
para_arr[i][1]=pow(i,2)/6;
};
int FCounter=0;
isJumping=true;
Falling=false;

}

void Fly()
{
   if ((FCounter<30) && (!Falling)) {
m_Sprite.setPosition(Baza.x+para_arr[FCounter][0],Baza.y-para_arr[FCounter][1]);
FCounter++;

   } else { Falling=true;}

      if ((FCounter>-1) && (Falling)) {

FCounter--;
   } 

   if (FCounter<0) { Falling=false; isJumping=false; };
   
  
   



};


/*    
   bool isCollision (TPlatform &target) {
      if (m_Sprite.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
            return true;
      }
      return false;
   }; */


sf::Drawable& GetToDraw()
{
return m_Sprite;
}

};
