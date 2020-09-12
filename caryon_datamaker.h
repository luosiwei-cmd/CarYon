#ifndef CRAYON_DATAMAKER__H
#    define CRAYON_DATAMAKER_H
#    ifndef _GLIBCXX_NO_ASSERT
#        include <cassert>
#    endif
#    include <cctype>
#    include <cerrno>
#    include <cfloat>
#    include <ciso646>
#    include <climits>
#    include <clocale>
#    include <cmath>
#    include <csetjmp>
#    include <csignal>
#    include <cstdarg>
#    include <cstddef>
#    include <cstdio>
#    include <cstdlib>
#    include <cstring>
#    include <ctime>

#    if __cplusplus >= 201103L
#        include <ccomplex>
#        include <cfenv>
#        include <cinttypes>
#        include <cstdalign>
#        include <cstdbool>
#        include <cstdint>
#        include <ctgmath>
#        include <cwchar>
#        include <cwctype>
#    endif

// C++
#    include <algorithm>
#    include <bitset>
#    include <complex>
#    include <deque>
#    include <exception>
#    include <fstream>
#    include <functional>
#    include <iomanip>
#    include <ios>
#    include <iosfwd>
#    include <iostream>
#    include <istream>
#    include <iterator>
#    include <limits>
#    include <list>
#    include <locale>
#    include <map>
#    include <memory>
#    include <new>
#    include <numeric>
#    include <ostream>
#    include <queue>
#    include <set>
#    include <sstream>
#    include <stack>
#    include <stdexcept>
#    include <streambuf>
#    include <string>
#    include <typeinfo>
#    include <utility>
#    include <valarray>
#    include <vector>

#    if __cplusplus >= 201103L
#        include <array>
#        include <atomic>
#        include <chrono>
#        include <condition_variable>
#        include <forward_list>
#        include <future>
#        include <initializer_list>
#        include <mutex>
#        include <random>
#        include <ratio>
#        include <regex>
#        include <scoped_allocator>
#        include <system_error>
#        include <thread>
#        include <tuple>
#        include <type_traits>
#        include <typeindex>
#        include <unordered_map>
#        include <unordered_set>
#    endif
#    define db double
#    define ll long long
#    define ld long db
#    define makein(m, n) for (ci = m; ci <= n; ci++)
#    define bh ++cnt
#    define ns "-1"
#    define fs(i, x, y, z) for (ll i = x; i <= y; i += z)
#    define ft(i, x, y, z) for (ll i = x; i >= y; i += z)
#    define ull unsigned long long
#    ifndef CarYon
#        define CarYon 3.4
#    endif
std::string dataname;
int         cprime[1000000];
int         ci;
int         cnt;
const int   N = 151, inf = 0x7f7f7f7f, moda = 1000000007;
int         maxtime = 1000;
long double runtime;
bool        ___flag = false;
void        csh() {
    cnt = 0;
}
int cgcd(int a, int b) {
    int t = 1;
    while (t != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
template < typename T1, typename T2 >
void ms(T1* a, T2 b) {
    memset(a, b, sizeof(a));
}
template < typename T >
int sz(T* a) {
    return sizeof(a);
}
int lcm(int x, int y) {
    return x / cgcd(x, y) * y;
}
std::stringstream sp;
namespace crand {
bool isInit;
int  MTindex;
ll   MT[624];
void csrand(int seed) {
    MTindex = 0;
    isInit  = 1;
    MT[0]   = seed;
    for (int i = 1; i < 624; i++) {
        int t = 1812433253 * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
        MT[i] = t & 0xffffffff;
    }
}
inline void generate() {
    for (int i = 0; i < 624; i++) {
        long long y = (MT[i] & 0x80000000) + (MT[(i + 1) % 624] & 0x7fffffff);
        MT[i]       = MT[(i + 397) % 624] ^ (y >> 1);
        if (y % 2 == 1)
            MT[i] ^= 2147483647;
    }
}
inline int cyrand() {
    if (!isInit)
#    if __cplusplus <= 201103L
        csrand((int)time(NULL));
#    else
        csrand((int)time(nullptr));
#    endif
    if (MTindex == 0)
        generate();
    int y   = MT[MTindex];
    y       = y ^ (y >> 11);
    y       = y ^ ((y << 7) & 1636928640);
    y       = y ^ ((y << 15) & 1022730752);
    y       = y ^ (y >> 18);
    MTindex = (MTindex + 1) % 624;
    return y;
}
inline ll cyrand_ll() {
    return ((ll)(cyrand()) << 31) + cyrand();
}
inline int cyrand(int a, int b) {
    if (a > b)
        a = b;
    if (a == b)
        return a;
    else
        return cyrand() % (b - a + 1) + a;
}
inline ll cyrand_ll(ll a, ll b) {
    if (a > b)
        a = b;
    if (a == b)
        return a;
    else
        return cyrand_ll() % (b - a + 1) + a;
}
inline bool cyrand_bool() {
    if (cyrand(0, 1) == 0)
        return false;
    else
        return true;
}
inline char cyrand_letter() {
    return cyrand(32, 126);
}
inline char cyrand_engs() {
    return 'a' + cyrand(0, 26);
}
inline char cyrand_engb() {
    return 'A' + cyrand(0, 26);
}
inline char cyrand_fomatc() {
    switch (cyrand(0, 4)) {
        case 0: {
            return '\n';
            break;
        }
        case 1: {
            return '\t';
            break;
        }
        case 2: {
            return '\r';
            break;
        }
        case 3: {
            return '\v';
            break;
        }
        case 4: {
            return '\f';
            break;
        }
    }
}
inline std::string cyrand_word(int a) {
    std::string chen_zhe;
    for (int kkksc03 = 0; kkksc03 < a; kkksc03++) {
        if (cyrand_bool()) {
            chen_zhe[kkksc03] = cyrand_engs();
        }
        else {
            chen_zhe[kkksc03] = cyrand_engb();
        }
    }
    return chen_zhe;
}
inline std::string cyrand_article(int a) {
    std::string soha;
    soha = cyrand_word(cyrand(1, 10));
    for (int lzn = 1; lzn < a; lzn++) {
        soha = soha + " " + cyrand_word(cyrand(1, 10));
    }
    return soha;
}
template < typename T >
inline T choice(T* a, int lbound, int ubound) {
    return a[cyrand(lbound, ubound)];
}
inline double doubleRandom() {
    srand(time(0));
    return (double)(rand() / (double)RAND_MAX);
}
inline bool __checktmp(int* arr, int tmp, int flag, int end) {
    if (flag == 0) {
        return true;
    }
    for (int i = 0; i < end; i++) {
        if (flag == -1) {
            if (arr[i] == tmp) {
                return false;
            }
        }
        else if (flag == 1) {
            if (arr[i] > tmp) {
                return false;
            }
        }
        else if (flag == 2) {
            if (arr[i] < tmp) {
                return false;
            }
        }
        else if (flag == 3) {
            if (arr[i] >= tmp) {
                return false;
            }
        }
        else if (flag == 4) {
            if (arr[i] <= tmp) {
                return false;
            }
        }
    }
    return true;
}
inline void randomArr(int* arr, int n, int lower, int upper, int flag) {
    for (int i = 0; i < n;) {
        int tmp = cyrand(lower, upper);
        if (__checktmp(arr, tmp, flag, i - 1)) {
            arr[i++] = tmp;
        }
    }
}
}  // namespace crand
namespace inout {
inline void inint(int a) {
    std::string       c, ccci, tnmp;
    std::stringstream ss, cci;
    if (cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        cci << ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    ss << a;
    ss >> c;
    std::cin >> tnmp;
    c = tnmp + c;
    std::cout << c;
    bh;
}
inline void instring(std::string a) {
    std::string ccci, tnmp;
    if (cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        std::stringstream cci;
        cci << ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    std::cin >> tnmp;
    a = tnmp + a;
    std::cout << a;
    bh;
}
template < typename T >
inline void in(T a) {
    std::string       c, ccci, tnmp;
    std::stringstream ss, cci;
    if (cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        cci << ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    ss << a;
    ss >> c;
    std::cin >> tnmp;
    c = tnmp + c;
    std::cout << c;
    bh;
}
inline void out(int a) {
    freopen("CON.exe", "w", stdout);
    freopen("CON.exe", "r", stdin);
    std::stringstream aa;
    std::string       aaa;
    aa << a;
    aa >> aaa;
    std::string abc;
    std::string name = "data-" + dataname + "./" + dataname + aaa + ".in";
    freopen(name.c_str(), "r", stdin);
    std::string outname = "data-" + dataname + "./" + dataname + aaa + ".out";
    freopen(outname.c_str(), "w", stdout);
    system("std.exe");
}
inline void makeout(int b, int a) {
    for (int i = b; i <= a; ++i) {
        out(i);
        freopen("CON.exe", "r", stdin);
        freopen("CON.exe", "w", stdout);
        std::stringstream _a;
        std::string       _i;
        _a << i;
        _a >> _i;
        std::string fff = "Generating:" + dataname + _i + ".out...\n";
        printf(fff.c_str());
    }
    printf(
        "out files are already generated, you can find them in the new folder "
        "in this directory.\n");
}
inline void closefile() {
    freopen("CON.exe", "w", stdout);
    freopen("CON.exe", "r", stdin);
}
}  // namespace inout
namespace ca {
using namespace crand;
using namespace inout;
}  // namespace ca
#endif