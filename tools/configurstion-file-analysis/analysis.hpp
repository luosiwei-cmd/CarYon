#ifndef ANALYSIS_HPP 
#define ANALYSIS_HPP 
#include<bits/stdc++.h>
#include<io.h>
#include<windows.h>
using namespace std;
struct _finddata_t info;
ofstream fout("test.cpp");
std::string type;
int start_d,end_d;
int CNT,_CNT,if_cnt;
string _variable[10000]={""};
int _i=0;
bool ___flag;
void init(){
	fout<<"#include\"caryon.h\"\n";
	fout<<"using namespace std;\n";
	fout<<"using namespace ca;\n";
	fout<<"\n";
	fout<<"int main(){\n";
}
void end(){ 
	fout<<"    }\n";
	fout<<"    makeout("<<start_d<<","<<end_d<<");\n";
	fout<<"    return 0;\n";
	fout<<"}\n";
	cout<<"Analysis end with succeed.\n\n";
	cout<<"Please check the analysis.log for more information.\n";
	system("pause");
}
void addMakein(int a,int b){
	fout<<"    makein("<<a<<","<<b<<"){\n";
	fout<<"        csh();\n";
	clog<<"LOG: Makein function was written successfully.\n";
}
void addInint(int a,int b){
	fout<<"        inint(cyrand("<<a<<","<<b<<"));\n";
	clog<<"LOG: Make a random number successfully.\n";
}
void addInint(string a){
	fout<<"        inint("<<a<<");\n";
	clog<<"LOG: Make a number successfully.\n";
}
void addInstring(string a){
	fout<<"        instring(\""<<a<<"\");\n";
	clog<<"LOG: Make a string or a space successfully.\n";
}
void addInstring(int a){
	fout<<"        instring(cyrand_word("<<a<<"));\n";
	clog<<"LOG: Make a random string successfully.\n";
}
void makedataERR(){
	cerr<<"ERR: on row "<<CNT<<", more than 1 makedata operation is not be allowed. | The makedata operation may be not in the fitst row. Plese check.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NothatERR(){
	cerr<<"ERR: on row "<<CNT<<", unknown operation found.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NoMakedataERR(){
	cerr<<"ERR: there is not a makedata opertion in your compile file.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NoiniERR(){
	cerr<<"ERR: cannot find file: control.ini.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);  
}
void variWrongERR(){
	cerr<<"ERR: on row "<<CNT<<", the variable name is wrong.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void twoVariERR(){
	cerr<<"ERR: on row "<<CNT<<", the variable name has already been named.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void nothisVariERR(){
	cerr<<"ERR: on row "<<CNT<<", there is no variable name "<<type<<".\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NoForEndERR(){
	cerr<<"ERR: The for do not have an end.";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void addInt(string type){
	fout<<"        int "<<type<<";\n";
	clog<<"LOG: Add int variable "<<type<<" successfully.\n";
	_variable[_i++]=type;
}
void addIntAssign(string type,int a){
	fout<<"        "<<type<<"="<<a<<";\n";
	clog<<"LOG: Assign variable "<<type<<" to "<<a<<" successfully.\n";
}
bool isvari(string type){
	if(!((type[0]>='a' and type[0]<='z')or(type[0]>='A' and type[0]<='Z')or(type[0]=='_')or(type[0]=='$'))){
		return false;
	}
	for(int i=1;i<type.size();i++){
		if(!((type[i]>='a' and type[i]<='z')or(type[i]>='A' and type[i]<='Z')or(type[i]=='_')or(type[i]=='$')or(type[i]>='0' and type[i]<='9'))){
			return false;   
		}
	}
	return true;
}
bool alreadyhave(string type){
	for(int i=0;i<_i;i++){
		if(_variable[i]==type)	return false;
	}
	return true;
}
void addvariInint(string type){
	fout<<"        inint("<<type<<");\n";
	clog<<"LOG: Make a variable number successfully.\n";
}
void assignrandvari(int start,int end,string type){
	fout<<"        "<<type<<"=cyrand("<<start<<","<<end<<");\n";
	clog<<"LOG: Assign  variable "<<type<<" with a random number successfully.\n";
}
void addFor(string i,int start,int end,int add){
	___flag=true;
	fout<<"        for(int "<<i<<"="<<start<<";"<<i<<"<="<<end<<";"<<i<<"+="<<add<<"){\n";
	clog<<"LOG: Add a for successfully.\n";
}
void endFor(){
	___flag=false;
	fout<<"        }\n";
	clog<<"LOG: End a for successfully.\n";
}
void NotinForERR(){
	cerr<<"ERR: On row "<<CNT<<", the continue/break/sf is not in a for.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NotinIfERR(){
	cerr<<"ERR: On row "<<CNT<<", the fi is not in an if.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void NoIfEndERR(){
	cerr<<"ERR: A/Some if(s) do not have an end.";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	cout<<"Analysis failed. Please check the analysis.log for more information.\n";
	system("pause");
	exit(0);
}
void addContinue(){
	fout<<"        continue;\n";
	clog<<"LOG: Add a \"continue\" successfully.\n";
}
void addBreak(){
	fout<<"        break;\n";
	clog<<"LOG: Add a break successfully.\n";
}
void addIf(string type){
	if_cnt++;
	fout<<"        if("<<type<<"){\n";
	clog<<"Add an if successfully.\n";
}
void endIf(){
	if_cnt--;
	fout<<"}\n";
	clog<<"End an if successfully.\n";
}
#endif //#ifndef ANALYSIS_HPP 
