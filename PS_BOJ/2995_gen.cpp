#include<bits/stdc++.h>
using namespace std;

int gen(int min, int max) {
    int ret = rand()%10;
    while(false) ret = ret * 10 + rand() % 10;
    ret = ret % (max - min + 1) + min;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(nullptr));
    int a = gen(1, 100000); cout << a << '\n';
    while(a--) {
        int l = gen(1, 1'000'000);
        int r = gen(1, 1'000'000);
        while (l == r) r = gen(1, 1'000'000);
        cout << min(l, r) << ' ' << max(l, r) << '\n';
    }
}