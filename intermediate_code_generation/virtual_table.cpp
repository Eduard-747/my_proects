#include "virtual_table.h"

#include <iostream>
#include <algorithm>
#include <iterator>

void virtual_table::generate_virtual_functions(std::ofstream & ofile) 
{
    std::for_each(virtual_functions.begin(),virtual_functions.end(),[&](std::vector<std::string> & function){
        std::copy(function.begin(),function.end(),std::ostream_iterator<std::string>(ofile)) ;
        ofile << ";\n" ;
    });
}
void virtual_table::virtual_function_coll(std::vector<std::string>& vec,std::vector<std::string>::iterator pos,
    const std::string& foo_name,const std::string& pointer_name,const std::string& str_tmp) 
{
    std::for_each(virtual_functions.begin(),virtual_functions.end(),[&](std::vector<std::string> & function){
        auto p = std::find(function.begin(),function.end(),foo_name) ;
        if(p != function.end()) {
           vec.insert(pos ,pointer_name+"->v_ptr->"+foo_name + "(" + pointer_name + str_tmp) ; 
        }
    });
}
std::vector<std::vector<std::string>> virtual_table::get_virtual_funtions() const 
{
    return virtual_functions ;
}