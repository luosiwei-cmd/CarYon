#include<bits/stdc++.h>
using namespace std;
struct pupil{
	int no;
	int c;
	int m;
	int e;
	int s;
};
bool cmp(pupil x,pupil y){
	if(x.s!=y.s)	return x.s>y.s;
	 if(x.c!=y.c)	return x.c>y.c;
	else	return x.no<y.no;	
} 
int n;
int main(){
	cin>>n;
	pupil a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].no=i+1;
		a[i].s=a[i].c+a[i].m+a[i].e;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<5;i++){
		cout<<a[i].no<<' '<<a[i].s<<'\n';
	}
	return 0;
}
