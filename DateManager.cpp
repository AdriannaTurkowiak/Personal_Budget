#include "DateManager.h"

string DateManager::findToday() {

    int yearToday, monthToday, dayToday;
    string dateTodayString, yearTodayString, monthTodayString, dayTodayString;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    yearToday = 1900 + ltm->tm_year;
    dateObject.setYear(yearToday);
    yearTodayString = convertIntToString(yearToday);

    monthToday = 1 + ltm->tm_mon;
    dateObject.setMonth(monthToday);
    monthTodayString = convertIntToString(monthToday);

    dayToday = ltm->tm_mday;
    dateObject.setDay(dayToday);
    dayTodayString = convertIntToString(dayToday);

    dateTodayString = yearTodayString + monthTodayString + dayTodayString;
    dateTodayString = addDashToDate(dateTodayString);

    cout << "Today is: " << dateTodayString << endl;
    cout << endl;
    system("pause");

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
    startYear = convertStringToInt(startYearString);

    endYearString = endDate;
    endYearString = endYearString.erase(4,6);
    endYear = convertStringToInt(endYearString);

    startMonthString = startDate;
    startMonthString = startMonthString.substr(5,2);
    startMonth = convertStringToInt(startMonthString);

    endMonthString = endDate;
    endMonthString = endMonthString.substr(5,2);
    endMonth = convertStringToInt(endMonthString);

    startDayString = startDate;
    startDayString = startDayString.substr(8,2);
    startDay = convertStringToInt(startDayString);

    endDayString = endDate;
    endDayString = endDayString.substr(8,2);
    endDay = convertStringToInt(endDayString);

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
int DateManager::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string DateManager :: convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string strNumber = ss.str();
    return strNumber;
}
string DateManager::getLastMonthFirstDay() {
    string today = findToday();
    string lmfdDateString, lmfdYearString, lmfdMonthString, lmfdDayString = "01";
    int lmfdYear, lmfdMonth;

    lmfdMonthString = today;
    lmfdMonthString = lmfdMonthString.substr(5,2);
    lmfdMonth = convertStringToInt(lmfdMonthString);
    lmfdMonth = lmfdMonth - 1;

    lmfdYearString = today;
    lmfdYearString = lmfdYearString.erase(4,6);

    if (lmfdMonth != 0) {
        lmfdMonthString = convertIntToString(lmfdMonth);
    } else {
        lmfdMonth = 12;
        lmfdMonthString = convertIntToString(lmfdMonth);

        lmfdYear = convertStringToInt(lmfdYearString);
        lmfdYear = lmfdYear - 1;
        lmfdYearString = convertIntToString(lmfdYear);
    }

    lmfdDateString = lmfdYearString + lmfdMonthString + lmfdDayString;
    lmfdDateString = addDashToDate(lmfdDateString);

    cout << "First day of last month was: " << lmfdDateString << endl;
    cout << endl;
    system("pause");

    return lmfdDateString;
}
string DateManager::getLastMonthLastDay() {
    string today = findToday();
    string lmldDateString, lmldYearString, lmldMonthString, lmldDayString;
    int lmldYear, lmldMonth, lmldDay;

    lmldMonthString = today;
    lmldMonthString = lmldMonthString.substr(5,2);
    lmldMonth = convertStringToInt(lmldMonthString);
    lmldMonth = lmldMonth - 1;

    lmldYearString = today;
    lmldYearString = lmldYearString.erase(4,6);
    lmldYear = convertStringToInt(lmldYearString);

    if (lmldMonth != 0) {
        lmldMonthString = convertIntToString(lmldMonth);
    }

    else {
        lmldMonth = 12;
        lmldMonthString = convertIntToString(lmldMonth);

        lmldYear = convertStringToInt(lmldYearString);
        lmldYear = lmldYear - 1;
        lmldYearString = convertIntToString(lmldYear);
    }

    lmldDay = getNumberOfDaysInMonth(lmldMonth, lmldYear);
    lmldDayString = convertIntToString(lmldDay);

    lmldDateString = lmldYearString + lmldMonthString + lmldDayString;
    lmldDateString = addDashToDate(lmldDateString);

    cout << "Last day of last month was: " << lmldDateString << endl;
    cout << endl;
    system("pause");

    return lmldDateString;
}
string DateManager :: addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    return stringDateWithDash;
}
