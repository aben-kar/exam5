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

// access
int vect2::operator[](int i) const
{
    if (i == 0)
        return _x;
    return _y;
}

int &vect2::operator[](int i)
{
    if (i == 0)
        return _x;
    return _y;
}

// increment and decrement
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
    vect2 tmp(*this);
    ++(*this);
    return tmp;
}

vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    --(*this);
    return tmp;
}

// arithmetic
vect2 vect2::operator+(const vect2& other) const
{
    vect2 res(*this);
    res += other;
    return res;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 res(*this);
    res -= other;
    return res;
}

vect2 vect2::operator*(int scalar) const
{
    vect2 res(*this);
    res *= scalar;
    return res;
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

// minus
vect2 vect2::operator-() const
{
    return vect2(-this->_x, -this->_y);
}

// comparaisone
bool vect2::operator==(const vect2& other) const
{
    return (this->_x == other._x && this->_y == other._y);
}

bool vect2::operator!=(const vect2& other) const
{
    return !(*this != other);
}

vect2 operator*(int scalare, const vect2& other)
{
    return other * scalare;
}

std::ostream &operator<<(std::ostream &out, const vect2& other)
{
    out << "{" << other[0] << ", " << other[1] << "}";
    return out;
}