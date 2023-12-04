#include "HelperMethod.h"

string HelperMethod::checkLengthString(string data)
{

    if(data.length() == 1)
    {
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

int HelperMethod::getDigit()
{

    int digit = 0;
    cin >> digit;

    return digit;
}

int HelperMethod::convertionStringToInt(string digit)
{
    int toInt;
    istringstream iss(digit);
    iss >> toInt;

    return toInt;
}

string HelperMethod::getCurrentDate()
{

    time_t now = time(0);
    tm* ltm = localtime(&now);
    string currentData = "";

    string year = to_string(1900 + ltm->tm_year);
    string month = checkLengthString(to_string(1 + ltm->tm_mon));
    string day = checkLengthString(to_string(ltm->tm_mday));

    currentData = year + "-" + month + "-" + day;
    return currentData;
}

bool HelperMethod::askAboutDate()
{
    char choise;

    while((choise != 'y') || (choise != 'o'))
    {
        cout << "Do I want to set today's date? If so click 'y' " << endl;
        cout << "Do I want to set other date? If so click 'o' " << endl;
        choise = getch();

        switch(choise)
        {
        case 'y':
        {
            system("CLS");
            return true;
        }
        break;
        case 'o':
        {
            system("CLS");
            return false;
        }
        break;
        }
        cout << "Correct choise !!" << endl;
        Sleep(2000);
        system("CLS");
    }
}
bool HelperMethod::checkDateFormat(string date)
{
    if((date[4] == '-') && (date[7] == '-'))
    {
        return true;
    }
    else
    {
        cout << "You entered the wrong date format or date is not digit !!" << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
}
int HelperMethod::convetionDateToInt(string date)
{
    string year = "";
    string mounth = "";
    string day = "";
    string fullDate = "";
    int dateToInt;
    year = year + date[0] + date[1] + date[2] + date[3];
    mounth = mounth + date[5] + date[6];
    day = day + date[8] + date[9];
    fullDate = fullDate + year + mounth + day ;

    istringstream iss(fullDate);
    iss >> dateToInt;

    return dateToInt;
}

