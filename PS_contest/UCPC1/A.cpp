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

int main() { FAST
    cin >> N;
    N >>= 2;
    for (int i = 0; i < N; ++i)
        cout << "long ";
    cout << "int";
}
