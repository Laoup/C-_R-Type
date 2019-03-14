#ifndef PHYSIQUEMANAGER_HH_
# define PHYSIQUEMANAGER_HH_

#include "config.hh"
#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include "view.hh"
#include "ennemy.hh"
#include <vector>
#include <array>
#include <stdlib.h>
#include <time.h>

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

  void checkCollision(element *, element *, std::vector<object *> &, handlerSprite *);
  void checkBorderCollision(element *, view &);

  object* fireOrder(ship *, DIRECTION);

  //std::array<int, 3>  &TileTheMap(int, int);
  void                  TileTheMap(int, int, std::array<int, 3> &);
  void                  generateEnnemys(int, std::array<int, 3> &, std::vector<ship *> &, int, int, handlerSprite *);
  void                  createWaveEnnemys(int, std::array<int, 3> &, std::vector<ship *> &, handlerSprite *);
};

#endif
