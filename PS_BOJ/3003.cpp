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

int arr[] = { 1, 1, 2, 2, 2, 8 }, X;

int main() { FAST
    fore (i, 6) {
        cin >> X;
        cout << arr[i] - X << " ";
    }
    cout << endl;
}
