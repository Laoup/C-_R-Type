#ifndef SHIP_HH_
# define SHIP_HH_

#include "element.hh"
#include "object.hh"
#include <memory>
#include <vector>

class ship : public element
{

  std::vector<object *> fire_list;
  bool                  boss;
  //bool                  imortal;

  bool                  memorie;

public:
  ship();
  ship(std::shared_ptr<handlerSprite>);
  ~ship();

  virtual STRATEGY  getStrategy();

  //object*               fireing(DIRECTION);
  std::shared_ptr<object> fireing(DIRECTION);
  std::vector<object *>   getFireList();

  void  promote();
  bool  getBoss();

  //sf::Vector2f getPosition();

  void  setMemorie(bool);
  bool  getMemorie();

  //void  setImortal(bool);
  //bool  getImortal();
};

#endif
