#include <iostream>
using namespace std;
int main() {
    long long a = 9223372036854775807LL;
    float b = 9223372036854775806LL;
    long long c = 9223372036854775806LL;
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}