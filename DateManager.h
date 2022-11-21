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
    void findYear(string date);
    string findToday();
    int getNumberOfDaysInMonth(int month, int year);
    void compareDate();
    string getLastMonthFirstDay();
    string getLastMonthLastDay();
};
#endif
