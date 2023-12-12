#ifndef HELPERMETHOD_H
#define HELPERMETHOD_H
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <sstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class HelperMethod
{

public:
    static string getLine();
    static string replaceWithCapitalLetter(string word);
    static string replaceTheCommaWithDot(string word);
    static string convertAmountToString(float amount);
    static string checkLengthString(string data);
    static bool passwordLength(string password);
    static int getDigit();
    static int convertionStringToInt(string digit);
    static float convertionStringToFloat(string digit);

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
