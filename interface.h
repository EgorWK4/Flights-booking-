//
// Created by egor on 16.05.20.
//

#ifndef CONTAINERS_INTERFACE_H
#define CONTAINERS_INTERFACE_H
void menu(Airport& airport,User& user)
{
    bool flag  = true;
    int i;
    while(flag)
    {
        std::cout << "1: Show available flights " << std::endl;
        std::cout << "2: Show user info " << std::endl;
        std::cout << "3: Buy tickets " << std::endl;
        std::cout << "4: Delete tickets " << std::endl;
        std::cout << "5: Search ticket with city->city and start_date -> end_date configuration " << std::endl;
        std::cout << "6: Save to file users wallet and info" << std::endl;
        std::cout << "7: Save to file airport tickets" << std::endl;


        int a ;
        string start_date;
        string end_date;
        string city1;
        string city2;

        std::cout << "Enter your choice" << std::endl;
        std::cin >> a;
        switch(a)
        {
            case 1:
                airport.show();
                break;
            case 2:
                user.show_info();
                break;
            case 3:
                std::cout << "Please enter flight_id to buy" << std::endl;
                int flight_id;
                std::cin >> flight_id;
                user.buy_tickets(airport,flight_id);
                break;
            case 4:
                std::cout << "Enter ticket id you want to delete" << std::endl;
                int id;
                std::cin>> id;
                airport.delete_ticket(id);
                break;
            case 5:
                std::cout << "Enter starting date in format 19900201 without comma" << std::endl;
                std::cin>> start_date;
                std::cout << "Enter end date in format 19900201 without comma" << std::endl;
                std::cin >> end_date;
                std::cout << "Enter City you want to fly from " << std::endl;
                std::cin >> city1;
                std::cout << "Enter city you want to flight to" << std::endl;
                std::cin >> city2;
                user.find_ticket(airport,start_date,end_date,city1,city2);
                break;
            case 6:
                to_file(airport,"data.txt");
                break;
            case 7:
                save_users_wallet(user,"wallet.txt");
                break;
            default :
                std::cout << "Wrong operation key" << std::endl;
                break;
        }
        std::cout << "Would you like to continue ? 0 - to exit" << std::endl;
        std::cin >> i;
        //std::cout << "\033[2J\033[1;1H" << std::endl; // to clear console output with special escaping sequence of characters/dont working dunno why
        if (i == 0)
            flag = false;
    }
}
#endif //CONTAINERS_INTERFACE_H
