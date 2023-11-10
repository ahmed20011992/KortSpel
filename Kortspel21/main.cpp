#include <iostream>
#include "bankir.h"
#include "spelare.h"
#include "korthand.h"
#include "kortlek.h"


using namespace std;

int main()
{
    cout<< "kortspelet 21" << endl;

    Bankir bank;
    Spelare spelare;
    bank.registreraSpelare(&spelare);

    while(bank.harRegistreradeSpelare())
        bank.spelaEnOmgang();

    return 0;
}
