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

int A, B;

main() { FAST
    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0) return 0;
        cout << (A > B ? "Yes\n" : "No\n");
    }
}

