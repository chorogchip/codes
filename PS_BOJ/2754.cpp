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

char a, b;

int main() {
    scanf("%c%c", &a, &b);
    if (a =='F') { printf("0.0\n"); return 0; }
    printf("%.1f\n", 'D' - a + 1 + (b == '0' ? 0.0f : b == '+' ? 0.3f : -0.3f));
}
