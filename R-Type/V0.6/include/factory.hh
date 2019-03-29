#ifndef FACTORY_HH_
# define FACTORY_HH_

#include "element.hh"
#include <memory>
#include <map>

template <class T> class factoryPrototype
{
public:
  virtual ~factoryPrototype();
  virtual std::shared_ptr<T> clone() const =0;
};

class factoryFigure
{
public:
       static std::map<std::string, std::shared_ptr<element>> m_map;

public:
        //Fonction qui associe clé <=> prototype
        static void Register(const std::string& key,std::shared_ptr<element> obj);

        //Celle qui va créer les objets
        std::shared_ptr<element> create(const std::string& key) const;
};

#endif
