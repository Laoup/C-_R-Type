#ifndef IGAME_HH_
# define IGAME_HH_

#include <SFML/Graphics.hpp>
#include "config.hh"
#include "handlerWindow.hh"
#include "handlerKeyMapping.hh"
#include "handlerSprite.hh"
#include "physiqueManager.hh"
#include "view.hh"
#include "musicManager.hh"
#include "drawableClass.hh"
#include <memory>

class IGame
{
  handlerWindow         handler_window;
  handlerKeyMapping     handler_key;

  physiqueManager         m_physique;
  view                    handler_view;
  std::shared_ptr<handlerSprite> sprite_manager;
  //musicManager            music_manager;

public:
  IGame();
  virtual ~IGame();

  virtual void  launchGame() = 0;

  virtual void  initializeTheGame() = 0;

  virtual void  applyTurn() = 0;

  virtual int   menu() = 0;
  virtual int   endScreen() = 0;
  virtual void  initializeLockedScreen() = 0;

  handlerWindow&    getHandlerWindow();
  handlerKeyMapping&      getHandlerKey();
  physiqueManager&  getPhysiqueManager();
  view&             getHandlerView();
  std::shared_ptr<handlerSprite>  getSpriteManager();
};

#endif
