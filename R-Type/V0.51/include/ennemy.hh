#ifndef ENNEMY_HH_
# define ENNEMY_HH_

#include "ship.hh"

//enum class STRATEGY {DEFAULT};

class ennemy : public ship
{

  STRATEGY  move_strat;

public:
  ennemy();
  ennemy(handlerSprite *);
  ennemy(handlerSprite *, int, STRATEGY, int, int);
  ~ennemy();

  STRATEGY  getStrategy();
};

#endif
