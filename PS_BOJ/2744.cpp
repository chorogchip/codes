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

string s;

int main() { FAST
    cin >> s;
    int ss = s.length();
    for (int i = 0; i != ss; ++i) s[i] ^= ' ';
    cout << s << endl;
}
