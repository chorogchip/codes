#include<bits/stdc++.h>
using namespace std;

int d[10][10];

bool chk(int ii, int jj) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum |= 1<<d[ii+i][jj+j];
        }
    }
    return sum == 0b111'111'111'0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= 9; ++i) {
        int sum = 0;
        for (int j = 1; j <= 9; ++j) {
            sum |= 1<<d[i][j];
        }
        if (sum != 0b111'111'111'0) goto NO;
        sum = 0;
        for (int j = 1; j <= 9; ++j) {
            sum |= 1<<d[j][i];
        }
        if (sum != 0b111'111'111'0) goto NO;
    }
    for (int i = 1; i <= 9; i += 3)
        for (int j = 1; j <= 9; j += 3)
            if (!chk(i, j)) goto NO;
    YES: cout << "Yes"; exit(0);
    NO: cout << "No";
}