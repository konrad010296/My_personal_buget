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

float HelperMethod::convertionStringToFloat(string digit)
{
    float num_float = stof(digit);

    return num_float;
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
    string month = "";
    string day = "";
    string fullDate = "";
    int dateToInt;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    fullDate = fullDate + year + month + day ;

    istringstream iss(fullDate);
    iss >> dateToInt;

    return dateToInt;
}

int HelperMethod::calculateDaysInMonth(int yearDigit,int monthDigit)
{
    int daysInMonth = 0;
    if (monthDigit == 2)
    {
        if ((yearDigit % 400 == 0) || (yearDigit % 4 == 0 && yearDigit % 100 != 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }

    else if (monthDigit == 1 || monthDigit == 3 || monthDigit == 5 || monthDigit == 7 || monthDigit == 8
             || monthDigit == 10 || monthDigit == 12)
        daysInMonth = 31;
    else
        daysInMonth = 30;

    return daysInMonth;
}

bool HelperMethod::checkDateRage(string date)
{

    const int initialYear = 2000;
    const int initialMonth = 1;
    const int initialDay = 1;
    string inputYear = "";
    string inputMonth = "";
    string inputDay = "";
    string currentDate = "";
    string currentDateYear = "";
    string currentDateMonth = "";
    string currentDateDay = "";
    int currentYear= 0;
    int currentMonth = 0;
    int currentDaysInMonth = 0;
    int daysInMonth = 0;
    int yearDigit = 0;
    int monthDigit = 0;
    int dayDigit = 0;

    currentDate = getCurrentDate();

    inputYear = date.substr(0, 4);
    inputMonth = date.substr(5, 2);
    inputDay = date.substr(8, 2);

    currentDateYear = currentDate.substr(0, 4);
    currentDateMonth = currentDate.substr(5, 2);

    yearDigit = convertionStringToInt(inputYear);
    monthDigit = convertionStringToInt(inputMonth);
    dayDigit = convertionStringToInt(inputDay);

    currentYear = convertionStringToInt(currentDateYear);
    currentMonth = convertionStringToInt(currentDateMonth);
    currentDaysInMonth = calculateDaysInMonth(currentYear,currentMonth);

    daysInMonth = calculateDaysInMonth(yearDigit,monthDigit);

    if(dayDigit > daysInMonth)
    {
        cout << "The given number of days in a given month is too large! The maximum number of days in a given month is : " << daysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;

    }
    else if(monthDigit > 12)
    {
        cout << "The given month does not exist, please select a month range between 1 - 12 : " << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if((yearDigit < initialYear) || (monthDigit < initialMonth) || (dayDigit < initialDay))
    {
        cout << "The given date is too old! The oldest date that can be entered is : 2000-01-01" << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if(dayDigit > daysInMonth)
    {
        cout << "The given day does not exist! Last day of this month = " << daysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if(yearDigit > currentYear)
    {
        cout << "The given date is too far away, the oldest date you can use is : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if((yearDigit == currentYear) && (monthDigit > currentMonth))
    {
        cout << "The given date is too far away, the oldest date you can use is : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
        system("CLS");
    }

    system("CLS");
    return true;
}

string HelperMethod::replaceWithCapitalLetter(string word)
{

    word[0] = toupper(word[0]);
    return word;
}

string HelperMethod::replaceTheCommaWithDot(string word)
{

    while (word.find(",") != string::npos)
        word.replace(word.find(","), 1, ".");

    return word;
}

string HelperMethod::changeDateToBeginningMonth(string word)
{

    string begginingMonth = "";
    string initialDay = "01";

    for(size_t i = 0 ; i < word.length() - 2 ; i++)
    {

        begginingMonth += word[i];
    }
    begginingMonth += initialDay;
    return begginingMonth;
}

string HelperMethod::connectLastDayWitchCurrentMounth(string date, int day)
{

    string convertedDay = to_string(day);
    string endOfMounth = "";

    for(int i = 0 ; i < 8 ; i++)
    {

        endOfMounth += date[i];
    }
    endOfMounth += convertedDay;

    return endOfMounth;

}

string HelperMethod::dateSeparatedByDashes(int date)
{

    string newDate = to_string(date);
    string year = newDate.substr(0, 4);
    string month = newDate.substr(4, 2);
    string day = newDate.substr(6, 2);

    return year + "-" + month + "-" + day;
}
