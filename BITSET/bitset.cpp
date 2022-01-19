#include "bitset.h"

#include <map>

template <size_t N>
bitset<N>::bitset()
{}

template <size_t N>
bitset<N>::bitset(const unsigned long long& n)
{
    arr[0] = n;
}

template <size_t N>
bitset<N>::~bitset()
{
    delete [] arr;
    arr = nullptr;
}

template <size_t N>
bitset<N>::bitset(const bitset<N>& r)
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] = r[i];
    }
}

template <size_t N>
bitset<N>::bitset(const std::string& str, const int & size, const char& zero, const char& one)
{
    auto _zero = [](unsigned long long& num) {
        num <<= 1;
    } ;
    auto _one = [](unsigned long long& num) {
        num <<= 1;
        num |= 1;
    } ;
    std::map<char,void(*)(unsigned long long&)> m {{zero,_zero},{one,_one}};
    for(int i = 0; i < size; ++i)
    {
        m.at(str[i])(arr[i / N]);
    }
}

template <size_t N>
bitset<N>::bitset(bitset<N>&& r)
{
    arr = r.arr ;
    r.arr = nullptr ;
}

template <size_t N>
bitset<N>& bitset<N>::operator=(const bitset<N>& r)
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] = r.arr[i] ;
    }
    return *this ;
}

template <size_t N>
bitset<N>& bitset<N>::operator=(bitset<N>&& r)
{
    arr = r.arr;
    r.arr = nullptr;
    return *this;
}

template <size_t N>
std::string bitset<N>::to_string(const char& zero , const char& one ) const
{
    std::string str;
    for(int i = 0; i < N; ++i)
    {
        str.push_back((this->test(i) == 0) ? zero: one) ;
    }
    return std::string(str.rbegin(),str.rend()) ;
}

template <size_t N>
unsigned long long bitset<N>::to_ullong() const
{
    return arr[0] ;
}

template <size_t N>
bitset<N> & bitset<N>::set(const size_t& pos,const bool & val)
{
	arr[pos / consts::sizeof_ull] |= (unsigned long long)val << pos % consts::sizeof_ull;
	return *this;
}

template <size_t N>
bitset<N> & bitset<N>::set()
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] = ~(0ull);
    }
	return *this;
}

template <size_t N>
bitset<N> & bitset<N>::reset()
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] = 0ull;
    }
	return *this;
}

template <size_t N>
bitset<N> & bitset<N>::reset(const size_t& pos)
{
	arr[pos / consts::sizeof_ull] &= ~(1ull << pos % consts::sizeof_ull);
	return *this;
}
template <size_t N>
bitset<N> & bitset<N>::flip(const size_t& pos)
{
	arr[pos / consts::sizeof_ull] ^= 1ull << pos % consts::sizeof_ull;
	return *this;
}

template <size_t N>
bitset<N> & bitset<N>::flip()
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] = ~arr[i] ;
    }
	return *this;
}

template <size_t N>
bool bitset<N>::test(const size_t& pos) const
{
    if(pos >= N)
    {
        throw std::out_of_range("bitset position (which is " + std::to_string(pos) + ") >= N (which is " + std::to_string(N) + ")" );
    }
    return arr[pos / consts::sizeof_ull] & 1ull << pos % consts::sizeof_ull;
}

template <size_t N>
size_t bitset<N>::size() const
{
    return N;
}

template <size_t N>
bool bitset<N>::none() const
{
    for(int i = 0; i <= _size; ++i)
    {
        if(arr[i] != 0) return false;
    }
    return true;
}

template <size_t N>
bool bitset<N>::any() const
{
    return !none();
}

template <size_t N>
size_t bitset<N>::count() const
{
    size_t c{} ;
    for(int i = 0; i < N; ++i)
    {
        c += test(i);
    }
    return c;
}

template <size_t N>
bool bitset<N>::all() const
{
    return count() == N ;
}

template <size_t N>
bitset<N>& bitset<N>::operator|=(const bitset<N>& rhs)
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] |= rhs.arr[i];
    }
    return *this;
}

template <size_t N>
bitset<N>& bitset<N>::operator&=(const bitset<N>& rhs)
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] &= rhs.arr[i];
    }
    return *this;
}

template <size_t N>
bitset<N>& bitset<N>::operator^=(const bitset<N>& rhs)
{
    for(int i = 0; i <= _size; ++i)
    {
        arr[i] ^= rhs.arr[i];
    }
    return *this;
}

template <size_t N>
bitset<N> bitset<N>::operator|(const bitset<N>& rhs) const
{
    bitset tmp(*this);
    for(int i = 0; i <= _size; ++i)
    {
        tmp[i] |= rhs.arr[i];
    }
    return tmp;
}

template <size_t N>
bitset<N> bitset<N>::operator&(const bitset<N>& rhs) const
{
    bitset tmp(*this);
    for(int i = 0; i <= _size; ++i)
    {
        tmp[i] &= rhs.arr[i];
    }
    return tmp;
}

template <size_t N>
bitset<N> bitset<N>::operator^(const bitset<N>& rhs) const
{
    bitset tmp(*this);
    for(int i = 0; i <= _size; ++i)
    {
        tmp[i] ^= rhs.arr[i];
    }
    return tmp;
}

template <size_t N>
void bitset<N>::shift_left()
{
    bool b = false;
    bool a = false;
    for(int i = 0 ; i <= _size ; ++i)
    {
        a = arr[i] & 1ull << (consts::sizeof_ull - 1);
        arr[i] <<= 1 ;
        arr[i] |= b ;
        b = a ;
    }
}

template <size_t N>
void bitset<N>::shift_right ()
{
    bool b = false;
    bool a = false;
    for(int i = _size ; i >= 0 ; --i)
    {
        a = arr[i] & 1ull ;
        arr[i] >>=  1 ;
        arr[i] |= (unsigned long long)b << (consts::sizeof_ull - 1) ;
        b = a ;
    }
}


template <size_t N>
bitset<N>& bitset<N>::operator<<=(const size_t& pos)
{
    for(int i = 0; i < pos; ++i)
    {
        shift_left();
    }
    return *this;
}

template <size_t N>
bitset<N>& bitset<N>::operator>>=(const size_t& pos)
{
    for(int i = 0; i < pos; ++i)
    {
        shift_right();
    }
    return *this;
}

template <size_t N>
bitset<N> bitset<N>::operator<<(const size_t& pos) const
{
    bitset<N> tmp(*this);
    for(int i = 0; i < pos; ++i)
    {
        tmp.shift_left();
    }
    return tmp;
}

template <size_t N>
bitset<N> bitset<N>::operator>>(const size_t& pos) const
{
    bitset<N> tmp(*this);
    for(int i = 0; i < pos; ++i)
    {
        tmp.shift_right();
    }
    return tmp;
}

