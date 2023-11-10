#include "bankir.h"
#include "kortlek.h"
#include "kort.h"
#include "korthand.h"
#include "spelare.h"
#include <iostream>
using namespace  std;
Bankir::Bankir()
{
    m_pSpelare = nullptr;
}

void Bankir::registreraSpelare(Spelare *pSpelare)
{
    //ska lagra den bifogade pekaren i m_pSpelare
    m_pSpelare = pSpelare;
}

bool Bankir::harRegistreradeSpelare() const
{
    if(m_pSpelare!= nullptr)
        return true;
    else return false;
}

void Bankir::spelaEnOmgang()
{
    /// skall spela en omgång mot spelaren..
    if (m_pSpelare==nullptr)
        return;
    if (m_kortlek.antalkort()<15){
        m_kortlek.aterstallBlandadkortlek();
        (*m_pSpelare).kortlekenHarBlandats();
    }
    if((*m_pSpelare).villSpela()){
        Kort k = m_kortlek.utplockatkort();
        (*m_pSpelare).tagEmotkort(k);
        while((*m_pSpelare).korthand().poang()<21 &&(m_pSpelare->villHaKort())){
            Kort k = m_kortlek.utplockatkort();
            (*m_pSpelare).tagEmotkort(k);
        }
        const int spelarpoang = (*m_pSpelare).korthand().poang();
        if(spelarpoang > 21)
            (*m_pSpelare).speletAvslutat(false);
        else if (spelarpoang==21)
            (*m_pSpelare).speletAvslutat(true);
        else{
            Korthand bankhand;
            while(bankhand.poang() < 16){
                Kort kort = m_kortlek.utplockatkort();
                bankhand.stoppaInkort(kort);
                (*m_pSpelare).bankentagKort(kort);
            }
            int bankpoang = bankhand.poang();
            bool spelarenVann = bankpoang > 21 || spelarpoang > bankpoang;
            (*m_pSpelare).speletAvslutat(spelarenVann);
        }
    }
    else m_pSpelare = nullptr;
}
