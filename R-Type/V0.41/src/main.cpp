#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include "config.hh"
#include "../include/handlerWindow.hh"
#include "../include/handlerSprite.hh"
#include "../include/handlerKeyMapping.hh"
#include "../include/game.hh"

int main()
{
  handlerWindow         handler_window("Window by Object");
  handlerKeyMapping     handler_key;
  game                  game;
  std::map<KEY, STATE>  key_map;
  std::vector<handlerSprite> movable_object;
  std::vector<handlerSprite>::iterator it;
  sf::Sprite            background;
  //sf::View              view;
  //sf::Vector2f          test;


  //Début d'un menu qui marche pas
  /*while (handler_window.windowIsOpen())
    {
      game.menu(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
      handler_window.windowClear(sf::Color::Black);
      //handler_window.windowDraw(game.returnBackground());
      handler_window.windowDraw(game.returnSpriteTitle());
      handler_window.windowDraw(game.returnText());
      handler_window.setView(game.returnView());
      handler_window.windowDisplay();
    }*/
  game.initializeTheGame(handler_window.getDefaultView(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
  /*view = handler_window.getDefaultView();
  test = view.getCenter();
  test = view.getSize();
  printf("view size x = %f, y = %f\n", test.x, test.y);*/

  while (handler_window.windowIsOpen())
    {
      /*while (handler_window.windowIsEvent(handler_key.getEvent()))
        {
          //key_map = handler_key.returnKey();
          key_map = handler_key.returnKey2();
          game.setKeyMap(key_map);
          game.applyTurn();
        }*/
        handler_window.windowIsEvent(handler_key.getEvent());
        key_map = handler_key.returnKey2();
        game.setKeyMap(key_map);
        game.applyTurn();

        /*key_map = handler_key.returnKey2();
        game.setKeyMap(key_map);
        game.applyTurn();*/

        //clear the window with black Color
        handler_window.windowClear(sf::Color::Black);

        background = game.returnBackground();
        game.returnVertexVectorMovableObject(movable_object);
        //int i = 0;
        it = movable_object.begin();
        /*while (i != movable_object.size())
          {
            handler_window.windowDraw(movable_object[i]);
            i++;
          }*/
        handler_window.setView(game.returnView());
        handler_window.windowDraw(background);
        while (it != movable_object.end())
          {
            handler_window.windowDraw(*it);
            it++;
          }
        movable_object.erase(movable_object.begin(), movable_object.end());
        /*it = movable_object.begin();
        while (it != movable_object.end())
          {
            handler_window.windowDraw(*it);
            it++;
          }*/
        //handler_window.windowDraw(game.returnVertexPlayer());

        //End the current frame
        handler_window.windowDisplay();
        if (game.deleteDeadElems() == 0)
          break;
    }
  printf("\nEND\n");
}
