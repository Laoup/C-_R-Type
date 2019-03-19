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
#include <memory>

class physiqueManager
{

public:
  physiqueManager();
  ~physiqueManager();

  void moveEnnemy(std::shared_ptr<ship>);
  void moveObjectVector(std::vector<std::shared_ptr<object>>);

  //void checkCollision(element *, element *, std::vector<object *> &, std::shared_ptr<handlerSprite>);
  //void checkBorderCollision(element *, view &);
  void checkCollision(std::shared_ptr<element>, std::shared_ptr<element>, std::vector<std::shared_ptr<object>> &, std::shared_ptr<handlerSprite>);
  void checkBorderCollision(std::shared_ptr<element>, view &);

  //object* fireOrder(ship *, DIRECTION);
  std::shared_ptr<object> fireOrder(std::shared_ptr<ship>, DIRECTION);

  //std::array<int, 3>  &TileTheMap(int, int);
  void                  TileTheMap(int, int, std::array<int, 3> &);
  //void                  generateEnnemys(int, std::array<int, 3> &, std::vector<ship *> &, int, int, std::shared_ptr<handlerSprite>);
  //void                  createWaveEnnemys(int, std::array<int, 3> &, std::vector<ship *> &, std::shared_ptr<handlerSprite>);
  void                  generateEnnemys(int, std::array<int, 3> &, std::vector<std::shared_ptr<ship>> &, int, int, std::shared_ptr<handlerSprite>);
  void                  createWaveEnnemys(int, std::array<int, 3> &, std::vector<std::shared_ptr<ship>> &, std::shared_ptr<handlerSprite>);
};

#endif
