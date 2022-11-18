#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sstream>


#include "Date.h"

using namespace std;

class DateManager
{
    Date dateObject;

    public:
    void findYear(string date);
    string findToday();
    int getNumberOfDaysInMonth(int month, int year);
    void compareDate();
    int convertStringToInt(string number);
    string getLastMonthFirstDay();
    string getLastMonthLastDay();
    string addDashToDate(string date);
    string convertIntToString(int number);

};
#endif
