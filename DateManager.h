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
        DateManager()
        {
            dateObject = findToday();
        }
    void findYear(string date);
    Date findToday();
    int getNumberOfDaysInMonth(int month, int year);
    void compareDate();
    string removeDashFromDate(string dateBefore);
    int convertStringToInt(string number);

};
#endif
