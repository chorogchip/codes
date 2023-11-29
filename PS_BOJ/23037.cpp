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

char arr[10];

long long asd(long long n) {
    long long a = n * n;
    return a * a * n;
}

int main() { FAST
    cin >> arr;
    cout << asd(arr[0] - '0') + asd(arr[1] - '0') + asd(arr[2] - '0') + asd(arr[3] - '0') + asd(arr[4] - '0');
}
