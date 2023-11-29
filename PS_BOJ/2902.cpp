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

char c;
string S;

int main() { FAST
    while ((c = getchar()) != '\n')
        if (c >= 'A' && c <= 'Z') S += c;
    cout << S;
}
