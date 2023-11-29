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

int N, D[1010];

int asd(int n) {
    if (D[n]) return D[n];
    else if (n == 1) return D[n] = 1;
    else if (n == 2) return D[n] = 3;
    else return D[n] = ((asd(n-2) << 1) + asd(n-1)) % 10007; 
}

int main() { FAST
    cin >> N;
    cout << asd(N);
}
