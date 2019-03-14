#include "../include/handlerSprite.hh"
#include <array>

handlerSprite::handlerSprite()
{
  if (vectorTextures[0].loadFromFile("./ressources/background2.png", sf::IntRect(0, 0, 125, 80)) == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  if (vectorTextures[1].loadFromFile("./ressources/guardious.png") == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  if (vectorTextures[2].loadFromFile("./ressources/simpleEnnemy.png") == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  if (vectorTextures[3].loadFromFile("./ressources/boss.png") == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  if (vectorTextures[4].loadFromFile("./ressources/Fireball1.png") == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  if (vectorTextures[5].loadFromFile("./ressources/explosion.png") == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  vectorTextures[0].setRepeated(true);
  vectorTextures[1].setRepeated(true);
  vectorTextures[2].setRepeated(true);
  vectorTextures[3].setRepeated(true);
  vectorTextures[4].setRepeated(true);
  vectorTextures[5].setRepeated(true);
}

handlerSprite::~handlerSprite()
{
}

//ATTENTION JE NE SAIS PLUS POURQUOI MAIS LES VALEURS 125 & 80 DE LA FONCTION SERVENT AU BON FONCTIONNEMENT DU BACKGROUND
//CES VALEURS SONT LES VALEURS PAR DEFAUT DE X ET Y
bool  handlerSprite::makeSprite(std::string path, int x, int y)
{
  if (this->texture.loadFromFile(path, sf::IntRect(0, 0, x, y)) == false)
    {
      std::cerr << "Impossible de charger la texture demandée" << std::endl;
      return (false);
    }
  this->texture.setRepeated(true);
  this->sprite.setTexture(this->texture);
  return (true);
}

bool  handlerSprite::makeVertexSprite(std::string path, int x, int y, int pos_tex_x, int pos_tex_y)
{
  //tableau de vertex Part

  if (this->texture_vertex.loadFromFile(path) == false)
    {
      std::cerr << "Impossible de charger la texture demandée" << std::endl;
      return (false);
    }

    this->x = x;//x et y peut-etre en trop
    this->y = y;
    this->width = x;
    this->height = y;
    this->defineOrigin(x, y);

    this->vertex_array.setPrimitiveType(sf::Quads);
    this->vertex_array.resize(4);
    // on le définit comme un rectangle, placé en (125, 80) (y_rec_pos, x_rec_pos) et de taille 200x150 y_rec x x_rec
    this->vertex_array[0].position = sf::Vector2f(0, 0);
    this->vertex_array[1].position = sf::Vector2f(x, 0);
    this->vertex_array[2].position = sf::Vector2f(x, y);
    this->vertex_array[3].position = sf::Vector2f(0, y);


    // et on définit la zone de texture à lui appliquer comme étant le rectangle de 140x80(y_tex, x_tex) démarrant en (0, 0)
    this->vertex_array[0].texCoords = sf::Vector2f(pos_tex_x, pos_tex_y);
    this->vertex_array[1].texCoords = sf::Vector2f(x, pos_tex_y);//X/Y
    this->vertex_array[2].texCoords = sf::Vector2f(x, y);
    this->vertex_array[3].texCoords = sf::Vector2f(pos_tex_x, y);

    return (true);
}

void  handlerSprite::makeMyVertexArray(sf::VertexArray &copyVA, int x, int y, int pos_tex_x, int pos_tex_y)
{
  //tableau de vertex Part

    this->x = x;//x et y peut-etre en trop
    this->y = y;
    this->width = x;
    this->height = y;

    copyVA.setPrimitiveType(sf::Quads);
    copyVA.resize(4);
    // on le définit comme un rectangle, placé en (125, 80) (y_rec_pos, x_rec_pos) et de taille 200x150 y_rec x x_rec
    copyVA[0].position = sf::Vector2f(0, 0);
    copyVA[1].position = sf::Vector2f(x, 0);
    copyVA[2].position = sf::Vector2f(x, y);
    copyVA[3].position = sf::Vector2f(0, y);


    // et on définit la zone de texture à lui appliquer comme étant le rectangle de 140x80(y_tex, x_tex) démarrant en (0, 0)
    copyVA[0].texCoords = sf::Vector2f(pos_tex_x, pos_tex_y);
    copyVA[1].texCoords = sf::Vector2f(x, pos_tex_y);//X/Y
    copyVA[2].texCoords = sf::Vector2f(x, y);
    copyVA[3].texCoords = sf::Vector2f(pos_tex_x, y);
}

/*void  handlerSprite::repeatTexture()
{
  this->texture.setRepeated(true);
}*/

/*
OLD
void  handlerSprite::defineRectSprite(int x, int y)
{
  this->sprite.setTextureRect({0, 0, x, y});
}
*/

sf::Sprite&  handlerSprite::getSprite()
{
  return (this->sprite);
}

int  handlerSprite::getX()
{
  return(this->x);
}

int  handlerSprite::getY()
{
  return(this->y);
}

/*sf::Vector2f  handlerSprite::getPosition()
{
  sf::Vector2f  vec;
  vec = sf::Vector2f(this->x, this->y);

  return (vec);
}*/

int handlerSprite::getWidth()
{
  return (this->width);
}

int handlerSprite::getHeight()
{
  return (this->height);
}

std::array<float, 4>  handlerSprite::getWidthHeight()
{
  std::array<float, 4>  arr;

  arr[2] = this->width;
  arr[3] = this->height;
  return (arr);
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

void handlerSprite::defineOrigin(int x, int y)
{
  this->origin_x = x / 2;
  this->origin_y = y / 2;
  this->setOrigin(this->origin_x, this->origin_y);
}

void  handlerSprite::texturize(sf::RenderStates &states, int val)
{
    states.texture = &this->vectorTextures[val];
}

void handlerSprite::texturizeMySprite(sf::Sprite &copyS, int val)
{
  copyS.setTexture(this->vectorTextures[val]);
}

sf::Texture  *handlerSprite::getTexture(int val)
{
  return (&this->vectorTextures[val]);
}
