#include "DateManager.h"

void DateManager::findYear(string date) {
    return;
}

Date DateManager::findToday() {
    int yearToday, monthToday, dayToday;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    yearToday = 1900 + ltm->tm_year;
    dateObject.setYear(yearToday);

    monthToday = 1 + ltm->tm_mon;
    dateObject.setMonth(monthToday);

    dayToday = ltm->tm_mday;
    dateObject.setDay(dayToday);

    /*cout << "Year: " << dateObject.getYear() << endl;
    cout << "Month: " << dateObject.getMonth() << endl;
    cout << "Day: " << dateObject.getDay() << endl;*/

    return dateObject;
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
string DateManager::removeDashFromDate(string dateBefore) {

    string dateAfter;

    for (int i = 0 ; i <= dateBefore.length(); i++) {
        if (dateBefore[i] != '-') {
            dateAfter += dateBefore[i];
        }
    }
    return dateAfter;
}
int DateManager::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
