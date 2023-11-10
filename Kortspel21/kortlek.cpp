#include "kortlek.h"
#include "assert.h"
#include <random>
#include<chrono>
#include <algorithm>

Kortlek::Kortlek()
{

}

int Kortlek::antalkort() const
{
    return m_korten.size();
}

Kort Kortlek::utplockatkort(){
    assert(!m_korten.empty());
    Kort sistkort = m_korten.back();
    m_korten.pop_back();
    return sistkort;
}


void Kortlek::aterstallkortlek()
{
    m_korten.clear();
    Kort::Farg farger[4]{Kort::hjater, Kort::klover,Kort::spader,Kort::ruter};
    for (int ixFarg=0; ixFarg <4 ;ixFarg +=1){
        for(int varde =1; varde <= 13; varde +=1){
            Kort kort(farger[ixFarg],varde);
            m_korten.push_back(kort);
        }
    }
    assert(m_korten.size() ==52);
}

void Kortlek::blanda()
{
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        static std::default_random_engine slumpgenrator(seed);
        shuffle( m_korten.begin(), m_korten.end(), slumpgenrator);

}

void Kortlek::aterstallBlandadkortlek()
{
    aterstallkortlek();
    blanda();
}
