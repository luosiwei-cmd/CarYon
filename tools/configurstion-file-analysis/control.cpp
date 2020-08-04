#include"analysis.hpp"
using namespace std;
int main(){
	init();
	while(fin>>type){
		CNT++;
		if(type=="makedata"){
			_CNT++;
			if(CNT!=1){
				makedataERR();
			}
			fin>>start_d>>end_d;
			addMakein(start_d,end_d);
		}
		else if(type=="inint"){
			fin>>type;
			if(type=="cyrand"){
				int start,end;
				fin>>start>>end;
				addInint(start,end);
			}
			else{
				addInint(type);
			}
		}
		else if(type=="instring"){
			fin>>type;
			addInstring(type);
		}
		else if(type=="space"){
			addInstring(" ");
		}
		else{
			NothatERR();
		}
	}
	if(_CNT==0){
		NoMakedataERR();
	}
	end();
}
