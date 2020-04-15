#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="st test";
	makein(30){
		csh;
		int n,x,v,t;
		n=cyrand(1,200);
		inint(n);
		instring("\n");
		for(int i=0;i<n;i++){
			x=cyrand(-500,500);
			v=cyrand(0,1000000000);
			t=cyrand(0,500);
			inint(x);
			instring(" ");
			inint(v);
			instring(" ");
			inint(t);
			instring("\n");
		}
	}
	makeout(30);
}
