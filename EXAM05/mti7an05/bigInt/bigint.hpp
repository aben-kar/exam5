#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
    public:
        // orth
        bigint(unsigned int nbr = 0);
        ~bigint();
        bigint(const bigint& other);
        bigint &operator=(const bigint& other);

        // get
        std::string getInt() const;

        //add
        bigint operator+(const bigint& other) const;
        bigint &operator+=(const bigint& other);

        // increment
        bigint &operator++();
        bigint operator++(int);

        // shift left
        bigint operator<<(unsigned int amount) const;
        bigint &operator<<=(unsigned int amount);
        bigint operator<<(const bigint& other) const;
        bigint &operator<<=(const bigint& other);

        // right shift
        bigint operator>>(unsigned int amount) const;
        bigint &operator>>=(unsigned int amount);
        bigint operator>>(const bigint& other) const;
        bigint &operator>>=(const bigint& other);

        //comparaison
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
    private:
        std::string _big;
};

std::ostream &operator<<(std::ostream& out, const bigint& other);
#endif