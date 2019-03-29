#ifndef PHYSIQUEMANAGER_HH_
# define PHYSIQUEMANAGER_HH_

#include "config.hh"
#include "IPhysiqueManager.hh"
#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include "view.hh"
#include "ennemy.hh"
#include "player.hh"
#include "handlerKeyMapping.hh"
#include <vector>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <map>

class physiqueManager : public IPhysiqueManager
{

    std::vector<std::shared_ptr<ship>>     ships;
    std::vector<std::shared_ptr<object>>   objects;

    std::map<KEY, STATE>                   key_map;

public:
  physiqueManager();
  ~physiqueManager();

  void  moveUp(std::shared_ptr<element>, double = SPEED);
  void  moveDown(std::shared_ptr<element>, double = SPEED);
  void  moveLeft(std::shared_ptr<element>, double = SPEED);
  void  moveRight(std::shared_ptr<element>, double = SPEED);

  void  createPlayerShip(std::shared_ptr<handlerSprite>);

  void  applyPlayerTurn(int, bool);
  void  applyEnnemyTurn(int, std::shared_ptr<handlerSprite>);

  void  moveEnnemy(std::shared_ptr<ship>);
  void  moveObjectVector();

  void  applyObjectsCollision(bool, std::shared_ptr<handlerSprite>);
  void  applyBordersCollision(view &);

  void  checkCollision(std::shared_ptr<element>, std::shared_ptr<element>, std::shared_ptr<handlerSprite>);
  void  checkBorderCollision(std::shared_ptr<element>, view &);

  //object* fireOrder(ship *, DIRECTION);
  std::vector<std::shared_ptr<object>> fireOrder(std::shared_ptr<ship>, DIRECTION, bool);

  void                  TileTheMap(int, int, std::array<int, 3> &);
  void                  generateEnnemys(int, std::array<int, 3> &, int, std::shared_ptr<handlerSprite>);
  void                  createWaveEnnemys(int, std::array<int, 3> &, std::shared_ptr<handlerSprite>);

  void                  setKeyMap(std::map<KEY, STATE> &);

  void                  returnVertexVectorMovableObject(std::vector<drawableClass> &);
  int                   deleteDeadElems();
};

#endif
