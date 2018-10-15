#ifndef GAME_HH_
# define GAME_HH_

#include "handlerKeyMapping.hh"
#include "handlerSprite.hh"
#include "element.hh"
#include "physiqueManager.hh"

class game
{
  element               player;
  physiqueManager       m_physique;
  std::map<KEY, STATE>  key_map;

//  handlerKeyMapping handler_key;

public:
  game();
  ~game();

  void  setKeyMap(std::map<KEY, STATE>  &);

  void  initializeTheGame();
  void  applyTurn();

  sf::Sprite&  returnSpritePlayer();
};

#endif
