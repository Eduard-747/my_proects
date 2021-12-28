#include "virtual_table.h"

#include <iostream>
#include <algorithm>

void virtual_table::set_fuction(const std::vector<std::string>& fun,const std::string& class_name) 
{
    std::vector<std::string> table_fun ;
    table_fun.push_back(fun[0]) ;
    table_fun.push_back("(*") ;
    table_fun.push_back(fun[1]) ;
    table_fun.push_back(")(") ;
    table_fun.push_back(class_name + "*") ;
    for(int i = 0 ; i < fun.size() ; ++i)
    {
        if(fun[i] == ",")
        {
            table_fun.push_back(',' + fun[i - 2]) ;
            table_fun.push_back(',' + fun[i + 1]) ;
        }
    }
    table_fun.push_back(")") ;
    virtual_functions.push_back(table_fun) ;
}

std::vector<std::vector<std::string>> virtual_table::get_virtual_funtions() const 
{
    return virtual_functions ;
}