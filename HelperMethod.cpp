#include "HelperMethod.h"

string HelperMethod::checkLengthString(string data){

        if(data.length() == 1){
        data = "0" + data;
        return data;
    }
    else
        return data;
}

string HelperMethod::getLine()
{

    string line = "";
    getline(cin, line);

    return line;
}

int HelperMethod::convertionStringToInt(string digit)
{
    int toInt;
    istringstream iss(digit);
    iss >> toInt;

    return toInt;
}

string HelperMethod::getCurrentDate(){

    time_t now = time(0);
    tm* ltm = localtime(&now);
    string currentData = "";

    string year = to_string(1900 + ltm->tm_year);
    string month = checkLengthString(to_string(1 + ltm->tm_mon));
    string day = checkLengthString(to_string(ltm->tm_mday));

    currentData = year + "-" + month + "-" + day;
    return currentData;
}
