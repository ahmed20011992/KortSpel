#ifndef KORTLEK_H
#define KORTLEK_H
#include "kort.h"
#include <vector>



class Kortlek
{
public:
    Kortlek();
    int antalkort() const;
    Kort utplockatkort();
    void aterstallkortlek();
    void blanda();
    void aterstallBlandadkortlek();
private:
    std::vector <Kort> m_korten;
};

#endif // KORTLEK_H
