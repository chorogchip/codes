#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N;

bool isU(int n) {
    vector<int> v;
    do v.push_back(n % 10); while (n /= 10);
    int s = v.size();
    for (int i = 1; i < s; ++i) {
        int x = 1, y = 1;
        for (int j = 0; j < i; ++j) x *= v[j];
        for (int j = i; j < s; ++j) y *= v[j];
        if (x == y) return true;
    }
    return false;
}

int main() { FAST
    cin >> N;
    if (isU(N)) cout << "YES\n";
    else cout << "NO\n";
}
