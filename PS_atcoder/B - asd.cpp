#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << arr[0];
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i] - arr[i-1]) <= 1) {
            cout << ' ' << arr[i];
        }  else if (arr[i] < arr[i-1]) {
            for (int j = arr[i-1] - 1; j >= arr[i]; --j)
                cout << ' ' << j;
        } else {
            for (int j = arr[i-1]+1; j <= arr[i]; ++j)
                cout << ' ' << j;
        }
        
    }
}