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
float para_arr[10][2];
sf::Vector2f Baza;
sf:: Vector2f lastPos;
bool Falling=false;

void MoveJump()
{
Baza = m_Sprite.getPosition();
std::cout << "BAZA x: " <<Baza.x;
std::cout << " BAZA y: " << Baza.y <<std::endl;

for (int i=0; i<11; i++)
{
   
para_arr[i][0]=i*10+Baza.x;
para_arr[i][1]=Baza.y-((-1*pow(i-5,2))+80);


std::cout << "x: " <<para_arr[i][0];
std::cout << " y: " << para_arr[i][1] <<std::endl;

};
int FCounter=0;
isJumping=true;
CanJump=false;

}

void Fly()
{
   
  // std::cout << "BAZA x: " <<Baza.x;
//std::cout << " BAZA y: " << Baza.y <<std::endl;
   if (FCounter<11) {
m_Sprite.setPosition(para_arr[FCounter][0],para_arr[FCounter][1]);

std::cout << "nowy x: " <<para_arr[FCounter][0];
std::cout << " nowy y: " << para_arr[FCounter][1] <<std::endl;


FCounter++;

   } else { isJumping=false;  FCounter=0; }

   //   if ((FCounter>-1) && (Falling)) {

//m_Sprite.setPosition(Baza.x+para_arr[FCounter][0],Baza.y-para_arr[FCounter][1]);
//FCounter--;
  // } 
 //if (FCounter<0) { Falling=false; isJumping=false; };
   
  
   



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
