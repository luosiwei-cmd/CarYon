#include"caryon.h"
using namespace std;
using namespace ca;
int n,m;
int main(){
	dataname="CF1A";
	makein(1,10){
		csh();
		int a;
		a=cyrand(1,100000);
		inint(a);
		instring(" ");
		int s;
		s=a*a;
		while(n*m<=s+50){
			n=a+cyrand(-100,200);
			m=a+cyrand(-100,200);
		}
		inint(n);
		instring(" ");
		inint(m);
		instring("\n");
	}
	makeout(1,10);
	return 0; 
} 
