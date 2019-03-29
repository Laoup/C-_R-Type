#include "factory.hh"

factoryPrototype::~factoryPrototype()
{

}

std::map<string, std::shared_ptr<element>> FactoryFigure::m_map = std::map<string, std::shared_ptr<element>>();

void factoryFigure::Register(const string& key, std::shared_ptr<element> obj)
{
        //si la clé n'est pas déjà présente
        if(m_map.find(key)==m_map.end())
                   {
                //on ajoute l'objet dans la map
                m_map[key]=obj;
                }

       //on pourrait détruire obj mais cette tâche ne revient pas à Register
}

Figure* factoryFigure::create(const std::string& key) const
{
            std::shared_ptr<element> tmp = std::make_shared<element>();
            std::map<string, std::shared_ptr<element>>::const_iterator it=m_map.find(key);

                //si l'itérateur ne vaut pas map.end(), cela signifie que que la clé à été trouvée
                if(it!=m_map.end())
                {
                          tmp=((*it).second)->Clone();
                      }

                //on pourrait lancer une exeption si la clé n'a pas été trouvée

                return tmp;
}
