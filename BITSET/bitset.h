#ifndef BITSET_H
#define BITSET_H

#include <iostream>

namespace consts 
{
    const int sizeof_ull = 64;
}

template <size_t N>
class bitset
{
public:
    bitset(); 
    bitset(const unsigned long long& n); 
    bitset(const std::string& str, const int & size, const char& zero, const char& one); 
    bitset(const bitset& r); 
    bitset(bitset&& r); 
    bitset& operator=(const bitset& r); 
    bitset& operator=(bitset&& r); 
    ~bitset(); 
public:
    friend std::ostream& operator<<(std::ostream& os, const bitset& b) 
    {
        os << b.to_string() ;
        return os;
    }
public:
    bitset & set(const size_t& pos,const bool & val = true); 
    bitset & set(); 
    bitset & reset(const size_t& pos); 
    bitset & reset(); 
    bitset & flip(const size_t& pos); 
    bitset & flip(); 
    size_t size() const; 
    bool any() const;  
    size_t count() const; 
    bool none() const; 
    bool all() const; 
    bool test(const size_t& pos) const; 
    std::string to_string(const char& zero = '0', const char& one = '1') const ; 
    unsigned long long to_ullong() const; 
public:
    bitset& operator|=(const bitset& rhs); 
    bitset& operator&=(const bitset& rhs); 
    bitset& operator^=(const bitset& rhs); 
    bitset& operator>>=(const size_t & position) ; 
    bitset& operator<<=(const size_t & position) ; 
    bitset operator|(const bitset& rhs) const; 
    bitset operator&(const bitset& rhs) const; 
    bitset operator^(const bitset& rhs) const; 
    bitset operator>>(const size_t & position) const; 
    bitset operator<<(const size_t & position) const; 
private:
    void shift_left();
    void shift_right();
private:
    size_t _size = N / consts::sizeof_ull;
    unsigned long long* arr = new unsigned long long[N / consts::sizeof_ull]{};
} ;

#endif