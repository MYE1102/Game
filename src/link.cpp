#include "link.h"
#include <iostream>
linkSprite::linkSprite()
{
	linkT.loadFromFile(resourcePath() + "assets/link.png");
	linkS.setTexture(linkT);
	linkS.setTextureRect(sf::IntRect(0, 0, 32, 32)); //left, top, width, height
	linkS.setOrigin(linkS.getGlobalBounds().width / 2, linkS.getGlobalBounds().height / 2);
	linkS.setPosition(400, 300);
	linkS.setScale(3.5, 3.5);
	currSide = linkS.getTextureRect();
}


void linkSprite::moveAni(sf::Event &event)
{
     //currSide = linkS.getTextureRect();
     if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
     {
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
               linkS.move(-3, -3);
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
               linkS.move(3, -3);
          }
          else
          {
               linkS.move(0, -3);
          }
          linkS.setTextureRect(sf::IntRect(30 * counter1, 777, 32, 32));
          counter1++;
          if (counter1 == 2 || counter1 == 1)
          {
               counter1 = 4;
          }
          posNum = 1;
     }
     if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
     {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
               linkS.move(-3, 3);
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
               linkS.move(3, 3);
          }
          else
          {
               linkS.move(0, 3);
          }
          linkS.setTextureRect(sf::IntRect(30 * counter1, -2, 32, 32));
          counter1++;
          posNum = 0;
     }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
          !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
          !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
	{
		linkS.move(3, 0);
		linkS.setTextureRect(sf::IntRect(30 * counter1, 1528, 32, 32));
		linkS.setScale(-3.5, 3.5);
		counter1++;
		posNum = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
          !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
          !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
	{
          
		linkS.move(-3, 0);
		linkS.setTextureRect(sf::IntRect(30 * counter1, 1528, 32, 32));
		linkS.setScale(3.5, 3.5);
		counter1++;
		posNum = 2;
	}

	if (counter1 >= 13)
	{
		counter1 = 0;
	}
     //currSide = linkS.getTextureRect();
     //checkPosNumber();
     std::cout << currSide.top << " -- " << currSide.left << std::endl;

}
void linkSprite::checkPosNumber()
{
     
     if (posNum == 0)
     {
          if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
          {
               counter1 = 0;
               linkS.setTextureRect(sf::IntRect(30 * counter1, -2, 32, 32));
          }

     }
     if (posNum == 1)
     {
          if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
          {
               counter1 = 0;
               linkS.setTextureRect(sf::IntRect(30 * counter1, 777, 32, 32));

          }
     }
     if (posNum == 2)
     {
          if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
               counter1 = 0;
               linkS.setTextureRect(sf::IntRect(30 * counter1, 1528, 32, 32));
               linkS.setScale(3.5, 3.5);
          }
     }
     if (posNum == 3)
     {
          if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
               counter1 = 0;
               linkS.setTextureRect(sf::IntRect(30 * counter1, 1528, 32, 32));
               linkS.setScale(-3.5, 3.5);
          }
     }
}
void linkSprite::attackAni()
{
	sf::Time time1 = clock1.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
	{
		linkS.setScale(3.5, 3.5);
		if (posNum == 0) //facing forward
		{
			initX = 90;
			initY = 358;
		}
		if (posNum == 1)//facing backward
		{
			initX = 90;
			initY = 1135;
		}
		if (posNum == 2)//facing left
		{
			initX = 86;
			initY = 1912;
		}
		if (posNum == 3) //facing right
		{
			initX = 86;
			initY = 1912;
			linkS.setScale(-3.5, 3.5);
		}
		if (counter2 >= 7)
		{
			counter2 = 0;
		}
		attack = true;
		counter2 = 0; //everytime LAlt ispressed the animation starts from beginning
		clock1.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && (clock2.getElapsedTime().asSeconds() > 2.0))
	{
		//another animation hold the sword
	}
	while (attack)
	{
		//clear the window

		time1 = clock1.getElapsedTime(); //get the current game elapsed time
		if (time1.asMilliseconds() > ((counter2 + 1) * 36)) //there are total 7 types of movement in attack //I want this movement to happen in one second.
		{
			linkS.setTextureRect(sf::IntRect(initX + (40 * counter2), initY, 38, 38)); //locate the next movement
			counter2++; //increment
			break;
		}
		if (counter2 >= 7) //if the counter is 7 then get out of this loop
		{
			linkS.setTextureRect(currSide); //back to original position
               std::cout << currSide.top << " - " << currSide.left << std::endl;
			attack = false;
		}
	}
}
