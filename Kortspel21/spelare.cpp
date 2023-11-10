#include "spelare.h"
#include <string>
#include <iostream>

using namespace std;


Spelare::Spelare()
{

}

bool Spelare::villSpela()
{
    string text;
    cout << "vill du spela mer?" << endl;
    cin >> text ;
    if (text== "ja")
        return true;
    if(text=="nej")
        return false;
}

bool Spelare::villHaKort() const
{
    string text;
    cout<< "vill du ha kort ?" << endl;
    cin >> text ;
    if (text== "ja")
        return true;
    if(text=="nej")
        return false;
}

void Spelare::tagEmotkort(const Kort &kort)
{
//ska addera kort till m_hand och ska skriva ut kortet i terminalförnstret.
//    m_hand+kort(kort);

    m_hand.stoppaInkort(kort);

    cout << "Spelaren tog emot: " << kort.text() << endl;

    // TODO: Skriv ut att kortet tagits emot
}

void Spelare::bankentagKort(const Kort &kort) const
{

}

void Spelare::kortlekenHarBlandats()
{
 cout<< "Kortleken har blandats" << endl;
}

void Spelare::speletAvslutat(bool spelarenVann)
{
/// här ska bara skriva vinnaren i terminalfönster
///
    if (spelarenVann) {
           cout << "Grattis, du vann!" << endl;
       } else {
           cout << "Tyvärr, du förlorade." << endl;
       }
    m_hand.rensa();
}

const Korthand &Spelare::korthand()
{
    //return m_hand; den ska retunera korthand!!!
    return m_hand;
}
