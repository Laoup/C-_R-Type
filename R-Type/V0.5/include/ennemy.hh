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
  /*
  OLD
  ennemy(std::string, int, int);
  ennemy(std::string, STRATEGY, int, int);
  */
  ennemy(handlerSprite *, int, STRATEGY, int, int);
  ~ennemy();

  void getTexture(std::string &);
  STRATEGY  getStrategy();
};

#endif
