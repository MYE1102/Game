#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.h"

class linkSprite
{
private:
	sf::Texture linkT;
	sf::Sprite linkS;

	sf::Clock clock1;
	sf::Clock clock2;
	sf::IntRect currSide;
	int counter1 = 0;
	int counter2 = 0;
	int posNum = 0;
	int initX = 0;
	int initY = 0;
	bool attack = false;

	sf::Vector2f currPosition;
     
public:

	linkSprite();
	void moveAni(sf::Event &event);
     void checkPosNumber();
	void attackAni();
     sf::Vector2f getPosition() { return linkS.getPosition();}
     void setPosition(sf::Vector2f newPos) { linkS.setPosition(newPos); }
	void drawlinkS(sf::RenderWindow &window)
	{
		window.draw(linkS);
	}

};