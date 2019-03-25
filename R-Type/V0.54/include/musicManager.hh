#ifndef MUSICMANAGER_HH_
# define MUSICMANAGER_HH_

#include <SFML/Audio.hpp>
//#include <SFML/Music.hpp>

class musicManager
{

  sf::Music game_music;

public:
  musicManager();
  ~musicManager();

  void  playGameMusic();
  void  stopGameMusic();
};

#endif
