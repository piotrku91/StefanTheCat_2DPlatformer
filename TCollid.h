#pragma once
#include "sfml/SFML-2.5.1/include/SFML/Graphics.hpp"

class TCollid
{
public:
sf::Texture m_Texture;
sf::Sprite m_Sprite;

   bool testCollision (TCollid &target) {
      if (m_Sprite.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
            return true;
      }
      return false;
   };

      bool testCollisionDown (TCollid &target) {
         
        sf::Sprite tmp=m_Sprite;
        tmp.move(0,4);
      if (tmp.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
         std::cout<< "KOLIZJA GLEBA y=" << m_Sprite.getPosition().y << std::endl;
            return true;

      }
      return false;
   };

    bool testCollisionTop (TCollid &target) {
        sf::Sprite tmp=m_Sprite;
        tmp.move(0,-5);
    //   sf::FloatRect temp = sf::FloatRect(m_Sprite.getPosition().x,m_Sprite.getPosition().y-5,m_Sprite.getTextureRect());
      
      if (tmp.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
         std::cout<< "KOLIZJA GORA y=" << m_Sprite.getPosition().y << std::endl;
            return true;
      }
      return false;
   };

      bool testCollisionLeft (TCollid &target) {
        sf::Sprite tmp=m_Sprite;
        tmp.move(-10,-20);
      if (tmp.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
         std::cout<< "KOLIZJA LEWA x=" << m_Sprite.getPosition().x << std::endl;
            return true;
      }
      return false;
   };

       bool testCollisionRight (TCollid &target) {
        sf::Sprite tmp=m_Sprite;
        tmp.move(+10,-20);
      if (tmp.getGlobalBounds().intersects(target.m_Sprite.getGlobalBounds())) {
         std::cout<< "KOLIZJA PRAWA x=" << m_Sprite.getPosition().x << std::endl;
            return true;
      }
      return false;
   };

      

};