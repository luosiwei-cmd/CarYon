//a+b problem test
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="A+B_Problem_Test";
	makein(1,10)/*make 10 in files*/{
		csh();
		inint(cyrand(0,100));
		instring("  ");
		inint(cyrand(0,100));
	}
	makeout(1,10);
	closefile();
	return 0;
}
