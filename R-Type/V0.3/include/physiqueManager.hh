#ifndef PHYSIQUEMANAGER_HH_
# define PHYSIQUEMANAGER_HH_

#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include <vector>

class physiqueManager
{

public:
  physiqueManager();
  ~physiqueManager();

  void moveUP(element *, float = 0.85);
  void moveDOWN(element *, float = 0.85);
  void moveLEFT(element *, float = 0.85);
  void moveRIGHT(element *, float = 0.85);

  //void moveEnnemy(std::vector<element *>::iterator);
  void moveEnnemy(ship *);
  void moveObjectVector(std::vector<object *>);

  void checkCollision(element *, element *, std::vector<object *> &);

  object* fireOrder(ship *, DIRECTION);
};

#endif
