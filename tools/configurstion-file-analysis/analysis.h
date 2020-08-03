#ifndef ANALYSIS_H
#define ANALYSIS_H
#include<bits/stdc++.h>
using namespace std;
ifstream fin("control.ini");
ofstream fout("test.cpp");
std::string type;
int start_d,end_d;
int cnt,CNT;
void init(){
	fout<<"#include\"caryon.h\"\n";
	fout<<"using namespace std;\n";
	fout<<"using namespace ca;\n";
	fout<<"\n";
	fout<<"int main(){\n";
}
void end(){
	fout<<"}\n";
	fout<<"makeout("<<start_d<<","<<end_d<<");\n";
	fout<<"return 0;\n";
	fout<<"}\n";
	cout<<"Analysis end with succeed.\n\n";
	system("pause");
}
void addMakein(int a,int b){
	fout<<"makein("<<a<<","<<b<<"){\n";
	fout<<"csh();\n";
}
void addInint(int a,int b){
	fout<<"inint(cyrand("<<a<<","<<b<<"));\n";
}
void addInint(string a){
	fout<<"inint("<<a<<");\n";
}
void addInstring(string a){
	fout<<"instring(\""<<a<<"\");\n";
}
void makedataERR(){
	cerr<<"ERR: on row "<<CNT<<", more than 1 makedata operation is not be allowed. Plese check.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	exit(0);
}
void NothatERR(){
	cerr<<"ERR: on row "<<CNT<<", unknown operation found.\n";
	fout<<"\n\n//Analysis failed, plese check stderr to know more.\n";
	exit(0);
}
#endif //#ifndef ANALYSIS_H
