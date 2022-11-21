#include "Date.h"

void Date::setYear (int newYear) {
    if (newYear >= 1900)
        year = newYear;
}
void Date::setMonth (int newMonth) {
    if ((newMonth > 0) && (newMonth < 13))
        month = newMonth;
}
void Date::setDay (int newDay) {
    if ((newDay > 0) && (newDay < 32))
        day = newDay;
}
int Date::getYear() {
    return year;
}
int Date::getMonth() {
    return month;
}
int Date::getDay() {
    return day;
}
