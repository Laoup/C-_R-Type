#ifndef ENNEMY_HH_
# define ENNEMY_HH_

#include "ship.hh"
#include <memory>

//enum class STRATEGY {DEFAULT};

class ennemy : public ship
{

  STRATEGY  move_strat;

public:
  ennemy();
  ennemy(std::shared_ptr<handlerSprite>);
  ennemy(std::shared_ptr<handlerSprite>, int, STRATEGY, int, int);
  ~ennemy();

  STRATEGY  getStrategy();
};

#endif
