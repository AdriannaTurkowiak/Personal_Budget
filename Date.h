#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>

using namespace std;

class Date {
    int year, month, day;
    string date;

public:
     void setYear (int newYear);
     void setMonth (int newMonth);
     void setDay (int newDay);

};
#endif
