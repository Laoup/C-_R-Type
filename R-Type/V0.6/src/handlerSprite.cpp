#include "../include/handlerSprite.hh"
#include <array>

handlerSprite::handlerSprite()
{
  printf("\nconstruction of handlerSprite\n");
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
  if (vectorTextures[6].loadFromFile("./ressources/r_type_logo.png", sf::IntRect(0, 0, 700, 200)) == false)
    std::cerr << "Impossible de charger la texture demandée" << std::endl;
  vectorTextures[0].setRepeated(true);
  vectorTextures[1].setRepeated(true);
  vectorTextures[2].setRepeated(true);
  vectorTextures[3].setRepeated(true);
  vectorTextures[4].setRepeated(true);
  vectorTextures[5].setRepeated(true);
}

handlerSprite::handlerSprite(std::string str)
{
  printf("\nconstruction of handlerSprite + msg = %s\n", str);
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
  if (vectorTextures[6].loadFromFile("./ressources/r_type_logo.png", sf::IntRect(0, 0, 700, 200)) == false)
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
  printf("\nDestruction of handlerSprite\n");
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

void  handlerSprite::makeMyVertexArray(sf::VertexArray &copyVA, int x, int y, int pos_tex_x, int pos_tex_y)
{
  //tableau de vertex Part

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
