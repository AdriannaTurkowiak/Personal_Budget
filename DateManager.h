#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sstream>

#include "Date.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {
    Date dateObject;

public:
    string findToday();
    int getNumberOfDaysInMonth(int month, int year);
    string getLastMonthFirstDay();
    string getLastMonthLastDay();
    bool isDateInRange (string checkDate, string startDate, string endDate);
    string getCurretntMonthFirstDay();
};
#endif
