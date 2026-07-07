#include <iostream>
#include <sstream>

class vect2
{
private:
    int x;
    int y;

public:
    vect2();
    vect2(const vect2 &other);
    vect2 &operator=(const vect2 &other);
    vect2(int _x, int _y);
    vect2 &operator++();
    vect2 operator++(int);
    vect2 &operator--();
    vect2 operator--(int);
    vect2 operator-() const;
    vect2 operator*(int num) const;
    vect2 operator*=(int num);
    vect2 operator+(const vect2 &other) const;
    vect2 operator-(const vect2 &other) const;
    vect2 operator*(const vect2 &other) const;

    int &operator[](int index);
    int operator[](int index) const;
    vect2 &operator+=(const vect2 &other);
    vect2 &operator-=(const vect2 &other);
    vect2 &operator*=(const vect2 &other);
    bool operator==(const vect2 &other) const;
    bool operator!=(const vect2 &other) const;

    ~vect2();
};

vect2 operator*(int num, const vect2 &other);

vect2 vect2::operator-() const
{
    vect2 tmp(*this);
    tmp.x = -tmp.x;
    tmp.y = -tmp.y;
    return tmp;
}

vect2 &vect2::operator++()
{
    this->x += 1;
    this->y += 1;
    return (*this);
}
vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    ++(*this);
    return tmp;
}
vect2 &vect2::operator--()
{
    this->x -= 1;
    this->y -= 1;
    return (*this);
}
vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    --(*this);
    return tmp;
}

vect2 vect2::operator+(const vect2 &other) const
{
    vect2 tmp(*this);
    tmp.x += other.x;
    tmp.y += other.y;
    return tmp;
}

vect2 vect2::operator*(const vect2 &other) const
{
    vect2 tmp(*this);
    tmp.x *= other.x;
    tmp.y *= other.y;
    return tmp;
}
vect2 vect2::operator-(const vect2 &other) const
{
    vect2 tmp(*this);
    tmp.x -= other.x;
    tmp.y -= other.y;
    return tmp;
}

bool vect2::operator==(const vect2 &other) const
{
    return (this->x == other.y) && (this->y == other.y);
}

vect2 &vect2::operator*=(const vect2 &other)
{
    this->x *= other.x;
    this->y *= other.y;

    return (*this);
}

vect2 &vect2::operator-=(const vect2 &other)
{
    this->x -= other.x;
    this->y -= other.y;

    return (*this);
}

vect2 &vect2::operator+=(const vect2 &other)
{
    this->x += other.x;
    this->y += other.y;

    return (*this);
}

bool vect2::operator!=(const vect2 &other) const
{
    return (this->x != other.y) || (this->y != other.y);
}

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}
vect2 &vect2::operator=(const vect2 &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return (*this);
}

vect2::vect2(const vect2 &other)
{
    this->x = other.x;
    this->y = other.y;
}

vect2::~vect2()
{
}

std::ostream &operator<<(std::ostream &os, const vect2 &other)
{
    os << "{" << other[0] << ", " << other[1] << "}" << std::endl;
    return os;
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return (this->x);
    return (this->y);
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return (this->x);
    return (this->y);
}

vect2 vect2::operator*(int num) const
{
    vect2 tmp(*this);

    tmp.x *= num;
    tmp.y *= num;
    return (tmp);
}
vect2 operator*(int num, const vect2 &other)
{
    vect2 tmp(other);
    tmp *= num;
    return (tmp);
}

vect2 vect2::operator*=(int num)
{
    this->x *= num;
    this->y *= num;
    return (*this);
}
int main()
{
    vect2 v1;           // 0, 0
    vect2 v2(1, 2);     // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2;      // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << v4++ << std::endl; // 2, 3
    std::cout << ++v4 << std::endl; // 3, 4
    std::cout << v4-- << std::endl; // 2, 3
    std::cout << --v4 << std::endl; // 1, 2
    v2 += v3;                       // 2, 4
    v1 -= v2;                       // -2, -4
    v2 = v3 + v3 * 2;               // 3, 6
    v2 = 3 * v2;                    // 9, 18
    v2 += v2 += v3;                 // 20, 40
    v1 *= 42;                       // -84, -168
    v1 = v1 - v1 + v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}



// Assignement name: vect2
// Expected files: vect2.cpp, vect2.hpp
// -------------------------------------------------------------------------------------------

// Create a class vect2 representing a mathematical vector of dimension 2 containing ints.

// It must support addition, substraction and multiplication by a scalar (such as the expression (vect2(2,2) * 2 == vect2(4,4)) is true).

// the operator [] can be used to access the component of your vector (with 0 and 1), no bound checking is required.

// Your function must be printable with the << operator such as:
//         std::cout << v << std::endl;
// produce the same output as:
//         std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;

// You will find a main in this directory that must work with your class.

// #include "vect2.hpp"
// #include <iostream>

// int main()
// {
//     vect2 v1; // 0, 0
//     vect2 v2(1, 2); // 1, 2
//     const vect2 v3(v2); // 1, 2
//     vect2 v4 = v2; // 1, 2

//     std::cout << "v1: " << v1 << std::endl;
//     std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
//     std::cout << "v2: " << v2 << std::endl;
//     std::cout << "v3: " << v3 << std::endl;
//     std::cout << "v4: " << v4 << std::endl;
//     std::cout << v4++ << std::endl; // 2, 3
//     std::cout << ++v4 << std::endl; // 3, 4
//     std::cout << v4-- << std::endl; // 2, 3
//     std::cout << --v4 << std::endl; // 1, 2
//     v2 += v3; // 2, 4
//     v1 -= v2; // -2, -4
//     v2 = v3 + v3 *2; // 3, 6
//     v2 = 3 * v2; // 9, 18
//     v2 += v2 += v3; // 20, 40
//     v1 *= 42; // -84, -168
//     v1 = v1 - v1 +v1;
//     std::cout << "v1: " << v1 << std::endl;
//     std::cout << "v2: " << v2 << std::endl;
//     std::cout << "-v2: " << -v2 << std::endl;
//     std::cout << "v1[1]: " << v1[1] << std::endl;
//     v1[1] = 12;
//     std::cout << "v1[1]: " << v1[1] << std::endl;
//     std::cout << "v3[1]: " << v3[1] << std::endl;
//     std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
//     std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
//     std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
//     std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
// }
