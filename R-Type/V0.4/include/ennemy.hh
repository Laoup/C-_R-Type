#ifndef ENNEMY_HH_
# define ENNEMY_HH_

#include "ship.hh"

//enum class STRATEGY {DEFAULT};

class ennemy : public ship
{

  STRATEGY  move_strat;

public:
  ennemy();
  ~ennemy();

  void getTexture(std::string &);
  STRATEGY  getStrategy();
};

#endif
