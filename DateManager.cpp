#include "DateManager.h"

string DateManager::findToday() {

    int yearToday, monthToday, dayToday;
    string dateTodayString, yearTodayString, monthTodayString, dayTodayString;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    yearToday = 1900 + ltm->tm_year;
    dateObject.setYear(yearToday);
    yearTodayString = AuxiliaryMethods::convertIntToString(yearToday);

    monthToday = 1 + ltm->tm_mon;
    dateObject.setMonth(monthToday);
    monthTodayString = AuxiliaryMethods::convertIntToString(monthToday);

    dayToday = ltm->tm_mday;
    dateObject.setDay(dayToday);
    dayTodayString = AuxiliaryMethods::convertIntToString(dayToday);

    dateTodayString = yearTodayString + monthTodayString + dayTodayString;
    dateTodayString = AuxiliaryMethods::addDashToDate(dateTodayString);

   // cout << "Today is: " << dateTodayString << endl;
    //cout << endl;

    return dateTodayString;
}

int DateManager::getNumberOfDaysInMonth(int month, int year) {
    //leap year condition, if month is February
    if( month == 2) {
        if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;

        else
            return 28;
    }
    //months which has 31 days
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8	|| month == 10 || month == 12)
        return 31;

    else
        return 30;
}

void DateManager::compareDate() {

    string startDate, endDate;

    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    string startDayString, startMonthString, startYearString;
    string endDayString, endMonthString, endYearString;

    cout << "Enter start date: " << endl;
    cin >> startDate;
    cout << endl;
    cout << "Enter end date: " << endl;
    cin >> endDate;
    cout << endl;

    startYearString = startDate;
    startYearString = startYearString.erase(4,6);
    startYear = AuxiliaryMethods::convertStringToInt(startYearString);

    endYearString = endDate;
    endYearString = endYearString.erase(4,6);
    endYear = AuxiliaryMethods::convertStringToInt(endYearString);

    startMonthString = startDate;
    startMonthString = startMonthString.substr(5,2);
    startMonth = AuxiliaryMethods::convertStringToInt(startMonthString);

    endMonthString = endDate;
    endMonthString = endMonthString.substr(5,2);
    endMonth = AuxiliaryMethods::convertStringToInt(endMonthString);

    startDayString = startDate;
    startDayString = startDayString.substr(8,2);
    startDay = AuxiliaryMethods::convertStringToInt(startDayString);

    endDayString = endDate;
    endDayString = endDayString.substr(8,2);
    endDay = AuxiliaryMethods::convertStringToInt(endDayString);

    if (startDate != endDate) {
        cout << "Result of comparison: " << endl;
        if (startYear < endYear)
            cout << startDate << " < " << endDate << endl;
        else if (startYear > endYear)
            cout << startDate << " > " << endDate << endl;
        else if (startYear == endYear) {

            if (startMonth < endMonth)
                cout << startDate << " < " << endDate << endl;
            else if (startMonth > endMonth)
                cout << startDate << " > " << endDate << endl;
            else if (startMonth == endMonth) {

                if (startDay < endDay)
                    cout << startDate << " < " << endDate << endl;
                else if (startDay > endDay)
                    cout << startDate << " > " << endDate << endl;
            }
        }
        cout << endl;
        system("pause");
    }
}

bool DateManager::isDateInRange (string checkDate, string startDate, string endDate) {
    int checkDayInt, checkMonthInt, checkYearInt;
    int startDayInt, startMonthInt, startYearInt;
    int endDayInt, endMonthInt, endYearInt;

    string checkDayString, checkMonthString, checkYearString;
    string startDayString, startMonthString, startYearString;
    string endDayString, endMonthString, endYearString;

 //*** Get Year ***//
    checkYearString = checkDate;
    checkYearString = checkYearString.erase(4,6);
    checkYearInt = AuxiliaryMethods::convertStringToInt(checkYearString);

    startYearString = startDate;
    startYearString = startYearString.erase(4,6);
    startYearInt = AuxiliaryMethods::convertStringToInt(startYearString);

    endYearString = endDate;
    endYearString = endYearString.erase(4,6);
    endYearInt = AuxiliaryMethods::convertStringToInt(endYearString);

 //*** Get Month ***//
    checkMonthString = checkDate;
    checkMonthString = checkMonthString.substr(5,2);
    checkMonthInt = AuxiliaryMethods::convertStringToInt(checkMonthString);

    startMonthString = startDate;
    startMonthString = startMonthString.substr(5,2);
    startMonthInt = AuxiliaryMethods::convertStringToInt(startMonthString);

    endMonthString = endDate;
    endMonthString = endMonthString.substr(5,2);
    endMonthInt = AuxiliaryMethods::convertStringToInt(endMonthString);

 //*** Get Day ***//
    checkDayString = checkDate;
    checkDayString = checkDayString.substr(8,2);
    checkDayInt = AuxiliaryMethods::convertStringToInt(checkDayString);

    startDayString = startDate;
    startDayString = startDayString.substr(8,2);
    startDayInt = AuxiliaryMethods::convertStringToInt(startDayString);

    endDayString = endDate;
    endDayString = endDayString.substr(8,2);
    endDayInt = AuxiliaryMethods::convertStringToInt(endDayString);

//*** Checking date ***//
    int checkDateInt = (checkYearInt * 10000) + (checkMonthInt * 100) + checkDayInt;
    int startDateInt = (startYearInt * 10000) + (startMonthInt * 100) + startDayInt;
    int endDateInt = (endYearInt * 10000) + (endMonthInt * 100) + endDayInt;

    if (checkDateInt >= startDateInt && checkDateInt <= endDateInt){
        return true;
    }
    else{
        return false;
    }
}

string DateManager::getLastMonthFirstDay() {
    string today = findToday();
    string lmfdDateString, lmfdYearString, lmfdMonthString, lmfdDayString = "01";
    int lmfdYear, lmfdMonth;

    lmfdMonthString = today;
    lmfdMonthString = lmfdMonthString.substr(5,2);
    lmfdMonth = AuxiliaryMethods::convertStringToInt(lmfdMonthString);
    lmfdMonth = lmfdMonth - 1;

    lmfdYearString = today;
    lmfdYearString = lmfdYearString.erase(4,6);

    if (lmfdMonth != 0) {
        lmfdMonthString = AuxiliaryMethods::convertIntToString(lmfdMonth);
    } else {
        lmfdMonth = 12;
        lmfdMonthString = AuxiliaryMethods::convertIntToString(lmfdMonth);

        lmfdYear = AuxiliaryMethods::convertStringToInt(lmfdYearString);
        lmfdYear = lmfdYear - 1;
        lmfdYearString = AuxiliaryMethods::convertIntToString(lmfdYear);
    }

    lmfdDateString = lmfdYearString + lmfdMonthString + lmfdDayString;
    lmfdDateString = AuxiliaryMethods::addDashToDate(lmfdDateString);

    return lmfdDateString;
}

string DateManager::getCurretntMonthFirstDay() {

    string today = findToday();
    string cmfdDateString, cmfdYearString, cmfdMonthString, cmfdDayString = "01";

    cmfdMonthString = today;
    cmfdMonthString = cmfdMonthString.substr(5,2);

    cmfdYearString = today;
    cmfdYearString = cmfdYearString.erase(4,6);

    cmfdDateString = cmfdYearString + cmfdMonthString + cmfdDayString;
    cmfdDateString = AuxiliaryMethods::addDashToDate(cmfdDateString);

    return cmfdDateString;
}

string DateManager::getLastMonthLastDay() {
    string today = findToday();
    string lmldDateString, lmldYearString, lmldMonthString, lmldDayString;
    int lmldYear, lmldMonth, lmldDay;

    lmldMonthString = today;
    lmldMonthString = lmldMonthString.substr(5,2);
    lmldMonth = AuxiliaryMethods::convertStringToInt(lmldMonthString);
    lmldMonth = lmldMonth - 1;

    lmldYearString = today;
    lmldYearString = lmldYearString.erase(4,6);
    lmldYear = AuxiliaryMethods::convertStringToInt(lmldYearString);

    if (lmldMonth != 0) {
        lmldMonthString = AuxiliaryMethods::convertIntToString(lmldMonth);
    }

    else {
        lmldMonth = 12;
        lmldMonthString = AuxiliaryMethods::convertIntToString(lmldMonth);

        lmldYear = AuxiliaryMethods::convertStringToInt(lmldYearString);
        lmldYear = lmldYear - 1;
        lmldYearString = AuxiliaryMethods::convertIntToString(lmldYear);
    }

    lmldDay = getNumberOfDaysInMonth(lmldMonth, lmldYear);
    lmldDayString = AuxiliaryMethods::convertIntToString(lmldDay);

    lmldDateString = lmldYearString + lmldMonthString + lmldDayString;
    lmldDateString = AuxiliaryMethods::addDashToDate(lmldDateString);

    return lmldDateString;
}

int DateManager::getDayFromDate (string date) {
    string dayStr;
    int day;

    dayStr = date.substr(8,2);
    day = AuxiliaryMethods::convertStringToInt(dayStr);
    return day;
}

int DateManager::getMonthFromDate (string date) {
    string monthStr;
    int month;

    monthStr = date.substr(5,2);
    month = AuxiliaryMethods::convertStringToInt(monthStr);
    return month;
}
