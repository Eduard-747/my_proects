#include "encryption.h"

#include <iostream>
#include <algorithm>
#include <map>

namespace constants {
	const int cube_size { 8 } ;
} ;

void encryption::set_text(std::string& str)
{
	while(str.size() % constants::cube_size != 0)
	{
		str.push_back(' ') ;
	}
	std::string tmp_str ;
	while(str.size())
	{
		cubes.push_back(str.substr(0,constants::cube_size)) ;
		str.erase(0,constants::cube_size) ;
	}
}
std::string encryption::get_text() const
{
	std::string text ;
	std::for_each(cubes.begin(),cubes.end(),[&](const std::string& str){
		text += str ;
	}) ;
	return text ;
}
std::string encryption::start_encryption(const std::string& key = "RUD") 
{
	std::for_each(key.begin(),key.end(),[&](const char & ch) {
		(this->*m[ch])();
	}) ;
	return key ;
}
void encryption::set_key(const std::string& key)
{
	start_encryption(key) ;
}
void encryption::up()
{
	for(auto & str: cubes)
	{
		std::string str_tmp = str ;
		str[0] = str_tmp[2] ;
		str[1] = str_tmp[3] ;
		str[2] = str_tmp[6] ;
		str[3] = str_tmp[7] ;
		str[4] = str_tmp[0] ;
		str[5] = str_tmp[1] ;
		str[6] = str_tmp[4] ;
		str[7] = str_tmp[5] ;
	}
}
void encryption::down()
{
	for(auto & str: cubes)
	{
		std::string str_tmp = str ;
		str[0] = str_tmp[4] ;
		str[1] = str_tmp[5] ;
		str[2] = str_tmp[0] ;
		str[3] = str_tmp[1] ;
		str[4] = str_tmp[6] ;
		str[5] = str_tmp[7] ;
		str[6] = str_tmp[2] ;
		str[7] = str_tmp[3] ;
	}
}
void encryption::left()
{
	for(auto & str: cubes)
	{
		std::string str_tmp = str ;
		str[0] = str_tmp[1] ;
		str[1] = str_tmp[5] ;
		str[2] = str_tmp[3] ;
		str[3] = str_tmp[7] ;
		str[4] = str_tmp[0] ;
		str[5] = str_tmp[4] ;
		str[6] = str_tmp[2] ;
		str[7] = str_tmp[6] ;
	}
}
void encryption::right()
{
	for(auto & str: cubes)
	{
		std::string str_tmp = str ;
		str[0] = str_tmp[4] ;
		str[1] = str_tmp[0] ;
		str[2] = str_tmp[6] ;
		str[3] = str_tmp[2] ;
		str[4] = str_tmp[5] ;
		str[5] = str_tmp[1] ;
		str[6] = str_tmp[7] ;
		str[7] = str_tmp[3] ;
	}
}
int main()
{
	encryption o ;
	std::string str {"1234567812345678"} ;
	o.set_text(str) ;
	std::cout << o.start_encryption() << std::endl ;
	o.set_key("UDL") ;
	std::cout << o.get_text() ;
	return 0 ;
}

