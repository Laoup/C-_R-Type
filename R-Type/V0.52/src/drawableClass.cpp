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

void              drawableClass::setTexture(sf::Texture *text)
{
  this->texture = text;
}

void              drawableClass::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
        states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

        // on applique la texture
        //states.texture = &this->texture;
        states.texture = this->texture;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // on dessine le tableau de vertex
        target.draw(vertex_array, states);
}
