#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {

public:
    static int convertStringToInt(string number);
    static string convertIntToString(int number);
    static string addDashToDate(string date);
    static char loadCharacter();
    static float convertStringToFloat (string amount);
};
#endif
