#include "DateMeneger.h"

string DateMeneger::getCurrentDate()
{

    time_t now = time(0);
    tm* ltm = localtime(&now);
    string currentData = "";

    string year = to_string(1900 + ltm->tm_year);
    string month = HelperMethod::checkLengthString(to_string(1 + ltm->tm_mon));
    string day = HelperMethod::checkLengthString(to_string(ltm->tm_mday));

    currentData = year + "-" + month + "-" + day;
    return currentData;
}

bool DateMeneger::askAboutDate()
{
    char choise;

    while((choise != 'y') || (choise != 'o'))
    {
        cout << "Do I want to set today's date? If so click 'y' " << endl;
        cout << "Do I want to set other date? If so click 'o' " << endl;
        choise = getch();
        system("CLS");

        switch(choise)
        {
        case 'y': return true; break;
        case 'o': return false; break;
        }
        cout << "Correct choise !!" << endl;
        Sleep(2000);
    }
}

bool DateMeneger::checkDateFormat(string date)
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

int DateMeneger::convetionDateToInt(string date)
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

int DateMeneger::calculateDaysInMonth(string date)
{
    int yearDigit = 0;
    int monthDigit = 0;
    int daysInMonth = 0;

    yearDigit = HelperMethod::convertionStringToInt(date.substr(0, 4));
    monthDigit = HelperMethod::convertionStringToInt(date.substr(5, 2));

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

bool DateMeneger::checkDateRage(string date)
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

    yearDigit = HelperMethod::convertionStringToInt(inputYear);
    monthDigit = HelperMethod::convertionStringToInt(inputMonth);
    dayDigit = HelperMethod::convertionStringToInt(inputDay);

    currentYear = HelperMethod::convertionStringToInt(currentDateYear);
    currentMonth = HelperMethod::convertionStringToInt(currentDateMonth);
    currentDaysInMonth = calculateDaysInMonth(currentDate);

    daysInMonth = calculateDaysInMonth(date);

    if(dayDigit > daysInMonth)
    {
        system("CLS");
        cout << "The given number of days in a given month is too large! The maximum number of days in a given month is : " << daysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;

    }
    else if(monthDigit > 12)
    {
        system("CLS");
        cout << "The given month does not exist, please select a month range between 1 - 12 : " << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if((yearDigit < initialYear) || (monthDigit < initialMonth) || (dayDigit < initialDay))
    {
        system("CLS");
        cout << "The given date is too old! The oldest date that can be entered is : 2000-01-01" << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if(dayDigit > daysInMonth)
    {
        system("CLS");
        cout << "The given day does not exist! Last day of this month = " << daysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if(yearDigit > currentYear)
    {
        system("CLS");
        cout << "The given date is too far away, the oldest date you can use is : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    else if((yearDigit == currentYear) && (monthDigit > currentMonth))
    {
        system("CLS");
        cout << "The given date is too far away, the oldest date you can use is : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
        system("CLS");
    }

    system("CLS");
    return true;
}

string DateMeneger::changeDateToBeginningMonth(string word)
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

int DateMeneger::connectLastDayWitchCurrentMounth(int date, int day)
{
    string convertedDay = to_string(day);
    string convertedDate = to_string(date);
    string endOfMounth = "";

    for(int i = 0 ; i < 6 ; i++)
    {

        endOfMounth += convertedDate[i];
    }
    endOfMounth += convertedDay;

    return HelperMethod::convertionStringToInt(endOfMounth);

}

string DateMeneger::dateSeparatedByDashes(int date)
{

    string newDate = to_string(date);
    string year = newDate.substr(0, 4);
    string month = newDate.substr(4, 2);
    string day = newDate.substr(6, 2);

    return year + "-" + month + "-" + day;
}

string DateMeneger::getBeginningPerviousMonth(string actualDate){

    string year = actualDate.substr(0, 4);
    string month = actualDate.substr(5, 2);
    int yearDigit = HelperMethod::convertionStringToInt(year);
    int monthDigit = HelperMethod::convertionStringToInt(month);

    if(monthDigit == 1)
    {
        yearDigit = yearDigit - 1;
        monthDigit = 12;
    }
    else
        monthDigit = monthDigit - 1;

    if(monthDigit < 10)
    {
        month = "0" + to_string(monthDigit) + "-01";
        year = to_string(yearDigit) + "-";
    }
    else
    {
        month = to_string(monthDigit)+ "-01";
        year = to_string(yearDigit)+ "-";
    }

    return year + month;
}
