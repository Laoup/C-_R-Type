#include "../include/musicManager.hh"
#include <SFML/Audio.hpp>

musicManager::musicManager()
{
  this->game_music.openFromFile("./ressources/stage1_crazy_machine.wav");
  this->game_music.setLoop(true);
}

musicManager::~musicManager()
{

}

void  musicManager::playGameMusic()
{
  this->game_music.play();
}

void  musicManager::stopGameMusic()
{
  this->game_music.stop();
}
