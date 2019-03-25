#include "drawableClass.hh"

drawableClass::drawableClass()
{

}

drawableClass::~drawableClass()
{

}

sf::VertexArray&  drawableClass::getVertexArray()
{
  return (this->vertex_array);
}

void              drawableClass::setTextureRef(sf::Texture *text)
{
  this->textureRef = text;
}

void              drawableClass::setSprite(sf::Texture *text)
{
  this->sprite.setTexture(*text);
}

void              drawableClass::setSpritePosition(float x, float y)
{
  this->sprite.setPosition(x, y);
}

bool              drawableClass::setFontText(std::string str)
{
  std::map<std::string, sf::Text>::iterator it;

  if (!this->font.loadFromFile(str))
    return (false);
  for (it = this->map_text.begin(); it != this->map_text.end(); it++)
    it->second.setFont(this->font);
  return (true);
}

void              drawableClass::addText(std::string str, int size)
{
  sf::Text        text;

  text.setString(str);
  text.setFont(this->font);
  text.setCharacterSize(size);
  this->map_text.insert(std::pair<std::string, sf::Text>(str, text));
}

void              drawableClass::setTextPosition(std::string str, float x, float y)
{
  this->map_text.find(str)->second.setPosition(x, y);
}

void              drawableClass::setColorText(std::string str, sf::Color color)
{
  this->map_text.find(str)->second.setFillColor(color);
}

sf::FloatRect     drawableClass::getBoundsText(std::string str)
{
  return (this->map_text.find(str)->second.getGlobalBounds());
}

sf::Sprite&       drawableClass::getSprite()
{
  return (this->sprite);
}

std::map<std::string, sf::Text>& drawableClass::getMapText()
{
  return (this->map_text);
}

void              drawableClass::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
        states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

        // on applique la texture
        //states.texture = &this->texture;
        states.texture = this->textureRef;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // on dessine le tableau de vertex
        target.draw(vertex_array, states);
}
