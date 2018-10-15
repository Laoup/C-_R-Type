#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
  sf::RenderWindow  window(sf::VideoMode(800, 600), "My Window");

  //sf::Image   image;
  sf::Texture texture;
  sf::Sprite  sprite;
  sf::Texture texture2;
  sf::Sprite  sprite2;

  if (texture.loadFromFile("./ressources/Starfighter.png") == false || texture2.loadFromFile("./ressources/test.png") == false)
    {
      std::cout << "Impossible de charger l'image du vaisseau" << std::endl;
      return (-1);
    }
  else
    {
      sprite.setTexture(texture);
      sprite2.setTexture(texture2);
    }

  // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //clear the window with black Color
        window.clear(sf::Color::Black);

        window.draw(sprite2);
        window.draw(sprite);

        //End the current frame
        window.display();
    }
}

/*int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}*/
