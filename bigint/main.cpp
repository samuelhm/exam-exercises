#include "bigint.hpp"
#include <iostream>

int main()
{
    bigint a;
    bigint b(42);
    bigint c(1337);
    bigint d(b);

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';
    std::cout << "d = " << d << '\n';
}
