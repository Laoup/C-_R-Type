#ifndef PLAYER_HH_
# define PLAYER_HH_

#include "element.hh"

class player : public element
{
public:
  player();
  ~player();

  void getTexture(std::string &);
};

#endif
