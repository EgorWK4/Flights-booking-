//
// Created by egor on 7.05.20.
//

#ifndef CONTAINERS_AIRPORT_H
#define CONTAINERS_AIRPORT_H
#include <string>
#include <vector>
#include <map>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;
using std::string;
#include <utility>
#include <vector>
#include <optional>
#include <fstream>

struct Ticket
{
    /*
     * struct Ticket represent's ticket object;
     *
     * Fields:
     * departing_to/arriving_from just simple std::pairs of boost datetime obj and string City;
     * double price - cost of ticket;
     * id - autoincrement obj.id with static field usage. Using this id's as a key in the Airport map of tickets>;
     *private static field current_id. Using it to increment id's of created object's;
     *
     * Constructor's:
     * : via initializer list and ordinary Ticket();
     *
     * Methods :
     * get_travel duration() : departing_to - arriving_from. Difference between 2 datetime objects.
     * show() : displays Ticket fields information
     */
    std::pair<date,string> departing_to;
    std::pair<date,string> arriving_from;
    double price;
    unsigned id;
    Ticket();
    Ticket(std::pair<date,string> departing_to,std::pair<date,string> arriving_from,double price);
    date_duration get_travel_duration() const;
    void show() const;
    friend std::ostream & operator<< (std::ostream &out, const Ticket& obj);
private:
    static unsigned current_id;
};

class Airport
{
    /*
     * class Airport represents airport object;
     *
     * Fields:
     *  std::map<unsigned,Ticket> tickets : container to store tickets;
     *  runway_strips : airport dummy variable;
     *  name : airports name. For example Charles de Gaulle Airport;
     *
     *  Constructors:
     *  : via initializer list and ordinary Airport();
     *
     *  Methods:
     * getters/setters for accessing private fields of class;
     * push_ticket() : add Ticket object to std::map;
     * delete ticket() : remove Ticket object from std::map;
     *show() : displays all tickets that are available in airport;
     */

    std::map<unsigned,Ticket> tickets;
    unsigned runway_strips;
    string name;
public:
    Airport();
    Airport(std::map<unsigned,Ticket> tickets, unsigned runway_strips, string name);
    void set_name(const string& name);
    void set_runway_strips(const unsigned& runway_strips);
    std::map<unsigned,Ticket> get_tickets() const;
    string get_name() const;
    unsigned get_runway_strips() const;
    void push_ticket(const Ticket& obj);
    void delete_ticket(int key);
    void show() const;
};

#endif //CONTAINERS_AIRPORT_H
