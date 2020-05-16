//
// Created by egor on 7.05.20.
//

#ifndef CONTAINERS_EXCEPTIONS_VALIDATE_H
#define CONTAINERS_EXCEPTIONS_VALIDATE_H

#include <regex>
class Wrong_PassportID
{
public:
    Wrong_PassportID() { message = "You entered wrong passport id.";};
    explicit Wrong_PassportID(string s) { message=s; };
    string message;
};
double regexValidate (std::string expr, std::string test_string);
    //std::cout << "Error" << expr << " " << teststring << std::endl;


#endif //CONTAINERS_EXCEPTIONS_VALIDATE_H
