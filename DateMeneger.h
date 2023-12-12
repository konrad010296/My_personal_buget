#ifndef DATEMENEGER_H
#define DATEMENEGER_H
#include "HelperMethod.h"
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <sstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class DateMeneger
{
    public:
    static string getCurrentDate();
    static string changeDateToBeginningMonth(string word);
    static string dateSeparatedByDashes(int date);
    static string getBeginningPerviousMonth(string actualDate);
    static int connectLastDayWitchCurrentMounth(int date, int day);
    static int convetionDateToInt(string date);
    static int calculateDaysInMonth(string date);
    static bool askAboutDate();
    static bool checkDateFormat(string date);
    static bool checkDateRage(string date);
};
#endif
