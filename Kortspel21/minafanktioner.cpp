#include "minafanktioner.h"

#include <iostream>
using namespace std;
bool boolFranAnvandare(const string &txt){

    cout << "Vill du ha ett nytt kort?"<< endl;
    string bb = txt;
    cin >> bb;
    if(bb == "ja")
        return true;
    else if (bb == "nej")
        return false;

}
