#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <vector>

class encryption
{
public:
	void set_key(const std::string &) ;
	void up() ;   
	void down() ; 
	void left() ; 
	void right(); 
	void set_text(std::string&) ;
	std::string get_text() const ;
	std::string start_encryption(const std::string&) ;
private:
	std::vector<std::string> cubes ;
} ;

#endif