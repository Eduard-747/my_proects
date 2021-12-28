#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class parser
{
public:
    parser(const std::string&);
    void tokenizer() ;
    std::vector<std::string> get_tokens() const ;
    static bool word(const std::string &) ;
    ~parser();
private:
    std::vector<std::string> tokens ;
    std::ifstream ifile ;
};

#endif