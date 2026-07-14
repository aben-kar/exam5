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
        bigint &operator=(const bigint& other);
        ~bigint();

        // getter
        std::string getBig() const;

        // ADD
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

        // shift right
        bigint &operator>>=(unsigned int amount);
        bigint operator>>(unsigned int amount) const;
        bigint &operator>>=(const bigint& other);
        bigint operator>>(const bigint& other) const;

        // comparaisone
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
};

std::ostream &operator<<(std::ostream &out, const bigint& other);