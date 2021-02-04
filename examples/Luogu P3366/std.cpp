#include <bits/stdc++.h>

using namespace std;

namespace luosw {
namespace IO {
    template < typename T >
    inline T read() {
        T    ret = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') {
            if (ch == '-')
                f = -f;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
            ret = ret * 10 + ch - '0', ch = getchar();
        return ret * f;
    }
    template < typename T >
    void write(T x) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        T y = 10, len = 1;
        while (y <= x) {
            y *= 10;
            len++;
        }
        while (len--) {
            y /= 10;
            putchar(x / y + 48);
            x %= y;
        }
    }
    template < typename T >
    void write(T x, bool flag) {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        T y = 10, len = 1;
        while (y <= x) {
            y *= 10;
            len++;
        }
        while (len--) {
            y /= 10;
            putchar(x / y + 48);
            x %= y;
        }
        if (flag)
            putchar('\n');
    }
}  // namespace IO
namespace tools {
    template < typename T >
    T cmax(T a, T b) {
        return max(a, b);
    }
    template < typename T >
    T cmin(T a, T b) {
        return min(a, b);
    }
    template < typename T >
    T cgcd(T a, T b) {
        return __gcd(a, b);
    }
    template < typename T >
    T clcm(T a, T b) {
        return a * b / cgcd(a, b);
    }
}  // namespace tools
}  // namespace luosw
#define read(t) t = luosw::IO::read< int >()
#define write(t) luosw::IO::write< int >(t, true)
template < typename T >
class mcs {
  private:
    T   n;
    T   fa[10000];
    int size[10000];

  public:
    void init(T s) {
        for (T i = 0; i < s; i++) {
            fa[i]   = i;
            size[i] = 1;
        }
    }
    mcs() {
    }
    mcs(T size) {
        init(size);
    }
    T getRoot(T node) {
        if (fa[node] != node)
            fa[node] = getRoot(fa[node]);
        return fa[node];
    }
    bool check(T n1, T n2) {
        return getRoot(n1) == getRoot(n2);
    }
    void merge(T n1, T n2) {
        int r1 = getRoot(n1);
        int r2 = getRoot(n2);
        if (r1 == r2)
            return;
        if (size[r1] > size[r2])
            swap(r1, r2);
        fa[r1] = r2;
        size[r2] += size[r1];
    }
};

mcs< int > a;

class Edge {
  public:
    int         v, next, w;
    friend bool operator<(const Edge e1, const Edge e2) {
        return e1.w < e2.w;
    }
};

vector< Edge > g;

int    n, m, ans, cnt;
bool   flag;
signed main() {
    read(n), read(m);
    a.init(n);
    for (int i = 0; i < m; i++) {
        Edge temp;
        read(temp.v), read(temp.next), read(temp.w);
        g.push_back(temp);
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < m; i++) {
        Edge temp = g[i];
        if (!a.check(temp.v, temp.next)) {
            a.merge(temp.v, temp.next);
            ans += temp.w;
            if (++cnt == n - 1) {
                flag = true;
                break;
            }
        }
    }
    if (!flag) {
        puts("orz");
        return 0;
    }
    write(ans);
#ifdef debug
    system("pause");
#endif
    return 0;
}
