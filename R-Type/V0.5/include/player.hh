#ifndef PLAYER_HH_
# define PLAYER_HH_

#include "ship.hh"
#include <vector>

class player : public ship
{

public:
  player();
  player(handlerSprite *);
  ~player();

  void getTexture(std::string &);
  STRATEGY  getStrategy();
};

#endif
