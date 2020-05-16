#include <iostream>
#include "airport.h"
#include "exceptions_validate.h"
#include "customer.h"
#include "file_writing.h"
#include "interface.h"

int main()
{

Ticket obj({{1975, 1, 2},"Vietnam"},{{1955,1,1},"Sweet home Alabama"},500);
Ticket obj1({{2014, 3, 10},"Minsk"},{{2014,2,2},"London"},1999);

Ticket obj2({{2014, 4, 10},"Moscow"},{{2014,4,2},"Amsterdam"},1999);
Ticket obj3({{2014, 5, 10},"Minsk"},{{2014,5,3},"London"},1999);


Airport airport;
airport.set_name("Sheremetyevo - A.S. Pushkin international airport");
airport.set_runway_strips(2);
airport.push_ticket(obj);
airport.push_ticket(obj1);
airport.push_ticket(obj2);
airport.push_ticket(obj3);


User user;
user.set_first_name("Egor");
user.set_second_name("Sviridenko");
user.set_age(19);
user.set_passport_id("123123123123"); // without correct passport id(only digits) user can't buy any tickets.
menu(airport,user);


//airport.delete_ticket(1); //cancel flight for example
/*
std::cout << "Show available tickets in the airport" << std::endl;
airport.show();
std::cout << std::endl;
std::cout << std::endl;
*/

//user.set_passport_id("12344125643AFDAFDAF"); // validation works;

/*
//user.buy_tickets(airport,1);
//user.buy_tickets(airport,2);
std::cout << "Show user's personal data" << std::endl;
user.show_info();
std::cout << std::endl;

std::cout << "Find ticket with rule example"<< std::endl;
user.find_ticket(airport,"20140502","20140512","London","Minsk");
//  "20140502","20140512" - data period, in which algorithm will search available tickets with given cities.
std::cout << "____________________" << std::endl;
user.buyuser's wallet and info_tickets(airport,4);
std::cout << "Find ticket with rule example(Already bought)"<< std::endl;
std::cout << std::endl;
std::cout << "____________________"<<std::endl;
//user.find_ticket(airport,"19520105","20000302","Sweet home Alabama","Vietnam");
std::cout <<"Showing tickets that are available in airport right now" << std::endl;
airport.show();
std::cout << std::endl;
std::cout << "Show user's information and his wallet" << std::endl;
//user.show_info();
//user.cancel_flight(); TODO in future . move back from std::list ticket pair to airport

//to_file(airport,"data.data");// works exception with regex match txt file
//to_file(airport,"data.txt");
//save_users_wallet(user,"wallet.txt");
*/
}