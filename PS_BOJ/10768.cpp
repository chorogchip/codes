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

int A, B;

int main() { FAST
    cin >> A >> B;
    if (A < 2) goto BEF;
    else if (A > 2) goto AFT;
    else if (B < 18) goto BEF;
    else if (B > 18) goto AFT;
    else cout << "Special\n";
    return 0;
    AFT: cout << "After\n"; return 0;
    BEF: cout << "Before\n"; return 0;
}
