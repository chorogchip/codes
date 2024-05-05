#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct CNT {
private:
    ll cnt[10];
public:
    CNT() = default;
    static CNT set1(ll n){ CNT ret{}; ret.cnt[n]=1; return ret; }
    static CNT setall(ll cnt){ CNT ret{}; for (int i = 0; i < 10; ++i) ret.cnt[i]=cnt; return ret; }
    void operator+=(const CNT& c){for (int i = 0; i < 10; ++i) cnt[i] += c.cnt[i];}
    void operator-=(const CNT& c){for (int i = 0; i < 10; ++i) cnt[i] -= c.cnt[i];}
    CNT operator+(const CNT& c){CNT ret{};for (int i = 0; i < 10; ++i) ret.cnt[i] = cnt[i] + c.cnt[i]; return ret;}
    void operator*=(ll m){for (int i = 0; i < 10; ++i) cnt[i] *= m;}
    CNT operator*(ll m){CNT ret{};for (int i = 0; i < 10; ++i) ret.cnt[i] = cnt[i] * m; return ret;}
    ostream& print(ostream& ostr) const {
        for (int i = 0; i < 10; ++i) ostr << cnt[i] << ' ';
        return ostr;
    }
};
ostream& operator<<(ostream& ostr, const CNT& c) { return c.print(ostr); }

struct NUM {
private:
    vector<ll> v;
public:
    NUM() = default;
    NUM(ll n){do v.push_back(n%10); while (n/=10);}
    ll get_digit() const { return v.size(); }
    ll get_LSD() const { return v.front(); }
    ll get_MSD() const { return v.back(); }
    ll get_num() const {
        ll ret = 0;
        for (int i = v.size()-1; i >= 0; --i) ret = ret * 10 + v[i];
        return ret;
    }
    NUM& pop_back() { v.pop_back(); return *this; }
};

ll pow10(ll n) {
    ll ret = 1;
    for (ll i = 0; i < n; ++i) ret *= 10;
    return ret;
}
CNT calc_max(ll digit) { return CNT::setall(digit * pow10(digit-1)); }

CNT calc_with0(NUM mx) {
    const ll digit = mx.get_digit();
    const ll top = mx.get_MSD();
    if (digit == 1) {
        CNT ret{};
        for (ll i = 0; i <= top; ++i) ret += CNT::set1(i);
        return ret;
    }
    CNT ret{};
    for (ll i = 0; i < top; ++i) {
        ret += calc_max(digit-1);
        ret += CNT::set1(i) * pow10(digit-1);
    }
    ret += CNT::set1(top) * (mx.get_num() % pow10(digit-1) + 1);
    ret += calc_with0(mx.pop_back());
    return ret;
}

CNT calc(NUM mx) {
    const ll digit = mx.get_digit();
    const ll top = mx.get_MSD();
    if (digit == 1) {
        CNT ret{};
        for (ll i = 0; i <= top; ++i) ret += CNT::set1(i);
        return ret;
    }
    CNT ret = calc(NUM(pow10(digit-1)-1));
    for (ll i = 1; i < top; ++i) {
        ret += calc_max(digit-1);
        ret += CNT::set1(i) * pow10(digit-1);
    }
    ret += CNT::set1(top) * (mx.get_num() % pow10(digit-1) + 1);
    ret += calc_with0(mx.pop_back());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    const auto nn = NUM(n);
    auto ret = calc(nn);
    ret -= CNT::set1(0);
    cout << ret;
}