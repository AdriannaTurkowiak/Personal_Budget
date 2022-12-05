#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>

#include "Date.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {

public:
    static int getNumberOfDaysInMonth(int month, int year);
    static bool isDateInRange (string checkDate, string startDate, string endDate);
    static string findToday();
    static string getLastMonthFirstDay();
    static string getLastMonthLastDay();
    static string getCurretntMonthFirstDay();
};
#endif
