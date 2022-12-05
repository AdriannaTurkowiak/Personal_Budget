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
    static string convertFloatToString(float amount);
    static string addDashToDate(string date);
    static string loadLine();
    static char loadCharacter();
    static float convertStringToFloat (string amount);
    static bool isNumber(const string& amount);

    };
#endif
