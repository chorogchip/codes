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

int a, b, c, d;

int main() { FAST
    fore (i, 3) {
        cin >> a >> b >> c >> d;
        switch(a+b+c+d) {
            case 3: cout << "A\n"; break;
            case 2: cout << "B\n"; break;
            case 1: cout << "C\n"; break;
            case 0: cout << "D\n"; break;
            case 4: cout << "E\n"; break;
        }
    }
}
