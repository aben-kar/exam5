#include "vect2.hpp"

vect2::vect2(int x, int y) : _x(x), _y(y)
{
}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y)
{
}

vect2 &vect2::operator=(const vect2& other)
{
    if (this != &other)
    {
        this->_x = other._x;
        this->_y = other._y;
    }
    return *this;
}

vect2::~vect2()
{
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return _x;
    return _y;
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return _x;
    return _y;
}

vect2 &vect2::operator++()
{
    this->_x++;
    this->_y++;
    return *this;
}

vect2 &vect2::operator--()
{
    this->_x--;
    this->_y--;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 inc(*this);
    ++(*this);
    return inc;
}

vect2 vect2::operator--(int)
{
    vect2 inc(*this);
    --(*this);
    return inc;
}

vect2 vect2::operator+(const vect2& other) const
{
    vect2 sum(*this);
    sum += other;
    return sum;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 res(*this);
    res -= other;
    return res;
}

vect2 vect2::operator*(int scalar) const
{
    vect2 multi(*this);
    multi *= scalar;
    return multi;
}

vect2 &vect2::operator+=(const vect2& other)
{
    this->_x += other._x;
    this->_y += other._y;
    return *this;
}

vect2 &vect2::operator-=(const vect2& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    return *this;
}

vect2 &vect2::operator*=(int scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    return *this;
}

vect2 vect2::operator-() const
{
    return vect2(-this->_x, -this->_y);
}

bool vect2::operator==(const vect2& other) const
{
    return (this->_x == other._x && this->_y == other._y);
}

bool vect2::operator!=(const vect2& other) const
{
    return !(*this == other);
}

vect2 operator*(int scalar, const vect2& other)
{
    return other * scalar;
}

std::ostream &operator<<(std::ostream &out, const vect2& other)
{
    out << "{" << other[0] << ", " << other[1] << "}";
    return out;
}