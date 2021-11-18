#include <iostream>
#include <cstring>
class String {
public:
    String();
    String(unsigned int count, char simbol ) ;
    String(const char* str) ;
    String(const String& other) ;
    String(String&& rother);
    ~String() ;
    String& operator= (String&& str) ;
    String& operator= (const String& str) ;
    String operator+ (const String& str) const ;
    String& operator+= (const String& str) ;
    String operator+ (const char) const ;
    String& operator+= (const char) ;
    bool operator> (const String& str) const ;
    bool operator< (const String& str) const ;
    bool operator== (const String& str) const ;
    bool operator!= (const String& str) const ;
    bool operator>= (const String& str) const ;
    bool operator<= (const String& str) const ;
    void push_back (char simbol) ;
    char pop_back () ;
    void push_front (char simbol) ;
    char pop_front () ;
    void resize (const int count, char simbol) ;
    String erase (const int index, int count) ;
    char erase (const int index);
    int find (const char) const ;
    int find (const String &) const ;
    int find (const char*) ;
    void insert (const int index, int count, char simbol) ;
    void insert (const int index, char simbol) ;
    void insert (const int index, const char* simbols) ;
    void insert (const int index, String str) ;
    const char& operator[] (const unsigned int index) const{ return buffer[index] ; }
    char& operator[] (const unsigned int index){ return buffer[index] ; }
    char& at (const unsigned int index) ;
    friend std::ostream & operator << (std::ostream & os,const String & obj) ;
private:
    unsigned int size = 0;
    char * buffer ;
} ;
std::ostream & operator << (std::ostream & os,const String & obj)
{
    return os << obj.buffer ;
}
String::~String()
{
    delete [] buffer ;
}
String::String()
{
    size = 1 ;
    buffer = new char[size] ;
}
String::String(unsigned int count, char simbol )
{
    size = count ;
    buffer = new char[size] ;
    for(int i = 0 ; i < count; ++i)
    {
        buffer[i] = simbol ;
    }
}

String::String(const String& other)
{
    size = other.size ;
    buffer = new char[size] ;
    for(int i = 0; i < size ; ++i) {
        buffer[i] = other[i] ;
    }
}

String::String(const char* str)
{
    size = std::strlen(str) ;
    buffer = new char[size] ;
    for(int i = 0 ; i < size; ++i)
    {
        buffer[i] = str[i] ;
    }
}

String::String(String&& rother)
{
    size = rother.size ;
    buffer = rother.buffer ;
    rother.buffer = nullptr ;
}

String String::operator+ (const String& str) const
{
    String tmp ;
    char * t = new char[this->size + str.size - 1] ;
    int g = 0 ;
    for(; g < this->size ; ++g) {
        t[g] = this->buffer[g] ;
    }
    for(int i = 0; i < str.size ; ++i , ++g) {
        t[g] = str.buffer[i] ;
    }
    tmp.size = this->size + str.size  ;
    tmp.buffer = t;
    t = nullptr ;
    return tmp ;
}

String& String::operator= (const String& str)
{
    if(this == &str) {
        return *this ;
    }
    delete [] this->buffer ;
    this->size = str.size ;
    this->buffer = new char[size] ;
    for(int i = 0; i < size; ++i)
        buffer[i] = str[i] ;
    return *this ;
}

String& String::operator= (String&& str)
{
    this->size = str.size ;
    this->buffer = str.buffer ;
    str.buffer = nullptr ;
    return *this ;
}

String& String::operator+= (const String& str)
{
    char * t = new char[this->size + str.size - 1] ;
    int g = 0 ;
    for(; g < this->size ; ++g) {
        t[g] = this->buffer[g] ;
    }
    for(int i = 0; i < str.size ; ++i , ++g) {
        t[g] = str.buffer[i];
    }
    delete [] this->buffer ;
    this->size += str.size ;
    this->buffer = t ;
    t = nullptr ;
    return *this ;
}

void String::push_back (char simbol)
{
    char * tmp = new char[size + 1] ;
    for(int i = 0; i < size ; ++i) {
        tmp[i] = this->buffer[i] ;
    }
    tmp[size + 1] = simbol ;
    delete []this->buffer ;
    this->buffer = tmp ;
    ++size ;
}

String String::operator+ (const char ch) const
{
    String tmp = *this ;
    tmp.push_back(ch) ;
    return tmp ;
}

String& String::operator+= (const char ch)
{
    this->push_back(ch) ;
    return *this ;
}

bool String::operator> (const String& str) const
{
    return this->size > str.size ;
}

bool String::operator< (const String& str) const
{
    return this->size < str.size ;
}

bool String::operator>= (const String& str) const
{
    return this->size >= str.size ;
}

bool String::operator<= (const String& str) const
{
    return this->size <= str.size ;
}

bool String::operator== (const String& str) const
{
    if(this->size != str.size)
        return false ;
    bool equal = true ;
    for(int i = 0 ; i < size; ++i) {
        if(buffer[i] != str[i])
            equal = false ;
    }
    return equal ;
}

bool String::operator!= (const String& str) const
{
    if(this->size != str.size)
        return true ;
    bool unequal = true ;
    for(int i = 0 ; i < size; ++i) {
        if(buffer[i] == str[i])
            unequal = false ;
    }
    return unequal ;
}

char String::pop_back() {
    char ch = buffer[size] ;
    char *tmp = new char[size - 1] ;
    for(int i = 0; i < size - 1; i++) {
        tmp[i] = buffer[i] ;
    }
    delete [] buffer ;
    buffer= tmp ;
    size-- ;
    return ch ;
}

void String::push_front (char simbol)
{
    char *tmp = new char[size + 1] ;
    tmp[0] = simbol ;
    for(int i = 1 , j = 0; i < size; ++j,++i) {
        tmp[i] = buffer[j] ;
    }
    delete [] buffer ;
    buffer = tmp ;
    size++ ;
}
char String::pop_front ()
{
    char ch = buffer[0] ;
    char *tmp = new char[size - 1] ;
    for(int i = 0, j = 1; i < size - 1; ++i, ++j) {
        tmp[i] = buffer[j] ;
    }
    delete [] buffer ;
    buffer = tmp ;
    --size ;
    return ch ;
}

void String::resize (const int count, char simbol)
{
    if(count <= size) return ;
    char * tmp = buffer ;
    buffer = new char[count] ;
    for(int i = 0; i < size ; ++i) {
        buffer[i] = tmp[i] ;
    }
    for(int i = size; i < count ; ++i) {
        buffer[i] = simbol ;
    }
    return ;
}

void String::insert (const int index, int count, char simbol)
{
    char * tmp = buffer ;
    buffer = new char[size + count] ;
    for(int i = 0; i < index ; ++i) {
        buffer[i] = tmp[i] ;
    }
    for(int i = index ; i < index + count ; ++i) {
        buffer[i] = simbol ;
    }
    for(int i = index + count, j = index ; i < size + count ; ++i , ++j) {
        buffer[i] = tmp[j] ;
    }
    size += count;
}

String String::erase (const int index, int count)
{
    char * tmp = buffer ;
    buffer = new char[size - count] ;
    for(int i = 0; i < index ; ++i) {
        buffer[i] = tmp[i] ;
    }
    for(int i = index, j = index + count ; i < size + count ; ++i , ++j) {
        buffer[i] = tmp[j] ;
    }
    size -= count ;
    return {} ;
}
char String::erase (const int index)
{
    char ch = buffer[index] ;
    char * tmp = buffer ;
    buffer = new char[size - 1] ;
    for(int i = 0; i < index; ++i )
    {
        buffer[i] = tmp[i] ;
    }
    for(int i = index + 1 ; i < size; ++i)
    {
        buffer[i - 1] = tmp[i] ;
    }
    delete [] tmp ;
    tmp = nullptr ;
    return ch ;
}

int String::find (const char ch) const
{
    for(int i = 0 ; i < size ; ++i) {
        if(buffer[i] == ch) return ch ;
    }
    return -1 ;
}

int String::find (const String & str) const
{
    bool equal = false ;
    unsigned int positon = -1 ;
    for(int i = 0; i < size; ++i) {
        if(buffer[i] == str[0]) {
            positon = i ;
            for (int j = 0; j < str.size ; ++j) {
                 if(buffer[i + j] != str[j]) {
                    equal = true;
                    break ;
                }
            }
            if(!equal) return positon ;
        }
    }
    return -1 ;
}

int String::find (const char* str)
{
    bool equal = false ;
    unsigned int positon = -1 ;
    for(int i = 0; i < size; ++i) {
        if(buffer[i] == str[0]) {
            positon = i ;
            for (int j = 0; j < std::strlen(str) ; ++j) {
                if(buffer[i + j] != str[j]) {
                    equal = true;
                    break ;
                }
            }
            if(!equal) return positon ;
        }
    }
    return -1 ;
}

void String::insert (const int index, char simbol)
{
    char * tmp = buffer ;
    buffer = new char[size + 1] ;
    for(int i = 0; i < index; ++i)
    {
        buffer[i] = tmp[i] ;
    }
    buffer[index] = simbol ;
    for(int i = index ; i < size; ++i)
    {
        buffer[i + 1] = tmp[i] ;
    }
    delete [] tmp ;
    tmp = nullptr ;
    ++size ;
}

void String::insert (const int index, const char* simbols)
{
    const unsigned int simbols_size = std::strlen(simbols) ;
    char * tmp = buffer ;
    buffer = new char[size += simbols_size] ;
    for(int i = 0; i < index; ++i)
    {
        buffer[i] = tmp[i] ;
    }
    for(int i = 0, j = index ; i < simbols_size ; ++i , ++j)
    {
        buffer[j] = simbols[i] ;
    }
    for(int i = index + simbols_size, j = index ; i < size ; ++i , ++j)
    {
        buffer[i] = tmp[j] ;
    }
    delete [] tmp ;
    tmp = nullptr ;
}

void String::insert (const int index, String str)
{
    char * tmp = buffer ;
    buffer = new char [size += str.size] ;
    for(int i = 0 ;i < index ; ++i) {
        buffer[i] = tmp[i] ;
    }
    for(int i = 0, j = index ; i < str.size ; ++i , ++j)
    {
        buffer[j] = str[i] ;
    }
    for(int i = index + str.size, j = index ; i < size ; ++i , ++j)
    {
        buffer[i] = tmp[j] ;
    }
    delete [] tmp;
    tmp = nullptr ;
}

char& String::at (const unsigned int index)
{
    if(index >= size) {
        std::cerr << "out_of_range" << std::endl ;
        exit(2) ;
    }
    return buffer[index] ;
}
