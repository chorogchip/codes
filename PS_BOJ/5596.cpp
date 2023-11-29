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

int X, AA, BB;

int main() { FAST
    fore(i, 4) cin >> X, AA += X;
    fore(i, 4) cin >> X, BB += X;
    cout << max(AA, BB) << endl;
    
}
