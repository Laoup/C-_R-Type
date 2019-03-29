#ifndef IPHYSIQUEMANAGER_HH_
# define IPHYSIQUEMANAGER_HH_

#include "element.hh"
#include "config.hh"
#include "drawableClass.hh"
#include "handlerSprite.hh"
#include "view.hh"
#include <memory>
#include <vector>

class IPhysiqueManager
{
public:

  IPhysiqueManager();
  virtual ~IPhysiqueManager();

  virtual void  moveUp(std::shared_ptr<element>, double = SPEED) = 0;
  virtual void  moveDown(std::shared_ptr<element>, double = SPEED) = 0;
  virtual void  moveLeft(std::shared_ptr<element>, double = SPEED) = 0;
  virtual void  moveRight(std::shared_ptr<element>, double = SPEED) = 0;

  virtual void  applyPlayerTurn(int, bool) = 0;
  virtual void  applyEnnemyTurn(int, std::shared_ptr<handlerSprite>) = 0;

  //void  moveEnnemy(std::shared_ptr<ship>); NON IMPLEMENTABLE A CAUSE DE L'ARGUMENT
  virtual void  moveObjectVector() = 0;

  virtual void  applyObjectsCollision(bool, std::shared_ptr<handlerSprite>) = 0;
  virtual void  applyBordersCollision(view &) = 0;

  virtual void  checkCollision(std::shared_ptr<element>, std::shared_ptr<element>, std::shared_ptr<handlerSprite>) = 0;
  virtual void  checkBorderCollision(std::shared_ptr<element>, view &) = 0;

  virtual void  returnVertexVectorMovableObject(std::vector<drawableClass> &) = 0;
  virtual int   deleteDeadElems() = 0;
};

#endif
