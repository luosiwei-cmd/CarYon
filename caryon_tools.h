#ifndef CARYON_TOOLS_H
#define CARYON_TOOLS_H
#include "caryon_datamaker.h"
namespace cconst {
const long double PI = 3.141592653589793238462643383279502884197169399;
const long double E  = 2.7182818284590452353602874713527;
const std::string ALPHABET_SMALL   = "abcdefghijklmnopqrstuvwxyz";
const std::string ALPHABET_CAPITAL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ALPHABET =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string NUMBERS = "0123456789";
}  // namespace cconst
namespace cgraph {
template < typename T >
struct edge {
    int  v;
    T    w;
    bool operator<(const edge& rw) const  // priority_queue
    {
        return w > rw.w;
    }
};
template < typename T >
struct U {
    std::vector< edge< T > > u;
};
template < typename T >
struct graph {  // graph
    int                   n, m;
    std::vector< U< T > > g;
    graph() {
        ;
    }

    void update(int ntemp) {
        U< T > updatemp;
        updatemp.u.clear();
        while (g.size() <= ntemp)
            g.push_back(updatemp);
    }
    void addedge(int u, int v, T w) {
        n = cmath::cmax(n, u);
        n = cmath::cmax(n, v);
        update(cmath::cmax(u, v));
        m++;
        edge< T > tmp;
        tmp.v = v, tmp.w = w;
        g[u].u.push_back(tmp);
    }
    bool is_connect() {
        const int vstsize = n + 1;
        int       vstn    = 0;
        bool      vst[vstsize];
        memset(vst, false, sizeof(vst));
        std::queue< int > q;
        int               begin = crand::cyrand(1, n);
        vst[begin]              = true;
        vstn                    = 1;
        q.push(begin);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int i = 0; i < g[tmp].u.size(); i++) {
                if (!vst[g[tmp].u[i].v]) {
                    vst[g[tmp].u[i].v] = true;
                    vstn++;
                    q.push(g[tmp].u[i].v);
                }
            }
        }
        return ((vstn == n) ? true : false);
    }
    void output(graph< T > c) {
        std::cout << c;
    }
};
template < typename T >
std::ostream& operator<<(std::ostream& os, const graph< T >& c) {
    os << c.n << ' ' << c.m << '\n';
    for (int i = 1; i <= c.n; i++) {
        for (int j = 0; j < c.g[i].u.size(); j++)
            os << i << ' ' << c.g[i].u[j].v << ' ' << c.g[i].u[j].w << '\n';
    }
    return os;
}
template < typename T >
graph< T > operator+(graph< T > a, graph< T > b) {
    graph< T > ret;
    ret   = a;
    ret.m = a.m + b.m;
    ret.update(ret.n);
    for (int i = 1; i <= b.n; i++) {
        for (int j = 0; j < b.g[i].u.size(); j++) {
            ret.g[i].u.push_back(b.g[i].u[j]);
        }
    }
    return ret;
}

template < typename T >
graph< T > rand_graph(int n, int m, T mn, T mx, T (*randfunc)(T, T)) {
    graph< T > ret;
    ret.n = n;
    ret.m = m;

    ret.update(n);

    for (int i = 1; i <= m; i++) {
        edge< T > tmp;
        tmp.v = crand::cyrand(1, m);
        tmp.w = randfunc(mn, mx);
        ret.g[crand::cyrand(1, n)].u.push_back(tmp);
    }
    return ret;
}

struct caryon_node2 {
    int num, id1, id2;
};

bool crayon_cmp1(caryon_node2 a, caryon_node2 b) {
    return a.num < b.num;
}

template < typename T >
graph< T > rand_dag(int n, int m, T mn, T mx, T (*randfunc)(T, T)) {
    graph< T > ret;
    ret.update(n);
    ret.n = n;
    ret.m = m;
    for (int i = 1; i <= m; i++) {
        edge< T > tmp;
        int       utmp = crand::cyrand(1, crand::cyrand(1, n - 1));
        tmp.v          = crand::cyrand(utmp + 1, n);
        tmp.w          = randfunc(mn, mx);
        ret.g[utmp].u.push_back(tmp);
    }
    return ret;
}

struct caryon_node1 {
    int id;
    int soncnt;
};

template < typename T >
graph< T > rand_tree(int n, int k, T mn, T mx, T (*randfunc)(T, T)) {
    graph< T > ret;
    ret.n = n;
    ret.m = n - 1;
    ret.update(n);
    std::vector< caryon_node1 > t;
    std::vector< int >          hash;
    for (int i = 1; i <= n; i++) {
        hash.push_back(i);
    }
    random_shuffle(hash.begin(), hash.end());
    caryon_node1 updatemp;
    updatemp.id     = hash[0];
    updatemp.soncnt = 0;
    t.push_back(updatemp);
    for (int j = 2; j <= n; j++) {
        int i = hash[j - 1];
        std::swap(t[crand::cyrand(0, t.size() - 1)], t[t.size() - 1]);
        t[t.size() - 1].soncnt++;
        if (t[t.size() - 1].soncnt == k)
            t.pop_back();
        edge< T > tmp;
        tmp.v = t[t.size() - 1].id;
        tmp.w = randfunc(mn, mx);
        ret.g[i].u.push_back(tmp);
        updatemp.id     = i;
        updatemp.soncnt = 0;
        t.push_back(updatemp);
    }
    return ret;
}

template < typename T >
graph< T > connect_graph(int n, int m, T mn, T mx, T (*randfunc)(T, T)) {
    int        k = crand::cyrand(1, n);
    graph< T > ret;
    ret   = rand_tree(n, k, mn, mx, randfunc);
    ret.m = m;
    for (int i = n; i <= m; i++) {
        edge< T > tmp;
        tmp.v = crand::cyrand(1, n);
        tmp.w = randfunc(mn, mx);
        ret.g[crand::cyrand(1, n)].u.push_back(tmp);
    }
    return ret;
}
}  // namespace cgraph
#if __cplusplus >= 201103L
namespace caryon_cpp11 {
template < typename T >
T choice_plus(std::initializer_list< T > a) {
    std::vector< T > b;
    for (auto i : a) {
        b.push_back(i);
    }
    return b[crand::cyrand(1, b.size()) - 1];
}
}  // namespace caryon_cpp11
#endif
namespace ca {
using namespace cconst;
using namespace cgraph;
#if __cplusplus >= 201103L
using namespace caryon_cpp11;
#endif
}  // namespace ca
#endif