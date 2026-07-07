#include <iostream>
#include <sstream>

class bigint
{
private:
    std::string _str;

public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint &other);
    bigint &operator=(const bigint &other);
    ~bigint();

    std::string getStr() const;

    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);

    bigint& operator++();
    bigint operator++(int);

    bigint operator<<(unsigned int num) const;
    bigint operator>>(unsigned int num) const;
    bigint operator<<=(unsigned int num);
    bigint operator>>=(unsigned int num);

    bigint operator<<(const bigint &other) const;
    bigint operator>>(const bigint &other) const;
    bigint operator<<=(const bigint &other);
    bigint operator>>=(const bigint &other);

    bool operator>(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    bool operator<(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;
};

std::string IntToStr(unsigned int num);
unsigned int StrToInt(std::string str);
std::string reverse(const std::string str);
std::string addition(const bigint &obj1, const bigint &obj2);
std::ostream &operator<<(std::ostream &os, const bigint &other)
{
    os << other.getStr();
    return os;
}

bigint::bigint()
{
    this->_str = "0";
}
bigint::~bigint()
{
}
bigint::bigint(unsigned int num)
{
    this->_str = IntToStr(num);
}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
    {
        this->_str = other._str;
    }
    return (*this);
}
bigint::bigint(const bigint &other)
{
    this->_str = other._str;
}

std::string bigint::getStr() const
{
    return (this->_str);
}
std::string IntToStr(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    return (ss.str());
}

unsigned int StrToInt(std::string str)
{
    std::stringstream ss;
    unsigned int _num;
    ss <<str;
    ss >> _num;
    return _num;
}

std::string reverse(const std::string str)
{
    size_t len = str.length();
    std::string RevStr;
    for (size_t i = len; i > 0; i--)
    {
        RevStr.push_back(str[i - 1]);
    }
    return RevStr;
}

std::string addition(const bigint &obj1, const bigint &obj2)
{
    std::string Str1 = reverse(obj1.getStr());
    std::string Str2 = reverse(obj2.getStr());

    size_t len1 = Str1.length();
    size_t len2 = Str2.length();

    if (len2 > len1)
    {
        size_t diff = len2 - len1;
        for (size_t i = 0; i < diff; i++)
        {
            Str1.push_back('0');
        }
    }

    if (len1 > len2)
    {
        size_t diff = len1 - len2;
        for (size_t i = 0; i < diff; i++)
        {
            Str2.push_back('0');
        }
    }

    int digit1;
    int digit2;
    std::string result;
    int carry = 0;

    for (size_t i = 0; i < Str2.length(); i++)
    {
        digit1 = Str1[i] - '0';
        digit2 = Str2[i] - '0';

        int res = digit1 + digit2 + carry;
        if (res > 9)
        {
            carry = res/10;
            result.push_back(res % 10 + '0');
        }
        else
        {
            carry = 0;
            result.push_back(res + '0');
        }
    }
    if (carry != 0)
        result.push_back(carry + '0');
    return (reverse(result));
}

bigint bigint::operator+(const bigint &other) const
{
    bigint tmp(*this);
    tmp._str = addition((*this), other);
    return tmp;
}

bigint &bigint::operator+=(const bigint &other)
{
    (*this) = (*this) + other;
    return (*this);
}

bigint& bigint::operator++()
{
    (*this) += bigint(1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint tmp(*this);
    (*this) += bigint(1);
    return (tmp);
}

bigint bigint::operator<<(const bigint &other) const
{
    return ((*this) << StrToInt(other._str));
}
bigint bigint::operator>>(const bigint &other) const
{
    return ((*this) >> StrToInt(other._str));
}

bigint bigint::operator<<=(const bigint &other)
{
    (*this) = (*this) << StrToInt(other._str);
    return (*this);
}
bigint bigint::operator>>=(const bigint &other)
{
    (*this) = (*this) >> StrToInt(other._str);
    return (*this);
}

bigint bigint::operator<<(unsigned int num) const
{
    bigint tmp = *this;
    tmp._str.insert(tmp._str.end(), num, '0');
    return tmp;
}
bigint bigint::operator>>(unsigned int num) const
{
    bigint tmp = *this;
    size_t len = tmp._str.length();
    if (num >= len)
    {
        tmp._str = "0";
    }
    else
    {
        tmp._str.erase(tmp._str.length() - num, num);
        if(tmp._str.empty())
            tmp._str = "0";
    }
    return (tmp);
}

bigint bigint::operator<<=(unsigned int num)
{
    (*this) = (*this) << num;
    return (*this);
}
bigint bigint::operator>>=(unsigned int num)
{
    (*this) = (*this) >> num;
    return (*this);
}

bool bigint::operator>(const bigint &other) const
{   
    size_t len1 = other._str.length();
    size_t len2 = this->_str.length();
    if(len1 != len2)
        return (len2 > len1);
    return(this->_str > other._str);
    

}
bool bigint::operator>=(const bigint &other) const{
    return ((*this) > other || (*this) == other);
}
bool bigint::operator<(const bigint &other) const{

    size_t len1 = other._str.length();
    size_t len2 = this->_str.length();
    if(len1 != len2)
        return (len2 < len1);
    return(this->_str < other._str);
}
bool bigint::operator<=(const bigint &other) const{
    return ((*this) < other || (*this) == other);

}
bool bigint::operator==(const bigint &other) const{
    return (other._str == this->_str);
}
bool bigint::operator!=(const bigint &other) const{
    return (other._str != this->_str);

}


// the main is given in the subject 
int main()
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;
}




// [EN]
// Assignment name : bigint
// Expected files : bigint.hpp, bigint.cpp
// --------------------------------------------------------------------------------
// In computer science a bignum is an object representing an arbitrary precision
// number, this is useful when you want to store a number bigger than SIZE_MAX
// without any loss of precision. This is often achieved by storing an array or a
// string containing the different "parts" of the number.
// Create a class called bigint that will store an arbitrary precision unsigned
// integer.
// Your class must support addition, comparison and "digitshift" (like bitshift but
// instead of shifting the bits you will shift the digits in base 10, e.g.:
// (42 << 3 == 42000) and (1337 >> 2 == 13)).
// Your bigint must be printable with the << operator (in base 10) and the output
// should not contain any leading zeros.
// You will find a main in this directory that must work with your class

// [TR]
// Bilgisayar bilimlerinde bignum, keyfi bir hassasiyetteki sayıyı temsil eden bir nesnedir.
// Bu, herhangi bir hassasiyet kaybı olmadan SIZE_MAX değerinden büyük bir sayıyı depolamak istediğinizde kullanışlıdır.
// Bu genellikle sayının farklı "kısımlarını" içeren bir dizi veya dize depolayarak elde edilir.

// keyfi bir hassasiyetteki işaretsiz tamsayıyı depolayacak bigint adlı bir sınıf oluşturun.
// Sınıfınız toplama, karşılaştırma ve "rakam kaydırma" işlemlerini desteklemelidir
// (bit kaydırma gibi, ancak bitleri kaydırmak yerine 10 tabanındaki rakamları kaydırırsınız
// örneğin: (42 << 3 == 42000) ve (1337 >> 2 == 13)).

// bigint değeriniz << operatörüyle (10 tabanında) yazdırılabilir olmalı ve çıktıda başta sıfır bulunmamalıdır.

// Bu dizinde, sınıfınızla uyumlu olması gereken bir main bulacaksınız.

// [SUBJECT MAIN]
// #include "bigint.hpp"
// #include <iostream>

// int main()
// {
//     const bigint a(42);
//     bigint b(21), c, d(1337), e(d);

//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << "e = " << e << std::endl;

//     std::cout << "a + b = " << a + b << std::endl;
//     std::cout << "(c += a) = " << (c += a) << std::endl;

//     std::cout << "b = " << b << std::endl;
//     std::cout << "++b = " << ++b << std::endl;
//     std::cout << "b++ = " << b++ << std::endl;

//     std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
//     std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
//     std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

//     std::cout << "a =" << a << std::endl;
//     std::cout << "d =" << d << std::endl;

//     std::cout << "(d < a) = " << (d < a) << std::endl;
//     std::cout << "(d <= a) = " << (d <= a) << std::endl;
//     std::cout << "(d > a) = " << (d > a) << std::endl;
//     std::cout << "(d >= a) = " << (d >= a) << std::endl;
//     std::cout << "(d == a) = " << (d == a) << std::endl;
//     std::cout << "(d != a) = " << (d != a) << std::endl;
// }
