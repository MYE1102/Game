#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcePath.h"

class Background
{
private:
     sf::Texture backT;
     sf::Sprite backS;
     sf::Vector2f mainChPos;
     sf::IntRect currSide;
     sf::IntRect updateSide;

     bool newMap = false;
     bool oldMap = true;
public:
     Background();

     void setMainChPosition(sf::Vector2f mainPos) { mainChPos = mainPos; }
     void drawBackS(sf::RenderWindow &window) { window.draw(backS); }
     sf::Vector2f  moveBackground(sf::RenderWindow &window);
};