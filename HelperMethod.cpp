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
    string year = "";
    string month = "";
    string day = "";
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

    year = year + date[0] + date[1] + date[2] + date[3];
    month = month + date[5] + date[6];
    day = day + date[8] + date[9];

    currentDateYear = currentDateYear + currentDate[0] + currentDate[1] + currentDate[2] + currentDate[3];
    currentDateMonth = currentDateMonth + currentDate[5] + currentDate[6];

    yearDigit = convertionStringToInt(year);
    monthDigit = convertionStringToInt(month);
    dayDigit = convertionStringToInt(day);

    currentYear = convertionStringToInt(currentDateYear);
    currentMonth = convertionStringToInt(currentDateMonth);
    currentDaysInMonth = calculateDaysInMonth(currentYear,currentMonth);

    daysInMonth = calculateDaysInMonth(yearDigit,monthDigit);

    if(dayDigit > daysInMonth)
    {
        cout << "Podana iloœæ dni w danym miesi¹cu jest zbyt du¿a ! Maksymalna iloœæ dni w danym miesi¹cu wynosi : " << daysInMonth << endl;
        Sleep(2000);
        return false;

    }
    else if(monthDigit > 12)
    {
        cout << "Podany miesiac nie istnieje, wybierz zakres miesiecy miedzy 1 - 12 : " << endl;
        Sleep(2000);
        return false;
    }
    else if((yearDigit < initialYear) || (monthDigit < initialMonth) || (dayDigit < initialDay))
    {
        cout << "Podana data jest zbyt stara ! Najstarsza date ktora mozna wprowadzic to : 2000-01-01" << endl;
        Sleep(2000);
        return false;
    }
    else if(yearDigit > currentYear)
    {
        cout << "Podana data jest zbyt odlegla, najstarsza date ktora mozesz uzyc to : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
        return false;
    }
    else if((yearDigit == currentYear) && (monthDigit > currentMonth))
    {
        cout << "Podana data jest zbyt odlegla, najstarsza date ktora mozesz uzyc to : " << currentYear << "-" << currentMonth << "-" << currentDaysInMonth << endl;
        Sleep(2000);
    }
    else
    {
        return true;
    }
}
