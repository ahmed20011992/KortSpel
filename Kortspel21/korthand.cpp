#include "korthand.h"
#include "kort.h"
#include <vector>

Korthand::Korthand()
{

}

void Korthand::rensa()
{
    m_Korten.clear();
}

int Korthand::antalkort() const
{
   m_Korten.size();
}

Kort Korthand::kort(int nr) const
{
    return m_Korten[nr];
}

void Korthand::stoppaInkort(const Kort &kort)
{
    m_Korten.push_back(kort);
}

int Korthand::poang() const
{
    int antalpoang = 0;
    int antalEss = 0;

    for(int i = 0; i < m_Korten.size(); i++) {
        Kort dettaKort = m_Korten[i];
        int dettaKortsPoang = dettaKort.valor();

        antalpoang += dettaKortsPoang;
        if(dettaKortsPoang == 1)
            antalEss += 1;
    }

    if(antalEss >= 1)
        if(antalpoang + 13 <= 21)
            antalpoang += 13;

    return antalpoang;
}
