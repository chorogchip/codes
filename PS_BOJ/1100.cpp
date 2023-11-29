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

int a, b, cnt;

int main() { FAST
    for (int i = 0; i != 8; ++i) {
        for (int k = 0; k != 8; ++k) {
            b = getchar();
            if (++a & 1 && b == 'F') ++cnt; 
        }
        getchar();
        ++a;
    }
    cout << cnt << endl;
}
