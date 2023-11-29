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

int arr[31];

int main() { FAST
    fore (i, 28) {
        cin >> arr[0];
        arr[arr[0]] = 1;
    }
    for  (int i = 1; i <= 30; ++i)
        if (!arr[i]) cout << i << endl;
}
