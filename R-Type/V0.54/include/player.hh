#ifndef PLAYER_HH_
# define PLAYER_HH_

#include "ship.hh"
#include <vector>

class player : public ship
{

public:
  player();
  player(std::shared_ptr<handlerSprite>);
  ~player();

  STRATEGY  getStrategy();
};

#endif
