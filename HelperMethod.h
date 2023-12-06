#ifndef HELPERMETHOD_H
#define HELPERMETHOD_H
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <sstream>
#include <conio.h>

using namespace std;

class HelperMethod
{

public:
    static string getLine();
    static int getDigit();
    static int convertionStringToInt(string digit);
    static float convertionStringToFloat(string digit);
    static string getCurrentDate();
    static string checkLengthString(string data);
    static bool askAboutDate();
    static bool checkDateFormat(string date);
    static int convetionDateToInt(string date);
    static bool checkDateRage(string date);
    static int calculateDaysInMonth(int yearDigit,int monthDigit);
    static string replaceWithCapitalLetter(string word);
    static string replaceTheCommaWithDot(string word);
    static string changeDateToBeginningMonth(string word);
    static string connectLastDayWitchCurrentMounth(string date, int day);
    static string dateSeparatedByDashes(int date);
};
#endif
