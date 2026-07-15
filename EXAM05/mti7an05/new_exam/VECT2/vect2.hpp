#pragma once

#include <iostream>
#include <string>

class vect2
{
    private:
        int _x;
        int _y;
    public:
        vect2(int x = 0, int y = 0);
        vect2(const vect2& other);
        vect2 &operator=(const vect2& other);
        ~vect2();

        // access
        int operator[](int index) const;
        int &operator[](int index);

        // increment and decrement
        vect2 &operator++();
        vect2 &operator--();
        vect2 operator++(int);
        vect2 operator--(int);

        // arithmetic
        vect2 operator+(const vect2& other) const;
        vect2 operator-(const vect2& other) const;
        vect2 operator*(int scalar) const;
        vect2 &operator+=(const vect2& other);
        vect2 &operator-=(const vect2& other);
        vect2 &operator*=(int scalar);

        // minus
        vect2 operator-() const;

        // comparaison
        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
};

vect2 operator*(int scalar, const vect2 &other);
std::ostream &operator<<(std::ostream &out, const vect2& other);