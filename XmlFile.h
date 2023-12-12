#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>

using namespace std;

class XmlFile
{

    const string FILE_NAME;
public:

    XmlFile(string usersFileName) : FILE_NAME(usersFileName) {}
    string getFileName();
};
#endif
