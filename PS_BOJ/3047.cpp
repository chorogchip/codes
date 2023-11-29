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

int A[3];
char c[10];

int main() { FAST
    cin >> A[0] >> A[1] >> A[2] >> c;
    sort(A, A + 3);
    for (int i = 0; i != 3; ++i) switch(c[i]) {
        case 'A' : cout << A[0] << " "; break;
        case 'B' : cout << A[1] << " "; break;
        case 'C' : cout << A[2] << " "; break;
    }
}
