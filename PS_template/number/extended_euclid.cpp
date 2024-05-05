
#include<bits/stdc++.h>



template<typename T>
std::tuple<T, T, T> extended_euclid(T n, T m) {
    return extended_euclid_<T>(1, 0, 0, 1, n, m);
}

template<typename T>
std::tuple<T, T, T> extended_euclid_(T a_, T a, T b_, T b, T c, T d) {
    const T q = c / d;
    const T r = c % d;
    if (r == 0) return std::make_tuple(a, b, d);
    return extended_euclid_(a, a_ - q * a, b, b_ - q * b, d, r);
}

int main() {
    while(true) {
        int n, m; std::cin >> n >> m;
        auto[a, b, d] = extended_euclid(n, m);
        std::cout << a << ' ' << b << ' ' << d << std::endl;
    }
    
}