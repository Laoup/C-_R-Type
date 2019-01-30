#ifndef PHYSIQUEMANAGER_HH_
# define PHYSIQUEMANAGER_HH_

#include "config.hh"
#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include "view.hh"
#include <vector>

class physiqueManager
{

public:
  physiqueManager();
  ~physiqueManager();

  void moveUP(element *, float = SPEED);
  void moveDOWN(element *, float = SPEED);
  void moveLEFT(element *, float = SPEED);
  void moveRIGHT(element *, float = SPEED);

  //void moveEnnemy(std::vector<element *>::iterator);
  void moveEnnemy(ship *);
  void moveObjectVector(std::vector<object *>);

  void checkCollision(element *, element *, std::vector<object *> &);
  void checkBorderCollision(element *, view &);

  object* fireOrder(ship *, DIRECTION);
};

#endif
