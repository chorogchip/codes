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

string str;
int S;

int main() { FAST
    cin >> str;
    int ss = str.size();
    if (ss) S += 10;
    for (int i = 1; i != ss; ++i) {
        if (str[i] == str[i-1]) S += 5;
        else S += 10;
    }
    cout << S;
}
