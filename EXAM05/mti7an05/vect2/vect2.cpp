#include "vect2.hpp"

// --- 1. CONSTRUCTORS & DESTRUCTOR ---

vect2::vect2(int x, int y) : _x(x), _y(y) 
{
}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) 
{
}

vect2& vect2::operator=(const vect2& other) 
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

// --- 2. ACCESS OPERATOR [] ---
// Subject gal lna : "(with 0 and 1), no bound checking is required"
// Ya3ni kn-tiqno f l-main bliy ghadi ysift ghir 0 aw 1.

int& vect2::operator[](int index) 
{
    return (index == 0) ? _x : _y;
}

int vect2::operator[](int index) const 
{
    return (index == 0) ? _x : _y;
}

// --- 3. ARITHMETIC OPERATORS (COMPOUND) ---

vect2& vect2::operator+=(const vect2& other) 
{
    this->_x += other._x;
    this->_y += other._y;
    return *this; // Hadi hiya li katkhlli (v2 += v2 += v3) t-khdem!
}

vect2& vect2::operator-=(const vect2& other) 
{
    this->_x -= other._x;
    this->_y -= other._y;
    return *this;
}

vect2& vect2::operator*=(int scalar) 
{
    this->_x *= scalar;
    this->_y *= scalar;
    return *this;
}

// --- 4. ARITHMETIC OPERATORS (BINARY) ---

vect2 vect2::operator+(const vect2& other) const 
{
    vect2 result(*this);
    result += other;
    return result;
}

vect2 vect2::operator-(const vect2& other) const 
{
    vect2 result(*this);
    result -= other;
    return result;
}

vect2 vect2::operator*(int scalar) const 
{
    vect2 result(*this);
    result *= scalar;
    return result;
}

// --- 5. UNARY MINUS ---

vect2 vect2::operator-() const 
{
    return vect2(-this->_x, -this->_y);
}

// --- 6. INCREMENT / DECREMENT ---

vect2& vect2::operator++() 
{
    // ++v : kay-zid w kay-raj3 l-value jdid
    this->_x++;
    this->_y++;
    return *this;
}

vect2 vect2::operator++(int) 
{
    // v++ : kay-khbb3 l-old value, kay-zid, w kay-raj3 old value
    vect2 temp(*this);
    ++(*this);
    return temp;
}

vect2& vect2::operator--() 
{
    this->_x--;
    this->_y--;
    return *this;
}

vect2 vect2::operator--(int) 
{
    vect2 temp(*this);
    --(*this);
    return temp;
}

// --- 7. COMPARISONS ---

bool vect2::operator==(const vect2& other) const 
{
    return (this->_x == other._x && this->_y == other._y);
}

bool vect2::operator!=(const vect2& other) const 
{
    return !(*this == other);
}

// --- 8. GLOBAL FUNCTIONS (BERRA D CLASS) ---

// Hadi bach t-khdem (3 * v2) hit Scalar howa l-lowel f l-iser
vect2 operator*(int scalar, const vect2& v) 
{
    // Kn-st3mlo (v * scalar) li msaybinha hna l-foq f l-class
    return v * scalar; 
}

// Stream Output: std::cout << "{" << v[0] << ", " << v[1] << "}"
std::ostream& operator<<(std::ostream& os, const vect2& v) 
{
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}