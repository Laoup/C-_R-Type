#include "IGame.hh"

IGame::IGame() : sprite_manager(std::make_shared<handlerSprite> ()), handler_window("R-TYPE")
{
  printf("appel constructeur IGAME\n");
}

IGame::~IGame()
{
  
}

handlerWindow&    IGame::getHandlerWindow()
{
  return (this->handler_window);
}

handlerKeyMapping&      IGame::getHandlerKey()
{
  return (this->handler_key);
}

physiqueManager&  IGame::getPhysiqueManager()
{
  return (this->m_physique);
}

view&             IGame::getHandlerView()
{
  return (this->handler_view);
}

std::shared_ptr<handlerSprite>  IGame::getSpriteManager()
{
  return (this->sprite_manager);
}
