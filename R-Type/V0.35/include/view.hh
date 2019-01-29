#ifndef VIEW_HH_
# define VIEW_HH_

#include <SFML/Graphics.hpp>
#include "background.hh"

class view
{
  background  *my_background;
  sf::View    my_view;

public:
  view();
  ~view();

  void  move(float, float);

  void  setView(sf::View);
  void  defineBackground(std::string, int, int);

  sf::View&   getView();
  sf::Sprite& getBackground();

  /*view& operator=(const view &);*/
};

#endif
