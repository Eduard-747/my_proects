#include "parser.h"

bool parser::word(const std::string& str) 
{
    for(const char & ch: str)
    {
        if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z') && !(ch == '_') && !(ch >= '0' && ch <= '9'))
        {
            return false ;
        }
    }
    return !(str[0] >= '0' && str[0] <= '9') ? true : false ;
}

std::vector<std::string> parser::get_tokens() const 
{
    return tokens ;
}

parser::parser(const std::string & FileName )
{
    ifile.open(FileName) ;
    if(!ifile.is_open()) {
        std::cerr << "file is not open" << std::endl ;
        throw ;
    }
}

void parser::tokenizer() 
{
    std::string line ;
    while(!ifile.eof()) 
    {
        line.clear() ;
        std::getline(ifile,line) ;
        std::string token ;
        for(int i = 0 ; i <= line.size(); ++i) 
        {
            if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] == '_') || (line[i] >= '0' && line[i] <= '9')) {
                token.push_back(line[i]) ;
            } else {
                if(token != "")
                tokens.push_back(token) ;
                token.clear() ;
                if(line[i] != '\0' && line[i] != ' ' && line[i] != '>') {
                    if(line[i] == '-' && line[i + 1] == '>') {
                        token.push_back(line[i]) ;
                        token.push_back(line[i + 1]) ;
                        tokens.push_back(token) ;
                    } else {
                        token.push_back(line[i]) ;
                        tokens.push_back(token) ;
                    }
                    token.clear() ;
                }
            }
        }
    }
}
parser::~parser()
{
    ifile.close() ;
}