#ifndef VIRTUAL_TABLE_H
#define VIRTUAL_TABLE_H

#include <string>
#include <vector>
#include <fstream>

class generator ;

class virtual_table
{
public:
    void set_fuction(const std::vector<std::string>&,const std::string&,const generator& ) ; // implement "code_generator.cpp"
    std::vector<std::vector<std::string>> get_virtual_funtions() const ;
    void generate_virtual_functions(std::ofstream & ofile) ; 
    void virtual_function_coll(std::vector<std::string>&,std::vector<std::string>::iterator,const std::string&,const std::string&,const std::string&) ;
public:
    bool have_virtual_function { false } ;
private:
    std::vector<std::vector<std::string>> virtual_functions ;
} ;


#endif