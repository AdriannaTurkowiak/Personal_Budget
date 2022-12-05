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
        cin.sync();
        getline(cin, in);

        if (in.length() == 1) {
            character = in[0];
            break;
        }
    }
    return character;
}

float AuxiliaryMethods::convertStringToFloat (string amount) {
    float num_float = std::stof(amount);
    return num_float;
}

string AuxiliaryMethods::loadLine() {
    string in = "";
    cin.sync();
    getline(cin, in);
    return in;
}

string AuxiliaryMethods::convertFloatToString( float amount ) {
    std::stringstream FloatToStr;
    std::string str;

    FloatToStr << amount;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;
}

bool AuxiliaryMethods::isNumber(const string& amount)
{
    int foundComma = amount.find_last_of(",");
    int foundDot = amount.find_last_of(".");

    for (char const &ch : amount) {
        if (std::isdigit(ch) == 0)
            return false;
            else if (foundComma < 0 || foundDot > 0)
                return true;
    }
    return true;
}

