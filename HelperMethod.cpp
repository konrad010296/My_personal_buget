#include "HelperMethod.h"

string HelperMethod::getLine()
{

    string line = "";
    getline(cin, line);

    return line;
}

int HelperMethod::convertionStringToInt(string digit) {
    int toInt;
    istringstream iss(digit);
    iss >> toInt;

    return toInt;
}
