#include<iostream>
#include<string.h>
using namespace std;
char flip(char c) {
    switch (c) {
        case '1': return '1';
        case '2': return '5';
        case '3': return '?';
        case '4': return '?';
        case '5': return '2';
        case '6': return '?';
        case '7': return '?';
        case '8': return '8';
        case '9': return '?';
    }
    return '?';
}

char M[21][21];
char T[21];

void swap(int a, int b, int n) {
    for (int i = 1; i <= n; ++i)
        swap(M[i][a], M[i][b]);
}

int main() {
    char w; int n; char x;
    cin >> w >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        M[i][j] = flip((cin >> x, x));
    if (w == 'L' || w == 'R') {
        for (int i = 1; i <= n/2; ++i) {
            swap(i, n+1-i, n);
        }
    } else {
        for (int i = 1; i <= n/2; ++i) {
            memcpy(T+1, M[i]+1, n);
            memcpy(M[i]+1, M[n-i+1]+1, n);
            memcpy(M[n-i+1]+1, T+1, n);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        cout << M[i][j] << ' ';
    }
    cout << '\n';
    }
}