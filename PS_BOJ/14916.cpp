#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a = n / 10;
    int b = n % 10;
    int res = a * 2;

    switch(b) {
        case 0: break;
        case 2: res += 1; break;
        case 4: res += 2; break;
        case 6: res += 3; break;
        case 8: res += 4; break;
        case 5: res++; break;
        case 7: res += 2; break;
        case 9: res += 3; break;
        case 1: case 3:
            if (a) {
                res--;
                b += 5;
                res += b >> 1;
                break;
            } else {
                cout << -1;
                exit(0);
            }
    }

    cout << res;
    
    

}