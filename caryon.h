#ifndef CARYON_H
#define CARYON_H
#ifndef _GLIBCXX_NO_ASSERT
#    include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#    include <ccomplex>
#    include <cfenv>
#    include <cinttypes>
#    include <cstdalign>
#    include <cstdbool>
#    include <cstdint>
#    include <ctgmath>
#    include <cwchar>
#    include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#    include <array>
#    include <atomic>
#    include <chrono>
#    include <condition_variable>
#    include <forward_list>
#    include <future>
#    include <initializer_list>
#    include <mutex>
#    include <random>
#    include <ratio>
#    include <regex>
#    include <scoped_allocator>
#    include <system_error>
#    include <thread>
#    include <tuple>
#    include <type_traits>
#    include <typeindex>
#    include <unordered_map>
#    include <unordered_set>
#endif
#define makein(m, n) for (__ci = m; __ci <= n; __ci++)
#define fs(i, x, y, z) for (long long i = x; i <= y; i += z)
#define ft(i, x, y, z) for (long long i = x; i >= y; i += z)
#ifndef CarYon
#    define CarYon 3.7
#endif
std::string dataname;
int         cprime[1000000];
int         __ci;
int         __cnt;
const int   __N = 151, __moda = 1000000007;
int         maxtime = 1000;
long double runtime;
bool        ___flag = false;
void        csh() {
    __cnt = 0;
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
bool      isInit;
int       MTindex;
long long MT[624];
void      csrand(int seed) {
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
#if __cplusplus <= 201103L
        csrand((int)time(NULL));
#else
        csrand((int)time(nullptr));
#endif
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
inline long long cyrand_ll() {
    return ((long long)(cyrand()) << 31) + cyrand();
}
inline int cyrand(int a, int b) {
    if (a > b)
        a = b;
    if (a == b)
        return a;
    else
        return cyrand() % (b - a + 1) + a;
}
inline long long cyrand_ll(long long a, long long b) {
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
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        cci << __ci;
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
    ++__cnt;
}
inline void instring(std::string a) {
    std::string ccci, tnmp;
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        std::stringstream cci;
        cci << __ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    std::cin >> tnmp;
    a = tnmp + a;
    std::cout << a;
    ++__cnt;
}
template <>
inline void in< std::string >(std::string a) {
    std::string ccci, tnmp;
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        std::stringstream cci;
        cci << __ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    std::cin >> tnmp;
    a = tnmp + a;
    std::cout << a;
    ++__cnt;
}
template < typename T >
inline void in(T a) {
    std::string       c, ccci, tnmp;
    std::stringstream ss, cci;
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        cci << __ci;
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
    ++__cnt;
}
inline void inspace() {
    std::string ccci, tnmp;
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        std::stringstream cci;
        cci << __ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    std::cin >> tnmp;
    std::string a = tnmp + " ";
    std::cout << a;
    ++__cnt;
}
inline void inendl() {
    std::string ccci, tnmp;
    if (__cnt == 0) {
        if (!___flag) {
            std::string a666 = "mkdir data-" + dataname;
            system(a666.c_str());
            ___flag = true;
        }
        std::stringstream cci;
        cci << __ci;
        cci >> ccci;
        std::string name = "data-" + dataname + "./" + dataname + ccci + ".in";
        freopen(name.c_str(), "w", stdout);
        freopen(name.c_str(), "r", stdin);
    }
    std::cin >> tnmp;
    std::string a = tnmp + "\n";
    std::cout << a;
    ++__cnt;
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
namespace cydebug {
std::stringstream __re;
void              makeDebugFile(int a, int b) {
    std::string ___a = "mkdir debug-" + dataname;
    system(___a.c_str());
    for (int i = a; i <= b; ++i) {
        inout::closefile();
        std::stringstream debug1;
        std::string       Debug1;
        debug1 << i;
        debug1 >> Debug1;
        std::string debugname1 =
            "debug-" + dataname + "./" + dataname + Debug1 + ".ans";
        std::string debugname2 =
            "data-" + dataname + "./" + dataname + Debug1 + ".in";
        freopen(debugname1.c_str(), "w", stdout);
        freopen(debugname2.c_str(), "r", stdin);
        long double clock1 = clock();
        __re << system("myprogram.exe");
        runtime = (int)(clock() - clock1);
        sp << runtime << std::endl;
    }
}
void compareFile(int a, int b) {
    int ____cnt = 0;
    freopen("Debug.log", "w", stdout);
    for (int i = a; i <= b; i++) {
        inout::closefile();
        std::cout << "Comparing " << i << ".out and " << i << ".ans...\n";
        freopen("Debug.log", "a", stdout);
        std::cout << "Comparing " << i << ".out and " << i << ".ans...\n";
        std::stringstream debug1;
        std::string       Debug1;
        debug1 << i;
        debug1 >> Debug1;
        std::string command = "tools\\Compare\\NOIPStyle.exe debug-" +
                              dataname + "\\" + dataname + Debug1 +
                              ".ans data-" + dataname + "\\" + dataname +
                              Debug1 + ".out";
        int flag = system(command.c_str());
        sp >> runtime;
        int __tmp;
        __re >> __tmp;
        freopen("Debug.log", "a", stdout);
        if (__tmp != 0) {
            std::cout << "TestCase " << i << ", result: RE.\n";
        }
        else if (runtime > maxtime) {
            std::cout << "TestCase " << i
                      << ", result: TLE. The program\'s runtime is " << runtime
                      << " ms.\n";
        }
        else if (flag == 1) {
            std::cout << "TestCase " << i << ", result: AC.\n";
            ____cnt++;
        }
        else if (flag == 0) {
            std::cout << "TestCase " << i << ", result: WA.\n";
        }
        else if (flag == -1) {
            std::cout << "TestCase " << i << ", result: Judgement failed.\n";
        }
        else {
            std::cout << "TestCase " << i << ", result: UKE.\n";
        }
    }
    inout::closefile();
    std::cout << "Compare is compeleted.\n";
    std::cout << "The score is " << (long double)____cnt * 1.0 / (b - a) * 100
              << "." << std::endl;
}
void debug(int a, int b) {
    makeDebugFile(a, b);
    inout::closefile();
    std::cout << "Debug files were maked successfully.\n";
    compareFile(a, b);
    inout::closefile();
    std::cout << "Debug successfully.\n";
}
}  // namespace cydebug
namespace ca {
using namespace cydebug;
}
using namespace ca;
namespace cconst {
const long double PI = 3.141592653589793238462643383279502884197169399;
const long double E  = 2.7182818284590452353602874713527;
const std::string ALPHABET_SMALL   = "abcdefghijklmnopqrstuvwxyz";
const std::string ALPHABET_CAPITAL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ALPHABET =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string NUMBERS = "0123456789";
const int         INF     = 0x7f7f7f;
}  // namespace cconst
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
#if __cplusplus >= 201103L
using namespace caryon_cpp11;
#endif
}  // namespace ca
namespace cmath {
class quadtri {
  public:
    int  a, b, c;
    char s;
    int  Delta;
    quadtri() {
        a     = 1;
        b     = 0;
        c     = 0;
        s     = 'x';
        Delta = 0;
    }
    void make(char abc) {
        s = abc;
        a = crand::cyrand(-100, 100);
        while (a == 0) {
            a = crand::cyrand(-100, 100);
        }
        b = crand::cyrand(-100, 100);
        c = crand::cyrand(-100, 100);
    }
    void makeDelta() {
        Delta = b * b - 4 * a * c;
    }
    void makecanfac(char abc) {
        do {
            s = abc;
            a = crand::cyrand(-100, 100);
            while (a == 0) {
                a = crand::cyrand(-100, 100);
            }
            b     = crand::cyrand(-100, 100);
            c     = crand::cyrand(-100, 100);
            Delta = b * b - 4 * a * c;
        } while (!(Delta == (int)sqrt(Delta) * (int)sqrt(Delta)));
    }
    quadtri operator+(const quadtri cc) const {
        quadtri tmp;
        tmp.a = a + cc.a;
        tmp.b = b + cc.b;
        tmp.c = c + cc.c;
        return tmp;
    }
    quadtri operator-(const quadtri aaa) const {
        quadtri tmp;
        tmp.a = a - aaa.a;
        tmp.b = b - aaa.b;
        tmp.c = c - aaa.c;
        return tmp;
    }
    quadtri operator+(const int aaa) const {
        quadtri tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = tmp.c + aaa;
        return tmp;
    }
    quadtri operator-(const int aaa) const {
        return *this + (-a);
    }
};
class stpolyon {
  public:
    long double length, perimeter;
    long long   edge;
    long double oprc(bool flag) {
        if (flag) {
            perimeter = (long double)edge * length;
        }
        return (long double)edge * length;
    }
};
class kucan {  // By Billy2007
  public:
    long long p, q, dlt[__N][__N];
    kucan() {
        p = 1, q = 1;
        ms(dlt, 0);
    }
    kucan operator+(const kucan b) const {
        kucan c;
        if (b.p == p && b.q == q) {
            fs(i, 1, p, 1) {
                fs(j, 1, q, 1) {
                    c.dlt[i][j] = dlt[i][j] + b.dlt[i][j];
                }
            }
            c.p = p;
            c.q = q;
        }
        else {
            fs(i, 1, p, 1) {
                fs(j, 1, q, 1) {
                    c.dlt[i][j] = dlt[i][j];  //+b.dlt[i][j];
                }
            }
            fs(i, 1, b.p, 1) {
                fs(j, 1, b.q, 1) {
                    c.dlt[i + p][j + q] = b.dlt[i][j];
                }
            }
            c.p = p + b.p;
            c.q = q + b.q;
        }
        return c;
    }
    kucan operator-(const kucan b) const {
        kucan c;
        if (b.p == p && b.q == q) {
            fs(i, 1, p, 1) {
                fs(j, 1, q, 1) {
                    c.dlt[i][j] = dlt[i][j] - b.dlt[i][j];
                }
            }
            c.p = p;
            c.q = q;
        }
        return c;
    }
    kucan operator*(const kucan b) const {
        kucan c;
        if (b.p == q) {
            c.p = p;
            c.q = b.q;
            fs(i, 1, c.p, 1) {
                fs(j, 1, c.q, 1) {
                    long long jk = 0;
                    fs(k, 1, q, 1) {
                        jk += dlt[i][k] * b.dlt[k][j];
                        jk %= __moda;
                    }
                    c.dlt[i][j] = jk;
                    c.dlt[i][j] %= __moda;
                }
            }
        }
        return c;
    }
    kucan operator*(const long long b) const {
        kucan c;
        fs(i, 1, p, 1) {
            fs(j, 1, q, 1) {
                c.dlt[i][j] = dlt[i][j] * b;
            }
        }
        c.p = p;
        c.q = q;
        return c;
    }
    void out() {
        fs(i, 1, p, 1) {
            fs(j, 1, q, 1) {
                std::cout << dlt[i][j];
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
};
class circle {
  public:
    long double r, c, area;
    long double oprc(bool flag) {
        if (flag)
            c = 2 * r * cconst::PI;
        return 2 * r * cconst::PI;
    }
    long double opra(bool flag) {
        if (flag)
            area = cconst::PI * r * r;
        return cconst::PI * r * r;
    }
    circle operator+(const circle x) const {
        circle tmp;
        tmp.r    = r + x.r;
        tmp.c    = 2 * r * cconst::PI;
        tmp.area = cconst::PI * r * r;
        return tmp;
    }
    circle operator-(const circle x) const {
        circle tmp;
        tmp.r    = r - x.r;
        tmp.c    = 2 * r * cconst::PI;
        tmp.area = cconst::PI * r * r;
        return tmp;
    }
    bool operator>(const circle b) const {
        circle c = *this - b;
        if (c.r > 0)
            return true;
        else
            return false;
    }
    bool operator>=(const circle b) const {
        return !(b > *this);
    }
    bool operator<(const circle b) const {
        return b > *this;
    }
    bool operator<=(const circle b) const {
        return !(*this > b);
    }
    bool operator==(const circle b) const {
        return !(*this > b) && !(b > *this);
    }
    bool operator!=(const circle b) const {
        return !(*this == b);
    }
};
inline long double
cdistance(long double a1, long double a2, long double b1, long double b2) {
    return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
}
template < typename T >
inline T cabs(T a) {
    return a > 0 ? a : -a;
}
inline int cmin(int a, int b) {
    return a < b ? a : b;
}
inline int cmax(int a, int b) {
    return a > b ? a : b;
}
template < typename T >
T cgcd(T a, T b) {
    return a == 0 ? b : cgcd(b % a, a);
}
inline bool isprime(int a) {
    if (a < 2)
        return false;
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0)
            return false;
    }
    return true;
}
inline int cmakeprime(int a, int b) {
    int prcnt = 0;
    for (int i = a; i <= b; i++) {
        if (isprime(i)) {
            cprime[prcnt++] = i;
        }
    }
}
inline int crprimenum(int beg, int end) {
    return cprime[crand::cyrand(beg, end)];
}
class rectangle {
  public:
    int a, b, peri, area;
    rectangle() {
        a    = 0;
        b    = 0;
        peri = 0;
        area = 0;
    }
    void makePeri() {
        peri = (a + b) * 2;
    }
    void makeArea() {
        area = a * b;
    }
};
class triangle {
  public:
    int a, b, c, h1, h2, h3, peri, area;
    triangle() {
        a = b = c = h1 = h2 = h3 = peri = area = 0;
    }
    void makePeri() {
        peri = a + b + c;
    }
    void makeArea() {
        int p = (a + b + c) / 2;
        area  = sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
class frac {  // By GoneTime&luosw
  private:
    void huaj() {
        long long kk = cgcd(son, mom);
        son /= kk;
        mom /= kk;
    }
    bool fu() {
        huaj();
        if (son < 0 && mom < 0) {
            son = -son;
            mom = -mom;
            return 0;
        }
        else if (son > 0 && mom > 0) {
            return 0;
        }
        else
            return 1;
    }

  public:
    int son, mom;
    frac() {
        son = 0;
        mom = 1;
    }
    long double value() {
        return (long double)son * 1.0 / mom;
    }
    std::string take(bool flag) {
        int c = cgcd(son, mom);
        son /= c;
        mom /= c;
        std::stringstream tmp1, tmp2;
        std::string       aaa, bbb;
        tmp1 << son;
        tmp1 >> aaa;
        tmp2 << mom;
        tmp2 >> bbb;
        return (flag) ? aaa + '/' + bbb : aaa + ' ' + bbb;
    }
    std::string fracr(bool flag) {
        std::stringstream tmp1, tmp2;
        std::string       aaa, bbb;
        tmp1 << son;
        tmp1 >> aaa;
        tmp2 << mom;
        tmp2 >> bbb;
        return (flag) ? aaa + '/' + bbb : aaa + ' ' + bbb;
    }
    frac operator*(const frac b) const {
        frac c;
        c.son = son * b.son;
        c.mom = mom * b.mom;
        c.huaj();
        return c;
    }
    frac operator/(const frac b) const {
        frac c;
        c.son = son * b.mom;
        c.mom = mom * b.son;
        c.huaj();
        return c;
    }
    frac operator+(const frac b) const {
        frac c;
        c.mom = lcm(mom, b.mom);
        c.son = son * (c.mom / mom) + b.son * (c.mom / b.mom);
        c.huaj();
        return c;
    }
    frac operator-(const frac b) const {
        frac c;
        c.mom = lcm(mom, b.mom);
        c.son = son * (c.mom / mom) - b.son * (c.mom / b.mom);
        c.huaj();
        return c;
    }
    frac operator+(const int a) const {
        frac tmp;
        frac abc;
        abc.son = a;
        abc.mom = 1;
        tmp     = *this + abc;
        return tmp;
    }
    frac operator-(const int a) const {
        return *this + (-a);
    }
    frac operator*(const int a) const {
        frac tmp, abc;
        abc.son = a;
        abc.mom = 1;
        tmp     = tmp * abc;
        return tmp;
    }
    frac operator/(const int a) const {
        frac tmp, abc;
        abc.son = a;
        abc.mom = 1;
        tmp     = tmp / abc;
        return tmp;
    }
    bool operator>(const frac b) const {
        frac c = *this - b;
        if (c.fu())
            return 0;
        else
            return 1;
    }
    bool operator<(const frac b) const {
        return b > *this;
    }
    bool operator<=(const frac b) const {
        return !(*this > b);
    }
    bool operator>=(const frac b) const {
        return !(b > *this);
    }
    bool operator!=(const frac b) const {
        return (b > *this) || (*this > b);
    }
    bool operator==(const frac b) const {
        return !(*this > b) && !(b > *this);
    }
};
}  // namespace cmath
namespace cgeo {
class point {
  public:
    double x, y;
    point() {
        x = 0;
        y = 0;
    }
    double pointDis(point a, point b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
};
class line {
  public:
    double k, b;
    line() {
        k = 0;
        b = 0;
    }
    line makeLine(point a, point b) {
        line tmp;
        tmp.k = (a.y - b.y) / (a.x - b.x);
        tmp.b = a.y - ((a.y - b.y) / (a.x - b.x) * a.x);
        return tmp;
    }
};
class hypotenuse {
  public:
    double k;
    hypotenuse() {
        k = 1;
    }
    hypotenuse makeHypotenuse(point a) {
        hypotenuse tmp;
        tmp.k = a.x * a.y;
    }
};
class parabola {
  public:
    double a, b, c;
    parabola() {
        a = 1;
        b = 0;
        c = 0;
    }
};
}  // namespace cgeo
namespace ca {
using namespace cgeo;
using namespace cmath;
}  // namespace ca
namespace ca {
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
using namespace cgraph;
}  // namespace ca
#endif