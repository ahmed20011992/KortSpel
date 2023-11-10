#ifndef KORT_H
#define KORT_H
#include <string>



class Kort
{
public:
    enum Farg{
        klover,ruter,hjater,spader
    };
    Kort(Farg farg, int valor);
    ///Kort(Farg farg, int valor);
    Farg farg() const;
    int valor() const;
    std::string text () const; // retunerar t.ex."klöver sju"
private:
    std::string fargstrang() const;
    Farg m_farg;
    int m_valor;
};

#endif // KORT_H
