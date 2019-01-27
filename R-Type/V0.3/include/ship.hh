#ifndef SHIP_HH_
# define SHIP_HH_

#include "element.hh"
#include "object.hh"
#include <vector>

class ship : public element
{

  std::vector<object *> fire_list;

public:
  ship();
  ~ship();

  void getTexture(std::string &);
  virtual STRATEGY  getStrategy();

  object*               fireing(DIRECTION);
  std::vector<object *> getFireList();
};

#endif
