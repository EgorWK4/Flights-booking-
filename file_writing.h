//
// Created by egor on 8.05.20.
//

#ifndef CONTAINERS_FILE_WRITING_H
#define CONTAINERS_FILE_WRITING_H
#include "airport.h"
#include "customer.h"
#include <fstream>
#include <regex>
string txt_match(string file_path)
{
    std::regex txt_regex("[a-zA-Z0-9]+\\.txt");
    if(!std::regex_match(file_path, txt_regex))
        throw string("file name does not match txt file");
    return file_path;

}

bool to_file(const Airport& obj,const  string& file_path)
{
    txt_match(file_path);
    std::ofstream out(file_path);
    if(out.fail())
    {
        std::cout <<"Problems with opening file " << std::endl;
        return false;
    }
    auto mapp = obj.get_tickets();
    for(const auto &elem : mapp)
    {
        out << elem.second.departing_to.first << " destination time "<<"\n";
        out << elem.second.departing_to.second << " City of destination"<<"\n";
        out << elem.second.arriving_from.first  <<" Time of arriving from"<<"\n";
        out << elem.second.arriving_from.second  << " Starting city"<< "\n";
        out << elem.second.price << " Price " << "\n";
        out << elem.second.id <<  " Ticket id " <<"\n";
    }
    out.close();
    std::cout << "File writing was successful" << std::endl;
    return true;

}
bool save_users_wallet(const User& obj,const string& file_path)
{
    txt_match(file_path);
    std::ofstream out(file_path);
    if (out.fail())
    {
        std::cout << "Problems with opening file" << std::endl;
        return false;
    }
    auto mapp = obj.get_tickets();
    for(const auto& elem : mapp)
    {

        out << elem.departing_to.first << " destination time "<<"\n";
        out << elem.departing_to.second << " City of destination"<<"\n";
        out << elem.arriving_from.first  <<" Time of arriving from"<<"\n";
        out << elem.arriving_from.second  << " Starting city"<< "\n";
        out << elem.price << " Price " << "\n";
        out << elem.id <<  " Ticket id " <<"\n";
    }
    out.close();
    std::cout << "File writing was successful" << std::endl;
    return true;
}

#endif //CONTAINERS_FILE_WRITING_H
