#pragma once

#include <algorithm>
#include <iostream>
#include <cstdlib>

class bigint
{
    private:
        std::string _big;
    public:
        bigint(unsigned int nbr = 0);
        bigint(const bigint& other);
        bigint &operator=(const bigint& other);
        ~bigint();

        // geterr
        std::string getBig() const;

        // add
        bigint &operator+=(const bigint& other);
        bigint operator+(const bigint& other) const;

        // increment
        bigint &operator++();
        bigint operator++(int);

        // shift left
        bigint &operator<<=(unsigned int amount);
        bigint operator<<(unsigned int amount) const;
        bigint &operator<<=(const bigint& other);
        bigint operator<<(const bigint& other) const;

        // right shift
        bigint &operator>>=(unsigned int amount);
        bigint operator>>(unsigned int amount) const;
        bigint &operator>>=(const bigint& other);
        bigint operator>>(const bigint& other) const;

        // comparaison
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
};
std::ostream &operator<<(std::ostream &out, const bigint& other);