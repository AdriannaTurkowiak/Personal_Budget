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
    Date findToday();
    int getNumberOfDaysInMonth(int month, int year);
    void compareDate();
    int convertStringToInt(string number);
    string getLastMonthFirstDay(Date dateObject);
    string addDashToDate(string date);
    string convertIntToString(int number);

};
#endif
