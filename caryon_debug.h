#ifndef CARYON_DEBUG_H
#define CARYON_DEBUG_H
#include "caryon_datamaker.h"
using namespace ca;
namespace cydebug {
void makeDebugFile(int a, int b) {
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
        system("myprogram.exe");
        runtime = (int)(clock() - clock1);
        sp << runtime << std::endl;
    }
}
void compareFile(int a, int b) {
    freopen("Debug.log", "w", stdout);
    for (int i = a; i <= b; i++) {
        std::cout << "Comparing " << i << ".out and " << i << ".ans...\n";
        std::stringstream debug1;
        std::string       Debug1;
        debug1 << i;
        debug1 >> Debug1;
        system("mkdir IOI");
        freopen("IOI\\IOI.log", "w", stdout);
        std::string command = "tools\\Compare\\IOIStyle.exe debug-" + dataname +
                              "\\" + dataname + Debug1 + ".ans data-" +
                              dataname + "\\" + dataname + Debug1 + ".out";
        int flag = system(command.c_str());
        sp >> runtime;
        freopen("Debug.log", "a", stdout);
        if (runtime > maxtime) {
            std::cout << "TestCase " << i
                      << ", result: TLE. The program\'s runtime is " << runtime
                      << " ms.\n";
        }
        else if (flag == 1) {
            std::cout << "TestCase " << i << ", result: AC.\n";
        }
        else if (flag == 0) {
            std::cout << "TestCase " << i << ", result: WA.\n";
        }
        else {
            std::cout << "TestCase " << i << ", result: UKE.\n";
        }
    }
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
#endif