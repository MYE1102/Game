/*
Legend of Zelda Link's Awakening & Minish Cap Mix
Overworld Adventure

cocywrite by Ye Eun Myung
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.h"
#include "Overlap.h"
#include "link.h"
#include "Background.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(810, 650), "SFML Works!");
	//window.setVerticalSyncEnabled(true); //still fast
	window.setFramerateLimit(30);


	linkSprite linkSprite;
     Background background;
	sf::Music music;
	if (!music.openFromFile(resourcePath() + "assets\\Overworld_(The_Legend_of_Zelda).ogg"))
	{
		std::cout << "Cannot open music" << std::endl;
	}
	music.play();
	music.setLoop(true);

	//sf::View view;
	//view.reset(sf::FloatRect(0, 0, 800, 650));
	//view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f position(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		
		//window.setView(view);
		window.clear();
		
		
		linkSprite.moveAni(event);
          background.setMainChPosition(linkSprite.getPosition());
         
          linkSprite.setPosition(background.moveBackground(window));
		linkSprite.attackAni();		

          background.drawBackS(window);
		linkSprite.drawlinkS(window);
		window.display();
	}

	return 0;
}
