#ifndef SPELARE_H
#define SPELARE_H

#include "kort.h"
#include "korthand.h"

class Spelare
{
public:
    Spelare();
    bool villSpela();
    bool villHaKort() const;
    void tagEmotkort(const Kort &kort);
    void bankentagKort(const Kort &kort) const;
    void kortlekenHarBlandats();
    void speletAvslutat(bool spelarenVann);

    const Korthand& korthand();
private:
   Korthand m_hand;
};

#endif // SPELARE_H
