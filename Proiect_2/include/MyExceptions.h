#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <iostream>
#include <string>
#include <vector>

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
    static void acceptedInputException(std::string, std::vector<std::string>, int);  //throws if the string is not what provided in second string
    static void outOfBoundsException(int, int, int);    //throws if first int >= second int or if first int is negative

    std::string getException();
};

#endif // MYEXCEPTIONS_H
