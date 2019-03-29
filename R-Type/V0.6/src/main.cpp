#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include "config.hh"
#include "../include/handlerWindow.hh"
#include "../include/handlerSprite.hh"
#include "../include/handlerKeyMapping.hh"
#include "../include/game.hh"
#include "factory.hh"

#include <stdlib.h>

int main()
{
  handlerWindow         handler_window("Window by Object");
  handlerKeyMapping     handler_key;
  game                  game;
  std::map<KEY, STATE>  key_map;
  /*std::vector<element *> movable_object;
  std::vector<element *>::iterator it;*/
  std::vector<drawableClass> movable_object;
  std::vector<drawableClass>::iterator it;
  sf::Sprite            background;
  int                   end = 0;
  int                   play = 0;
  sf::Vector2f          arr;

  game.launchGame();

  //game.initializeTheGame(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
  /*while (handler_window.windowIsOpen() && end == 0 || end == 1)
    {
        if (play == 0)
        {
          game.initializeLockedScreen(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
          while (play == 0)
            {
              handler_window.windowClear(sf::Color::Black);
              arr = handler_key.returnMouseClick();
              play = game.menu(arr, X_SIZE_WINDOW, Y_SIZE_WINDOW);
              handler_window.windowIsEvent(handler_key.getEvent());
              handler_window.windowDraw(game.returnBackground());
              handler_window.windowDrawMenu(game.returnDrawableMenu());
              handler_window.setView(game.returnView());
              handler_window.windowDisplay();
            }
          game.initializeTheGame(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
        }
        handler_window.windowIsEvent(handler_key.getEvent());
        key_map = handler_key.returnKey2();
        game.setKeyMap(key_map);
        game.applyTurn();

        handler_window.windowClear(sf::Color::Black);

        background = game.returnBackground();
        game.returnVertexVectorMovableObject(movable_object);

        it = movable_object.begin();
        handler_window.setView(game.returnView());
        handler_window.windowDraw(background);
        while (it != movable_object.end())
          {
            handler_window.windowDraw(*it);
            it++;
          }
        movable_object.erase(movable_object.begin(), movable_object.end());

        //End the current frame
        handler_window.windowDisplay();

        if (game.deleteDeadElems() == 0)
          {
            if (end == 0)
              game.initializeLockedScreen(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
            else if (end == 1)
              game.getTheWindow(handler_window.getDefaultView());
            end = 0;
            while (handler_window.windowIsOpen() && end == 0)
              {
                handler_window.windowClear(sf::Color::Black);
                arr = handler_key.returnMouseClick();
                end = game.endScreen(arr, X_SIZE_WINDOW, Y_SIZE_WINDOW);
                handler_window.windowIsEvent(handler_key.getEvent());
                handler_window.windowDraw(game.returnBackground());
                /*handler_window.windowDraw(game.returnSpriteTitle());
                handler_window.windowDraw(game.returnText());
                handler_window.windowDraw(game.returnText2());
                handler_window.windowDraw(game.returnText3());*/
                /*handler_window.windowDrawMenu(game.returnDrawableMenu());
                handler_window.setView(game.returnView());
                handler_window.windowDisplay();
                sf::sleep(sf::milliseconds(50));
              }
            if (end == 1)
              game.initializeTheGame(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
          }
      }*/
  printf("\nEND\n");
}
