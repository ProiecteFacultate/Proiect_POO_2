#include "MyExceptions.h"
#include <string>

using namespace std;

MyExceptions::MyExceptions(string exceptionType, string message, string value)
{
    this->exceptionType = exceptionType;
    this->message = message;
    this->value = value;
}

void MyExceptions::badTypeIntegerException(string input)
{
    if(!(input[0] == '-' || ('0' <= input[0] && input[0] <= '9')))
    {
        MyExceptions e("BAD DATA TYPE EXCEPTION", "Found STRING, required INTEGER", input);
        throw e;
    }

    for(int i = 1; i < input.size(); i++)
        if(!('0' <= input[i] && input[i] <= '9'))
        {
            MyExceptions e("BAD DATA TYPE EXCEPTION", "Found STRING, required INTEGER", input);
            throw e;
        }
}

void MyExceptions::vectorLengthException(int input)
{
    if(input < 0)
    {
        MyExceptions e("BAD LENGTH EXCEPTION", "Vector can't have negative length", to_string(input));
        throw e;
    }
}

void MyExceptions::negativeValueException(int input)
{
    if(input < 0)
    {
        MyExceptions e("UNACCEPTED VALUE EXCEPTION", "Expected positive value, found negative", to_string(input));
        throw e;
    }
}

void MyExceptions::boolValueException(string input)
{
    for(int i = 0; i < input.size(); i++)
        input[i] = toupper(input[i]);

    if(!(input == "TRUE" || input == "FALSE"))
    {
        MyExceptions e("UNACCEPTED VALUE EXCEPTION", "Expected [TRUE/FALSE]", input);
        throw e;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string MyExceptions::getException()
{
    return this->exceptionType + ": " + this->message + ": " + this->value;
}
