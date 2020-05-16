//
// Created by egor on 7.05.20.
//
#include "airport.h"

Ticket::Ticket()
{
    departing_to = std::pair<date,string>();
    arriving_from = std::pair<date,string>();
    price = double();
    id = current_id++;
}
Ticket::Ticket(std::pair<date,string> departing_to,std::pair<date,string> arriving_from,double price)
: departing_to(departing_to), arriving_from(arriving_from), price(price){id = ++current_id;}

date_duration Ticket::get_travel_duration() const
{
    return departing_to.first - arriving_from.first;
}
void Ticket::show() const
{
    std::cout << "Departing to : " << departing_to.second <<  " Date :" <<departing_to.first <<'\n';
    std::cout << "Arriving from :" << arriving_from.second << " Date :" << arriving_from.first << '\n';
    std::cout << "Price : " << price << '\n';
    std::cout << "U will stay in  " << departing_to.second << " for " << get_travel_duration() << " days " <<  std::endl;
    //std::cout << "Id of flight" << id << '\n';
}
std::ostream & operator << (std::ostream &out, const Ticket& obj)
{
    out << obj.departing_to.first << obj.arriving_from.first<<"\n"
        <<obj.departing_to.second<<"\n" <<  obj.arriving_from.second << '\n'
        << obj.id << "\n";
    return out;
}
unsigned Ticket::current_id = 0;

// Airport

Airport::Airport()
{
    tickets= std::map<unsigned ,Ticket>();
    runway_strips = unsigned();
    name = string();
}
Airport::Airport(std::map<unsigned,Ticket> tickets, unsigned runway_strips, string name)
: tickets(tickets), runway_strips(runway_strips), name(name){}

void Airport::set_name(const string &name)
{
    this-> name = name;
}
void Airport::set_runway_strips(const unsigned& runway_strips)
{
    this->runway_strips = runway_strips;
}

std::map<unsigned int, Ticket> Airport::get_tickets() const
{
    return tickets;
}
string Airport::get_name() const
{
    return name;
}
unsigned int Airport::get_runway_strips() const
{
    return runway_strips;
}

void Airport::push_ticket(const Ticket &obj)
{
    tickets.insert({obj.id,obj});
}
void Airport::delete_ticket(int key)
{
    tickets.erase(key);
}
void Airport::show() const
{
    std::cout << " Airport's name : " << name << std::endl;
    std::cout << " Number of runways : "<< runway_strips << std::endl;
    for(const auto& flight : tickets)
    {
        std::cout <<"Id of flight " << flight.first << std::endl;
        flight.second.show();
        std::cout<< "_______" << std::endl;
    }
}