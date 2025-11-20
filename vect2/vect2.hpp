#pragma once
#include <ostream>
#include <cstddef>

class vect2
{
    private:
    int _x;
    int _y;

    public:
    vect2();
    vect2(int, int);

    int& operator[](std::size_t i);
    const int& operator[](std::size_t i) const;
    
    vect2 operator*(int value) const;

    vect2& operator+=(const vect2 &vec);
    vect2& operator-=(const vect2 &vec);
    vect2& operator*=(int value);
    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);
    bool operator==(const vect2 &vec) const;
    bool operator!=(const vect2 &vec) const;
    vect2 operator-() const;
    friend std::ostream& operator<<(std::ostream &os, const vect2 &v);
    
};

vect2 operator+(const vect2 &v1, const vect2 &v2);
vect2 operator-(const vect2 &v1, const vect2 &v2);
vect2 operator*(int value, const vect2 &v);
