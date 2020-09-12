#ifndef CARYON_MATH_H
#define CARYON_MATH_H
#include "caryon_datamaker.h"
#include "caryon_tools.h"
using namespace ca;
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
    ld length, perimeter;
    ll edge;
    ld oprc(bool flag) {
        if (flag) {
            perimeter = (ld)edge * length;
        }
        return (ld)edge * length;
    }
};
class kucan {  // By Billy2007
  public:
    ll p, q, dlt[N][N];
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
                    ll jk = 0;
                    fs(k, 1, q, 1) {
                        jk += dlt[i][k] * b.dlt[k][j];
                        jk %= moda;
                    }
                    c.dlt[i][j] = jk;
                    c.dlt[i][j] %= moda;
                }
            }
        }
        return c;
    }
    kucan operator*(const ll b) const {
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
    ld r, c, area;
    ld oprc(bool flag) {
        if (flag)
            c = 2 * r * cconst::PI;
        return 2 * r * cconst::PI;
    }
    ld opra(bool flag) {
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
inline ld cdistance(ld a1, ld a2, ld b1, ld b2) {
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
        ll kk = cgcd(son, mom);
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
    ld value() {
        return (ld)son / mom;
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
#endif