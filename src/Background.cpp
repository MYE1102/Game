#include "Background.h"

Background::Background()
{
     backT.loadFromFile(resourcePath() + "assets/9444.png");
     backS.setTexture(backT);
     backS.setTextureRect(sf::IntRect(0, 1300, 162, 130));
     backS.setScale(5.0, 5.0);
     currSide = backS.getTextureRect();
}

sf::Vector2f Background::moveBackground(sf::RenderWindow &window)
{
     float winX = (float)window.getSize().x;
     float winY = (float)window.getSize().y;
     updateSide = currSide;
     if (!newMap && oldMap)
     {
          if (mainChPos.x > winX)
          {
               updateSide = sf::IntRect(currSide.left + 162, currSide.top, currSide.width, currSide.height);
               mainChPos.x = 0.0;
               newMap = true;
          }
          if (mainChPos.y > winY)
          {
               updateSide = sf::IntRect(currSide.left, currSide.top + 130, currSide.width, currSide.height);
               mainChPos.y = 0.0;
               newMap = true;
          }
          if (mainChPos.x < 0.0 && currSide.left > 0.0)
          {
               updateSide = sf::IntRect(currSide.left - 162, currSide.top, currSide.width, currSide.height);
               mainChPos.x = winX;
               newMap = true;
          }
          if (mainChPos.y < 0.0 && currSide.top > 0.0)
          {
               updateSide = sf::IntRect(currSide.left, currSide.top - 130, currSide.width, currSide.height);
               mainChPos.y = winY;
               newMap = true;
          }

     }
     if (currSide != updateSide)
     {
          oldMap = false;
     }
     if (!oldMap)
     {
          newMap = false;
     }
     if (!newMap)
     {
          oldMap = true;
     }
     currSide = updateSide;

     backS.setTextureRect(currSide);

     return mainChPos;
}