#include<bits/stdc++.h>
using namespace std;

char base64_encode_char(unsigned char num) {
    if (num < 26) return 'A' + num;
    else if (num < 52) return 'a' + num - 26;
    else if (num < 62) return '0' + num - 52;
    else return num == 62 ? '+' : '/';
}

unsigned char base64_decode_char(char c) {
    if (c >= 'a') return c - 'a' + 26;
    else if (c >= 'A') return c - 'A';
    else if (c >= '0') return c - '0' + 52;
    return c == '+' ? 62 : 63;
}

string base64_encode(const unsigned char* buf, size_t size) {
    string out;
    out.reserve(((size + 2UL) / 3UL) * 4UL);
    size_t i = 0UL;
    for (; i+2UL < size; i += 3UL) {
        const unsigned num = buf[i]<<16U | buf[i+1UL]<<8U | buf[i+2UL];
        out += base64_encode_char(num>>18U & 63U);
        out += base64_encode_char(num>>12U & 63U);
        out += base64_encode_char(num>> 6U & 63U);
        out += base64_encode_char(num      & 63U);
    }
    unsigned num = 0U;

    if (i >= size) {
        goto RET;
    }
    
    num |= buf[i]<<16U;
    out += base64_encode_char(num>>18U & 63U);

    if (++i >= size) {
        out += base64_encode_char(num>>12U & 63U);
        out += '=';
        out += '=';
        goto RET;
    }

    num |= buf[i]<<8U;
    out += base64_encode_char(num>>12U & 63U);
    out += base64_encode_char(num>> 6U & 63U);
    out += '=';

    RET: return out;
}

vector<unsigned char> base64_decode(const string& str) {
    vector<unsigned char> out;
    size_t size = str.size();
    out.reserve((size / 4UL) * 3UL);
    while(str[size-1UL] == '=') --size;
    size_t i = 0;
    for (; i+3UL < size; i += 4UL) {
        const unsigned num =
            base64_decode_char(str[i    ])<<18U |
            base64_decode_char(str[i+1UL])<<12U |
            base64_decode_char(str[i+2UL])<< 6U |
            base64_decode_char(str[i+3UL]);
        out.push_back(num>>16U & 255U);
        out.push_back(num>> 8U & 255U);
        out.push_back(num      & 255U);
    }
    unsigned num = 0U;

    if (i >= size) {
        goto RET;
    }

    num |= base64_decode_char(str[i])<<18U;

    if (++i >= size) {
        out.push_back(num>>16U & 255U);
        goto RET;
    }

    num |= base64_decode_char(str[i])<<12U;
    out.push_back(num>>16U & 255U);

    if (++i >= size) {
        goto RET;
    }

    num |= base64_decode_char(str[i])<<6U;
    out.push_back(num>> 8U & 255U);

    RET: return out;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    auto res  = base64_decode(s);
    for (auto o : res) cout << (char)o;
}