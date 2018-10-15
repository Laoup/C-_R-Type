#ifndef PHYSIQUEMANAGER_HH_
# define PHYSIQUEMANAGER_HH_

#include "element.hh"

class physiqueManager
{

public:
  physiqueManager();
  ~physiqueManager();

  void moveUP(element *);
  void moveDOWN(element *);
  void moveLEFT(element *);
  void moveRIGHT(element *);

  void moveEnnemy(std::vector<element *>::iterator);
};

#endif
