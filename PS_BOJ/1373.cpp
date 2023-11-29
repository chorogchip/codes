#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

char A[1010101] = {'0','0','0', 0, }, B[333333] = {'0', 0, };
constexpr int a1 = '0'<<16;
constexpr int a2 = '0'<<8;
constexpr int a3 = '0'<<0;
constexpr int b1 = a1+0x10000;
constexpr int b2 = a2+0x100;
constexpr int b3 = a3+0x1;

constexpr inline char asd(int i) {
    switch (i) {
        case a3+a2+a1: return '0';
        case a3+a2+b1: return '1';
        case a3+b2+a1: return '2';
        case a3+b2+b1: return '3';
        case b3+a2+a1: return '4';
        case b3+a2+b1: return '5';
        case b3+b2+a1: return '6';
        case b3+b2+b1: return '7';
    }
    return 0;
}

int main() {
    fread(A+3, 1, sizeof(A)-3, stdin);
    int lo = 0, md, hi = sizeof(A)-1;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (A[md]) lo = md + 1;
        else hi = md;
    }
    lo -= 4, hi = lo/3;
    md = hi+1;
    for (; lo >= 0; lo -= 3, --hi)
        B[hi] = asd(*(int*)(A+lo)&0x00FFFFFF);
    lo = 0;
    while (B[lo]=='0') ++lo, --md;
    if (!md) { cout << '0'; return 0; }
    fwrite(B+lo, 1, md, stdout);
}
