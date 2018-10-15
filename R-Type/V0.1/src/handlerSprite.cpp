#include "../include/handlerSprite.hh"

handlerSprite::handlerSprite()
{
}

handlerSprite::~handlerSprite()
{
}

bool  handlerSprite::makeSprite(std::string path)
{
  if (this->texture.loadFromFile(path, sf::IntRect(0, 0, 125, 80)) == false)
    {
      std::cerr << "Impossible de charger la texture demandée" << std::endl;
      return (false);
    }
  this->sprite.setTexture(this->texture);
  return (true);
}

bool  handlerSprite::makeVertexSprite(std::string path)
{
  //tableau de vertex Part


  if (this->texture_vertex.loadFromFile(path) == false)
    {
      std::cerr << "Impossible de charger la texture demandée" << std::endl;
      return (false);
    }

    this->vertex_array.setPrimitiveType(sf::Quads);
    this->vertex_array.resize(4);
    // on le définit comme un rectangle, placé en (125, 80) et de taille 200x150
    this->vertex_array[0].position = sf::Vector2f(125, 80);
    this->vertex_array[1].position = sf::Vector2f(200, 80);
    this->vertex_array[2].position = sf::Vector2f(200, 150);
    this->vertex_array[3].position = sf::Vector2f(80, 150);

    // et on définit la zone de texture à lui appliquer comme étant le rectangle de 25x50 démarrant en (0, 0)
    this->vertex_array[0].texCoords = sf::Vector2f(0, 0);
    this->vertex_array[1].texCoords = sf::Vector2f(140, 0);
    this->vertex_array[3].texCoords = sf::Vector2f(0, 80);
    this->vertex_array[2].texCoords = sf::Vector2f(140, 80);

    return (true);
}

sf::Sprite&  handlerSprite::getSprite()
{
  return (this->sprite);
}

void handlerSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
        states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

        // on applique la texture
        states.texture = &this->texture_vertex;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // on dessine le tableau de vertex
        target.draw(vertex_array, states);
}
