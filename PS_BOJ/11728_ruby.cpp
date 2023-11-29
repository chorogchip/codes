#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

constexpr int SZ = 1 << 20;

int main() {
    struct stat st; fstat(0, &st);
	char w[SZ], *p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0), *q = w;
	auto ReadInt = [&]() {
		int ret = 0; char c = *p++, flag = 0;
        if (c == '-') c = *p++, flag = 1;
		for (; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return flag ? -ret : ret;
	};
    auto WriteInt = [&](int n) {
        if (q - w + 100 >= SZ) write(1, w, q - w), q = w;
        if (n < 0) *q++ = '-', n = -n;
        int sz = 1, t = n;
        for (; t >= 10; t /= 10) sz++;
        for (int i = sz; i --> 0; n /= 10) q[i] = n % 10 | 48;
        q += sz, *q++ = ' ';
    };

    int n = ReadInt(), m = ReadInt(), v[n];
    for (int i = 0; i < n; i++) v[i] = ReadInt();
    for (int i = 0, j = 0; ; j++) {
        if (j == m) { while (i < n) WriteInt(v[i++]); break; }
        const int val = ReadInt();
        while (i < n && v[i] <= val) WriteInt(v[i++]);
        WriteInt(val);
    }
    write(1, w, q - w);
}