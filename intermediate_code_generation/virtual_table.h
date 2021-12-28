#ifndef VIRTUAL_TABLE_H
#define VIRTUAL_TABLE_H

#include <string>
#include <vector>

class virtual_table
{
public:
    void set_fuction(const std::vector<std::string>&,const std::string&) ;
    std::vector<std::vector<std::string>> get_virtual_funtions() const ;
public:
    bool have_virtual_function { false } ;
private:
    std::vector<std::vector<std::string>> virtual_functions ;
} ;


#endif