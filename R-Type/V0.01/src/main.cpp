#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
  sf::RenderWindow  window(sf::VideoMode(800, 600), "My Window");

  // check all the window's events that were triggered since the last iteration of the loop
  sf::Event event;

  sf::Texture texture;
  sf::Sprite  sprite;

  if (texture.loadFromFile("./ressources/Starfighter.png") == false)
    {
      std::cout << "Impossible de charger l'image du vaisseau" << std::endl;
      return (-1);
    }
  else
    sprite.setTexture(texture);

  // run the program as long as the window is open
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
              {
                if (event.key.code == sf::Keyboard::A)
                  std::cout << "Yo PD ! " << std::endl;
              }
        }
        //clear the window with black Color
        window.clear(sf::Color::Black);

        window.draw(sprite);

        //End the current frame
        window.display();
    }
}
