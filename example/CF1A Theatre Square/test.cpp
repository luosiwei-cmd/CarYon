#include"caryon.h"
using namespace std;
using namespace ca;
int n,m;
int main(){
	dataname="CF1A";
	makein(1,10){
		csh();
		int a;
		inint(a);
		instring(" ");
		int s;
		s=a*a;
		while(n*m<=s+5){
			n=a+cyrand(-10,20);
			m=a+cyrand(-10,20);
		}
		inint(n);
		instring(" ");
		inint(m);
		instring("\n");
	}
	makeout(1,10);
	return 0; 
} 
