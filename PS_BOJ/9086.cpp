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

int T;
string S;

int main() { FAST
    cin >> T;
    while (T--) {
        cin >> S;
        cout << S[0] << S[S.size()-1] << endl;
    }
}
