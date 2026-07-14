#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

class bigint
{
    private:
        std::string _big;
    public:
        // 1
        bigint(unsigned int nbr = 0);
        bigint(const bigint& other);
        bigint &operator=(const bigint& rhs);
        ~bigint();

        // 2
        std::string getBig() const;

        // ADD
        bigint &operator+=(const bigint& other);
        bigint operator+(const bigint& other) const;

        // INCREMENT
        bigint &operator++(); // b++
        bigint operator++(int); // ++b

        // SHIFT LEFT
        bigint &operator<<=(unsigned int amount);
        bigint operator<<(unsigned int amount) const;
        bigint &operator<<=(const bigint& other);
        bigint operator<<(const bigint& other) const;

        // SHIFT RIGHT
        bigint &operator>>=(unsigned int amount);
        bigint operator>>(unsigned int amount) const;
        bigint &operator>>=(const bigint& other);
        bigint operator>>(const bigint& other) const;

        // COMPARAISON
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;

};
std::ostream &operator<<(std::ostream &os, const bigint &other);