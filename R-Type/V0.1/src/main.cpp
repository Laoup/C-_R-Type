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
        //handler_window.windowDraw(game.returnSpritePlayer());
        handler_window.windowDraw(game.returnVertexPlayer());

        //End the current frame
        handler_window.windowDisplay();
    }
}
