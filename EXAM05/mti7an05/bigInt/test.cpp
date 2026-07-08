// #include "bigint.hpp"
// #include <cstdlib>
// #include <algorithm>


// static std::string unsignedIntToStr(unsigned int nbr)
// {
//     if (nbr == 0)
//         return "0";
//     std::string s = "";
//     while (nbr > 0)
//     {
//         s.push_back((nbr % 10) + '0');
//         nbr /= 10;
//     }
//     std::reverse(s.begin(), s.end());
//     return s;
// }

// static unsigned int strToInt(const std::string &str)
// {
//     if (str.size() > 7)
//         return 999999;
//     return (unsigned int)std::atoi(str.c_str());
// }

// // orth
// bigint::bigint(unsigned int nbr) : _big(unsignedIntToStr(nbr))
// {
// }

// bigint::bigint(const bigint& other) : _big(other._big)
// {
// }

// bigint &bigint::operator=(const bigint& other)
// {
//     if (this != &other)
//         this->_big = other._big;
//     return *this;
// }

// bigint::~bigint()
// {
// }

// // getter
// std::string bigint::getInt() const
// {
//     return this->_big;
// }

// // ADD
// bigint bigint::operator+(const bigint& other) const
// {
//     bigint res(*this);
//     res += other;
//     return res;
// }

// bigint &bigint::operator+=(const bigint& other)
// {
//     int carry = 0;
//     int i = this->_big.size() - 1;
//     int j = other._big.size() - 1;
//     std::string res = "";
    
//     while (i >= 0 || j >= 0 || carry) { 
//         int x = (i >= 0) ? this->_big[i] - '0' : 0;
//         int y = (j >= 0) ? other._big[j] - '0' : 0;

//         int sum = x + y + carry;
//         carry = sum / 10;
//         res.push_back((sum % 10) + '0');
//         --i;
//         --j; 
//     }
//     std::reverse(res.begin(), res.end());
//     this->_big = res;
//     return *this;
// }

// // increment
// bigint &bigint::operator++()
// {
//     *this += 1;
//     return *this;
// }

// bigint bigint::operator++(int)
// {
//     bigint inc(*this);
//     *this += 1;
//     return inc;
// }

// // left shift
// bigint bigint::operator<<(unsigned int amount) const
// {
//     bigint res(*this);
//     res <<= amount;
//     return res;
// }

// bigint &bigint::operator<<=(unsigned int amount)
// {
//     if (this->_big != "0" && amount > 0)
//         this->_big.append(amount, '0');
//     return *this;
// }

// bigint bigint::operator<<(const bigint& other) const
// {
//     bigint res(*this);
//     res <<= other;
//     return res;
// }

// bigint &bigint::operator<<=(const bigint& other)
// {
//     return *this <<= strToInt(other._big);
// }