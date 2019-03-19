#ifndef OBJECT_HH_
# define OBJECT_HH_

#include "config.hh"
#include "element.hh"
#include <memory>

enum class TYPE {ATTACK, EXPLOSION, SHIELD};
enum class DIRECTION {LEFT, RIGHT};

class object : public element
{
private:

  float     speed;
  DIRECTION direction;
  TYPE      type;

public:
  object();
  object(std::shared_ptr<handlerSprite>, TYPE);
  object(std::shared_ptr<handlerSprite>, TYPE, DIRECTION);
  ~object();

  DIRECTION getDirection();
};

#endif
