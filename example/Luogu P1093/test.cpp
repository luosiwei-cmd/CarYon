#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="Luogu_P1093";
	makein(1,10){
		csh();
		int n;
		n=300;
		inint(n);
		instring("\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				inint(cyrand(0,100));
				instring(" ");
			}
			instring("\n");
		}
	}
	makeout(1,10);
}
