#include <bits/stdc++.h>
using namespace std;
#define UKE -1
#define AC 1
#define WA 0
int compareFile(FILE* file_compared, FILE* file_checked) {
    bool   diff = 0;
    int    N    = 65536;
    char   b1[65536], b2[65536];
    size_t s1, s2;
    while (1) {
        if (fgets(b1, N, file_compared) == NULL ||
            fgets(b2, N, file_checked) == NULL) {
            break;
        }
        s1 = strlen(b1);
        s2 = strlen(b2);
        if ((s1 != s2 && s1 + 2 != s2 && s1 - 2 != s2 && s1 + 1 != s2 &&
             s1 - 1 != s2) ||
            memcmp(b1, b2, min(s1, s2) - 1)) {
            diff = 1;
            break;
        }
    }
    if (diff)
        return 0;
    else
        return 1;
}
int main(int argc, char** argv) {
    if (argc < 2) {
        return UKE;
    }
    FILE* fuser = fopen(argv[1], "r");
    FILE* fstd  = fopen(argv[2], "r");
    if (compareFile(fuser, fstd) == 1) {
        return AC;
    }
    else {
        return WA;
    }
    return 0;
}
