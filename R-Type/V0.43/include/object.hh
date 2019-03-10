#ifndef OBJECT_HH_
# define OBJECT_HH_

#include "config.hh"
#include "element.hh"

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
  object(TYPE);
  object(TYPE, DIRECTION);
  ~object();

  void getTexture(std::string &);
  DIRECTION getDirection();
};

#endif
