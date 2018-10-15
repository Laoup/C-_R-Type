#ifndef ENNEMY_HH_
# define ENNEMY_HH_

#include "element.hh"

//enum class STRATEGY {DEFAULT};

class ennemy : public element
{

  STRATEGY  move_strat;

public:
  ennemy();
  ~ennemy();

  void getTexture(std::string &);
  STRATEGY  getStrategy();
};

#endif
