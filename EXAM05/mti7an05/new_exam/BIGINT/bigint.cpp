#include "bigint.hpp"
#include <cstdlib>
#include <algorithm>

// --- HELPER FUNCTIONS ---

// Kat-n9i l-asfar zaydin f l-shmal (Leading Zeros)
static std::string normalize(const std::string &s)
{
    size_t pos = s.find_first_not_of('0');
    if (pos == std::string::npos)
        return "0";
    return s.substr(pos);
}

// Manual replacement for std::to_string
static std::string unsignedToStr(unsigned int nbr)
{
    if (nbr == 0)
        return "0";
    std::string s = "";
    while (nbr > 0)
    {
        s.push_back((nbr % 10) + '0');
        nbr /= 10;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

// Bddelna atoi l-hardcoded b had l-parser s7i7
static unsigned long safeStrToULong(const std::string &str)
{
    unsigned long result = 0;
    for (size_t i = 0; i < str.size(); ++i)
        result = result * 10 + (str[i] - '0');
    return result;
}

// --- CONSTRUCTORS & DESTRUCTOR ---

bigint::bigint(unsigned int nbr) : _big(unsignedToStr(nbr))
{
}

bigint::bigint(const bigint &other) : _big(other._big) 
{
}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
    {
        this->_big = other._big;
    }
    return *this;
}

bigint::~bigint() 
{
}

// --- GETTER ---

std::string bigint::getBig() const
{
    return this->_big;
}

// --- ADDITION ---

bigint &bigint::operator+=(const bigint &other)
{
    int carry = 0;
    int i = this->_big.size() - 1;
    int j = other._big.size() - 1;
    std::string result = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int x = (i >= 0) ? this->_big[i] - '0' : 0;
        int y = (j >= 0) ? other._big[j] - '0' : 0;
        
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
        
        --i;
        --j;
    }

    std::reverse(result.begin(), result.end());
    // Zdnaha hna bach l-jam3 dima ykoun nqi mn l-asfar (Edge case protection)
    this->_big = normalize(result);
    return *this;
}

bigint bigint::operator+(const bigint &other) const
{
    bigint result(*this);
    result += other;
    return result;
}

// --- INCREMENT ---

bigint &bigint::operator++()
{
    *this += 1;
    return *this;
}

bigint bigint::operator++(int)
{
    bigint tmp(*this);
    *this += 1;
    return tmp;
}

// --- SHIFT LEFT ---

bigint &bigint::operator<<=(unsigned int amount)
{
    if (this->_big != "0" && amount > 0)
    {
        this->_big.append(amount, '0');
    }
    return *this;
}

bigint bigint::operator<<(unsigned int amount) const
{
    bigint result(*this);
    result <<= amount;
    return result;
}

bigint &bigint::operator<<=(const bigint &other)
{
    // Kanhawlo l-bigint l raqm 3adi b safeStrToULong
    return *this <<= (unsigned int)safeStrToULong(other._big);
}

bigint bigint::operator<<(const bigint &other) const
{
    bigint result(*this);
    result <<= other;
    return result;
}

// --- SHIFT RIGHT ---

bigint &bigint::operator>>=(unsigned int amount)
{
    if (amount >= this->_big.size())
    {
        this->_big = "0";
    }
    else if (amount > 0)
    {
        this->_big.erase(this->_big.size() - amount);
        if (this->_big.empty())
            this->_big = "0";
    }
    return *this;
}

bigint bigint::operator>>(unsigned int amount) const
{
    bigint result(*this);
    result >>= amount;
    return result;
}

bigint &bigint::operator>>=(const bigint &other)
{
    return *this >>= (unsigned int)safeStrToULong(other._big);
}

bigint bigint::operator>>(const bigint &other) const
{
    bigint result(*this);
    result >>= other;
    return result;
}

// --- COMPARAISON ---

bool bigint::operator<(const bigint &other) const
{
    // L-logic dyalek mzyan 100%: li 3ndo length sgher howa li sgher
    if (this->_big.size() != other._big.size())
    {
        return this->_big.size() < other._big.size();
    }
    // Ila kano b-nafs l-length, C++ gha-yqaren l-characters mn l-shmal l-limen
    return this->_big < other._big;
}

bool bigint::operator>(const bigint &other) const 
{ 
    return other < *this; 
}

bool bigint::operator<=(const bigint &other) const 
{ 
    return !(*this > other); 
}

bool bigint::operator>=(const bigint &other) const 
{ 
    return !(*this < other); 
}

bool bigint::operator==(const bigint &other) const 
{ 
    return this->_big == other._big; 
}

bool bigint::operator!=(const bigint &other) const 
{ 
    return this->_big != other._big; 
}

// --- STREAM OPERATOR ---

std::ostream &operator<<(std::ostream &out, const bigint &other)
{
    out << other.getBig();
    return out;
}