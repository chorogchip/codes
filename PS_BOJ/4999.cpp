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

string s1, s2;

main() { FAST
    cin >> s1 >> s2;
    if (s1.size() >= s2.size()) cout << "go\n";
    else cout << "no\n";
}

