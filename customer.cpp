//
// Created by egor on 8.05.20.
//
#include "customer.h"

User::User()
{
    tickets = std::list<Ticket>();
    first_name = std::string();
    second_name = std::string();
    string passport_id();
    age = int();
}
std::list<Ticket> User::get_tickets() const
{
    return tickets;
}
void User::set_age(const int &age)
{
    this->age = age;
}
void User::set_second_name(const string &second_name)
{
    this->second_name = second_name;
}
void User::set_first_name(const string &first_name)
{
    this->first_name = first_name;
}
void User::set_passport_id(const string &passport_id)
{
    this->passport_id = passport_id;
}

std::string User::get_passport_id() const
{
    return passport_id;
}
void User::buy_tickets(Airport &obj, int key)
{
    string pattern = "^[0-9]*$";
    regexValidate (pattern, get_passport_id());// check if user entered wrong passport id
    std::map<unsigned,Ticket> mapp = obj.get_tickets();
    auto ticket = mapp.at(key);
    tickets.push_back(ticket);
    obj.delete_ticket(key);
}
void User::print_list() const
{
    if(tickets.empty())
    {
        std::cout << "There are no tickets yet" << std::endl;
    }
    for(auto const& i : tickets)
    {
        i.show();
        std::cout << std::endl;
    }
}
void User::show_info() const
{
    std::cout << "First name :" << first_name << std::endl;
    std::cout << "Second name :" << second_name << std::endl;
    std::cout << "Age :" << age << std::endl;
    std::cout << "Passport id" << passport_id << std::endl;
    print_list();
}
std::ostream & operator << (std::ostream &out, const User& obj)
{
    out << obj.first_name << "\n" <<obj.second_name<<"\n"<<obj.passport_id<<
        obj.age  << std::endl;
    return out;
}
void User::find_ticket(Airport &obj, string datetime1, string datetime2, string city_from, string city_to)
{
    date d = from_undelimited_string(datetime1);
    date v = from_undelimited_string(datetime2);
    date_period dp(d,v);
    //auto to_find = std::pair<boost::gregorian::date,string> {d,city};
    auto mapp = obj.get_tickets();
    if(mapp.empty())
    {
        throw(string("There are no available tickets in Airport right now !"));
        //User could buy all tickets/ With get_tickets we will return empty map;
    }
    for (const auto& elem : mapp)
    {
        //if we found tickets to our destination, we want to get there in some period of time. Suppose from june/21 - June25
        if(
                (elem.second.arriving_from.second == city_from) & (dp.contains(elem.second.arriving_from.first)) &
                (elem.second.departing_to.second == city_to) & (dp.contains(elem.second.departing_to.first))

                )
        {
            std::cout << "Your period was " << dp << std::endl;
            std::cout << "You want to flight from " << city_from << " to " << city_to << std::endl;
            std::cout << "Id of Ticket is : " << elem.first  << std::endl;
            elem.second.show();
        }
    }
}

double regexValidate (std::string expr, std::string test_string)
{
    noexcept(false);
    {
        std::regex ex(expr);
        if (regex_match(test_string, ex)) {
            //std::cout << "true";
            return std::stod(test_string);//cast to int if true;
        }
        throw (Wrong_PassportID("wrong"));


    }
}