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
int ss;

int main() { FAST
    cin >> s1;
    ss = s1.length();
    for (int i = ss-1; i >= 0; --i) s2 += s1[i];
    cout << s2 << endl;
}
