#include<iostream>

#include <algorithm>

constexpr unsigned gcd(unsigned u, unsigned v)
{
    if (u == v || u == 0 || v == 0)
        return u | v;
    
    unsigned shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    v >>= __builtin_ctz(v);

    const auto &[min, max] = std::minmax(u, v);

    return gcd(max - min, min) << shift;
}

int main() {
    while (true) {
        unsigned int a, b;
        std::cin >> a >> b;
        std::cout << gcd(a, b) << '\n';
    }
}