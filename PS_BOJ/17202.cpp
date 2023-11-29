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

int C[16];

int main() {
    for (int i = 0; i < 16; i += 2) C[i] = getchar() - '0'; getchar();
    for (int i = 1; i < 16; i += 2) C[i] = getchar() - '0'; getchar();
    for (int i = 15; i > 1; --i) for (int j = 0; j != i; ++j)
        C[j] += C[j+1];
    cout << C[0]%10 << C[1]%10 << endl;
}
