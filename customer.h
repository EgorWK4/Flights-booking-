//
// Created by egor on 7.05.20.
//
#ifndef CONTAINERS_CUSTOMER_H
#define CONTAINERS_CUSTOMER_H
#include "airport.h"
#include <list>
#include "exceptions_validate.h"
using namespace boost::gregorian;
class Wrong_PassportID;
double regexValidate (std::string expr, std::string test_string);

class User
{
    /*
     * Class User represents airport customer object;
     *
     * Fields:
     * std::list<Ticket> tickets: list of user's tickets;
     * user's first_name/second_name/age;
     * passport_id to buy ticket; Check if user has provided correct passport_id(with RegexValidate). ID's must be only digits.;
     *
     * Methods:
     * getters/setters;
     * buy_tickets(Airport& obj, int key) : retrieve ticket from airport's map_of_tickers and push it to user's wallet;
     * print_list() : display user's wallet;
     *show_info() : displays user's wallet and his personal data;
     *
     * find_tickets() Tries to find available tickets with given settings. Period is date between first_date and second_date;
     */
    std::list<Ticket> tickets;
    string first_name;
    string second_name;
    string passport_id;
    int age;
public:
    std::string get_passport_id() const;
    void set_first_name(const string& first_name);
    void set_second_name(const string& second_name);
    void set_passport_id(const string& passport_id);
    void set_age(const int& age);
    User();
    void buy_tickets(Airport& obj, int key);
    void print_list() const;
    void show_info() const;
    friend std::ostream & operator << (std::ostream &out, const User& obj);
    std::list<Ticket> get_tickets() const;
    void find_ticket(Airport& obj,string datetime1,string datetime2, string city_from, string city_to);
    };


#endif //CONTAINERS_CUSTOMER_H
