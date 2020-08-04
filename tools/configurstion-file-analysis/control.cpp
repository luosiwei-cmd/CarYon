#include"analysis.hpp"
using namespace std;
int main(){
	freopen("analysis.log","w",stderr);
	init();
	if(_findfirst("control.ini",&info)==-1){
		NoiniERR();	
	}
	ifstream fin("control.ini");
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
			else if(type=="variable"){
				fin>>type;
				if(!alreadyhave(type)){
					addvariInint(type);
				}
				else{
					nothisVariERR();
				}
			} 
			else{
				addInint(type);
			}
		}
		else if(type=="instring"){
			fin>>type;
			if(type!="cyrand") 
				addInstring(type);
			else{
				int a;
				fin>>a;
				addInstring(a);
			}
		}
		else if(type=="space"){
			addInstring(" ");
		}
		else if(type=="int"){
			fin>>type;
			if(isvari(type)){
				if(alreadyhave(type))
					addInt(type);
				else
					twoVariERR();
			}
			else{
				variWrongERR();
			}
		}
		else if(type=="assignment"){
			fin>>type;
			int _a;
			fin>>_a;
			if(!alreadyhave(type)){
				addIntAssign(type,_a);
			}
			else{
				nothisVariERR();
			}
		}
		else if(type=="variable_cyrand"){
			fin>>type;
			int start,end;
			fin>>start>>end;
			if(alreadyhave(type)){
				nothisVariERR();
			}
			else{
				assignrandvari(start,end,type);
			}
		}
		else if(type=="fs"){
			string __i;
			fin>>__i;
			int ___start,___end,___add;
			fin>>___start>>___end>>___add;
			if(!alreadyhave(__i))
				addFor(__i,___start,___end,___add);
			else{
				type=__i;
				nothisVariERR();
			}	
		}
		else if(type=="sf"){
			endFor();
		}
		else if(type=="continue"){
			if(___flag){
				addContinue();
			}
			else{
				NotinForERR();
			}
		}
		else if(type=="break"){
			if(___flag){
				addBreak();
			}
			else{
				NotinForERR();
			}
		}
		else{
			NothatERR();
		} 
	}
	if(_CNT==0){
		NoMakedataERR();
	}
	if(___flag){
		NoForEndERR();
	}
	end();
}
