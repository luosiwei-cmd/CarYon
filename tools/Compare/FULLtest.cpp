#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define UKE -1
#define AC 1
#define WA 0
int compareFile(FILE* file_compared, FILE* file_checked) {
    bool   diff = 0;
    int    N    = 65536;
    char*  b1   = (char*)calloc(1, N + 1);
    char*  b2   = (char*)calloc(1, N + 1);
    size_t s1, s2;

    do {
        s1 = fread(b1, 1, N, file_compared);
        s2 = fread(b2, 1, N, file_checked);
        if ((s1 != s2) || memcmp(b1, b2, s1)) {
            diff = 1;
            break;
        }
    } while (!feof(file_compared) || !feof(file_checked));

    free(b1);
    free(b2);

    if (diff)
        return 0;
    else
        return 1;
}
int main(int argc, char* argv[]) {
    if (argc <= 2) {
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
