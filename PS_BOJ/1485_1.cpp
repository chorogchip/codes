#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        pair<int,int> arr[4];
        for (int i = 0; i < 4; ++i) cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + 4);
        swap(arr[2], arr[3]);
        const int dx = arr[1].first - arr[0].first;
        const int dy = arr[2].first - arr[1].first;
        #define AS(x) if (!(x)) goto E;
        #define ASS(num, tar, val) AS(arr[((num)+1)%4].tar - arr[(num)].tar == (val))
        #define ASD(num, tar, val) AS(abs(arr[((num)+1)%4].tar - arr[(num)].tar) == abs(val))
        
        ASS(0, first, dx)
        ASS(1, first, dy)
        ASS(2, first, -dx)
        ASS(3, first, -dy)
        ASD(0, second, dy)
        ASD(1, second, dx)
        ASD(2, second, dy)
        ASD(3, second, dx)
        AS(arr[1].second-arr[0].second == arr[2].second-arr[3].second);
        AS(arr[2].second-arr[1].second == arr[3].second-arr[0].second);
        cout << 1 << '\n'; continue;
        E: cout << 0 << '\n';
    }
}