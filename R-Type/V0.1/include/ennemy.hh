#ifndef ENNEMY_HH_
# define ENNEMY_HH_

#include "element.hh"

class ennemy : public element
{
public:
  ennemy();
  ~ennemy();

  void getTexture(std::string &);
};

#endif
