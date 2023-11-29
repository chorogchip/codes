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
string S;

int gg(int n) {
    int res = 0;
    do res += n % 10;
    while (n /= 10);
    return res;
}

int main() { FAST
    while (true) {
        cin >> S;
        N = 0;
        if (S[0] == '0') return 0;
        int aa = S.size();
        fore (i, aa) N += S[i] - '0';
        while (N / 10) N = gg(N);
        cout << N << endl;
    }
}
