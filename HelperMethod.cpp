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

bool HelperMethod::passwordLength(string password)
{
    system("CLS");
    if (password.length() < 4)
    {
        cout << "The Password is to short ! The minimum number of characters is 4." << endl;
        Sleep(2000);
        system("CLS");
        return false;
    }
    return true;
}

string HelperMethod::convertAmountToString(float amount){
    ostringstream stream;
    stream << fixed << setprecision(2) << amount;
    string score = stream.str();
    return score;
}
