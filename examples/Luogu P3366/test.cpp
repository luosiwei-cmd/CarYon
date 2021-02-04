#include "caryon.h"
// including <bits/stdc++.h>
using namespace std;
using namespace ca;  // namespace
graph< int > example;
int          main() {
    dataname = "Luogu_P3366";  // dataname
    maxtime  = 1000;
    makein(1, 10) {
        csh();
        if (cyrand(0, 1) > 0) {
            example = rand_graph(10, 10, 1, 10, cyrand);
        }
        else {
        	do{
        		example = rand_graph(10, 10, 1, 10, cyrand);
			}while(!example.is_connect());
        }
        ingraph(example);
        // Please finish these rows
    }
    makeout(1, 10);
    return 0;
}
