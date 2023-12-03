#ifndef HELPERMETHOD_H
#define HELPERMETHOD_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

class HelperMethod
{

public:
    static string getLine();
    static int convertionStringToInt(string digit);
    static string getCurrentDate();
    static string checkLengthString(string data);
};
#endif
