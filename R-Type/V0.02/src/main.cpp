#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "../include/handlerWindow.hh"
#include "../include/handlerSprite.hh"
#include "../include/handlerKeyMapping.hh"
#include "../include/game.hh"

int main()
{
  handlerWindow         handler_window("Window by Object");
  handlerSprite         handler_sprite;
  handlerKeyMapping     handler_key;
  game                  game;
  std::map<KEY, STATE>  key_map;

  // check all the window's events that were triggered since the last iteration of the loop
  //sf::Event event;

  //sf::Texture texture;
  //sf::Sprite  sprite;

  /*if (texture.loadFromFile("./ressources/Starfighter.png") == false)
    {
      std::cout << "Impossible de charger l'image du vaisseau" << std::endl;
      return (-1);
    }
  else
    sprite.setTexture(texture);*/
    //std::string str = "./ressources/Starfighter.png";
  //handler_tile.makeSprite("./ressources/Starfighter.png");
    //handler_sprite.makeSprite("./ressources/Starfighter.png");

  // run the program as long as the window is open
    /*while (handler_window.windowIsOpen())
    {
        while (handler_window.windowIsEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                return (-1);
                //window.close();
            else if (event.type == sf::Event::KeyPressed)
              {
                if (event.key.code == sf::Keyboard::A)
                  std::cout << "Yo PD ! " << std::endl;
              }
        }*/

      game.initializeTheGame();

        while (handler_window.windowIsOpen())
        {
            while (handler_window.windowIsEvent(handler_key.getEvent()))
            {
              key_map = handler_key.returnKey();
              game.setKeyMap(key_map);
              game.applyTurn();
            }

        //clear the window with black Color
        handler_window.windowClear(sf::Color::Black);

        //handler_window.windowDraw(handler_sprite.getSprite());
        handler_window.windowDraw(game.returnSpritePlayer());

        //End the current frame
        handler_window.windowDisplay();
    }
}
