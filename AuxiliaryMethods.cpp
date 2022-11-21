#include "AuxiliaryMethods.h"

int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string strNumber = ss.str();
    return strNumber;
}

string AuxiliaryMethods::addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    return stringDateWithDash;
}

char AuxiliaryMethods::loadCharacter() {
    string in = "";
    char character  = {0};

    while (true) {
        getline(cin, in);

        if (in.length() == 1) {
            character = in[0];
            break;
        }
    }
    return character;
}
