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

int A, B, C;

int main() {
    scanf("%d%d%d", &A, &B, &C);
         if (A + B == C) printf("%d+%d=%d\n", A, B, C);
    else if (A - B == C) printf("%d-%d=%d\n", A, B, C);
    else if (A * B == C) printf("%d*%d=%d\n", A, B, C);
    else if (A == B + C) printf("%d=%d+%d\n", A, B, C);
    else if (A == B - C) printf("%d=%d-%d\n", A, B, C);
    else if (A == B * C) printf("%d=%d*%d\n", A, B, C);
    else if (A / B == C) printf("%d/%d=%d\n", A, B, C);
    else if (A == B / C) printf("%d=%d/%d\n", A, B, C);
}
