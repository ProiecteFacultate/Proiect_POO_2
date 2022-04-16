#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <iostream>


class MyExceptions
{
private:
    std::string exceptionType;
    std::string message;
    std::string value;

public:
    MyExceptions(std::string, std::string, std::string);

    static void badTypeIntegerException(std::string);   //throws if input is not integer
    static void vectorLengthException(int);   //throws if integer is negative
    static void negativeValueException(int);  //throws if integer is negative
    static void boolValueException(std::string);  //throws if the string is not TRUE or FALSE

    std::string getException();
};

#endif // MYEXCEPTIONS_H
