#ifndef HANDLERKEYMAPPING_HH_
# define HANDLERKEYMAPPING_HH_

#include <SFML/Graphics.hpp>
#include <map>

enum class  KEY   {NO, UP, DOWN, LEFT, RIGHT, CLOSE};
enum class  STATE {PRESSED, NOTPRESS};

class handlerKeyMapping
{

  sf::Event  event;
  std::map<KEY, STATE> key_map;

public:
  handlerKeyMapping();
  ~handlerKeyMapping();

  void setLastEvent(sf::Event &);

  sf::Event& getEvent();


  std::map<KEY, STATE> returnKey();
  std::map<KEY, STATE> returnKey2();
};

#endif
