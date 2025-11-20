#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int a, int b) : _x(a), _y(b) {}

int& vect2::operator[](std::size_t i)
{
     return (i == 0 ? _x : _y);
}
const int& vect2::operator[](std::size_t i) const
{
    return (i == 0 ? _x : _y);
}
vect2& vect2::operator+=(const vect2 &vec)
{
    _x += vec._x;
    _y += vec._y;
    return *this;
}

vect2& vect2::operator-=(const vect2 &vec)
{
    _x -= vec._x;
    _y -= vec._y;
    return *this;
}
vect2& vect2::operator*=(int value)
{
    _x *= value;
    _y *= value;
    return *this;
}

vect2 operator*(int value, const vect2 &v2)
{
    vect2 vec = v2;
    vec *= value;
    return vec;
}

vect2 operator+(const vect2 &v1, const vect2 &v2)
{
    vect2 vec = v1;
    vec += v2;
    return vec;
}
vect2 operator-(const vect2 &v1, const vect2 &v2)
{
    vect2 vec = v1;
    vec -= v2;
    return vec;
}
vect2 vect2::operator*(int value) const
{
    vect2 vec = *this;
    vec *= value;
    return vec;
}
vect2& vect2::operator++()
{
    _x++;
    _y++;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 tmp = *this;
    _x++;
    _y++;
    return tmp;
}

vect2& vect2::operator--()
{
    _x--;
    _y--;
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 tmp = *this;
    _x--;
    _y--;
    return tmp;
}
bool vect2::operator==(const vect2 &vec) const
{
    return (_x == vec._x && _y == vec._y);
}

bool vect2::operator!=(const vect2 &vec) const
{
    return !(*this == vec);
}
vect2 vect2::operator-() const
{
    vect2 vec(-_x,-_y);
    return vec;
}

std::ostream& operator<<(std::ostream &os, const vect2 &v)
{
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}


