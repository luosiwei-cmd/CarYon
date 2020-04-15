#ifndef CRAYON_H
#define CRAYON_H 
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define makein(n) for(ci=1;ci<=n;ci++)
#define csh cnt=0
#define bh ++cnt
#define ns "-1"
#define fs(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(ll i=x;i>=y;i+=z) 
#define ull unsigned long long
#define db double
#define ms(a,b) memset(a,b,sizeof(a))
#define sz(a) sizeof(a)
#define lcm(x,y) (x/cgcd(x,y)*y)
using namespace std;
string dataname;
int cprime[1000000];
int ci;
int cnt;
const int N=151,inf=0x7f7f7f7f,moda=1000000007;
bool debug;
namespace crand{
	bool isInit;
	int MTindex;
	ll MT[624];
	void csrand(int seed) {
		MTindex=0;
		isInit=1;
		MT[0]=seed;
		for(int i=1;i<624;i++) {
			int t=1812433253*(MT[i-1]^(MT[i-1]>>30))+i;
			MT[i]=t&0xffffffff;
		}
	}
	inline void generate() {
		for(int i=0;i<624;i++) {
			long long y=(MT[i]&0x80000000)+(MT[(i+1)%624]&0x7fffffff);
			MT[i]=MT[(i+397)%624]^(y>>1);
			if(y%2==1) MT[i]^=2147483647;
		}
	}
	inline int cyrand() {
		if(!isInit) csrand((int)time(NULL));
		if(MTindex==0) generate();
		int y=MT[MTindex];
		y=y^(y>>11);
		y=y^((y<<7)&1636928640);
		y=y^((y<<15)&1022730752);
		y=y^(y>>18);
		MTindex=(MTindex+1)%624;
		return y;
	}
	inline ll cyrand_ll() {
		return ((ll)(cyrand())<<31)+cyrand();
	}
	inline int cyrand(int a,int b) {
		if(a>b) a=b;
		if(a==b) return a;
		else return cyrand()%(b-a+1)+a;
	}
	inline ll cyrand_ll(ll a,ll b) {
		if(a>b) a=b;
		if(a==b) return a;
		else return cyrand_ll()%(b-a+1)+a;
	}
	inline bool cyrand_bool(){
		if(cyrand(0,1)==0)	return false;
		else return true;
	}
	inline char cyrand_engs(){
		return 'a'+cyrand(0,26);
	}
	inline char cyrand_engb(){
		return 'A'+cyrand(0,26);
	}
}
namespace cmath{
	class kucan{
		public:
    		ll p,q,dlt[N][N];//p*q
   		 	kucan(){
    		    p=1,q=1;
        		ms(dlt,0);
    		}
    		kucan operator + (const kucan b) const{
        		kucan c;
        		if(b.p==p&&b.q==q){
         		   fs(i,1,p,1){
          		      fs(j,1,q,1){
          		          c.dlt[i][j]=dlt[i][j]+b.dlt[i][j];
           		     	}
          		    }
            	c.p=p;
           	 	c.q=q;
        		}else{
            		fs(i,1,p,1){
                		fs(j,1,q,1){
                    		c.dlt[i][j]=dlt[i][j];//+b.dlt[i][j];
                		}
            		}
            		fs(i,1,b.p,1){
                		fs(j,1,b.q,1){
                	    	c.dlt[i+p][j+q]=b.dlt[i][j];
                		}
            		}
            		c.p=p+b.p;
            		c.q=q+b.q;
        		}
        		return c;
    		}
    		kucan operator - (const kucan b) const{
        		kucan c;
        		if(b.p==p&&b.q==q){
            		fs(i,1,p,1){
                		fs(j,1,q,1){
                    		c.dlt[i][j]=dlt[i][j]-b.dlt[i][j];
                		}
            		}
            		c.p=p;
            		c.q=q;
        		}
        		return c;
    		}
	    	kucan operator * (const kucan b) const{
	       		kucan c;
	        	if(b.p==q){
	            	c.p=p;
	            	c.q=b.q;
	            	fs(i,1,c.p,1){
	                	fs(j,1,c.q,1){
	                    	ll jk=0;
	                    	fs(k,1,q,1){
	                        	jk+=dlt[i][k]*b.dlt[k][j];
	                        	jk%=moda;
	                    	}
	                    	c.dlt[i][j]=jk;
	                    	c.dlt[i][j]%=moda;
	                	}
	            	}
				}
	        	return c;
	    	}
	    	kucan operator * (const ll b) const{
	        	kucan c;
	        	fs(i,1,p,1){
	            	fs(j,1,q,1){
	                	c.dlt[i][j]=dlt[i][j]*b;
	            	}
	        	}
	        	c.p=p;
	        	c.q=q;
	        	return c;
	    	}
	    	void out(){
	        	fs(i,1,p,1){
	            	fs(j,1,q,1){
	                	cout<<dlt[i][j];
	                		cout<<' ';
	            	}
	            	cout<<endl;
	        	}
	    	}
	    	void in(int x,int y){
	        	p=x;
	        	q=y;
	        	fs(i,1,p,1){
	            	fs(j,1,q,1){
	                	cin>>dlt[i][j];
	            	}
	        	}
	    	}
	};
	inline ld cpi();
	class circle{
		public:
			ld r,c,area;
			ld oprc(bool flag){
				if(flag)
					c=2*r*cpi();
				return 2*r*cpi();
			}
			ld opra(bool flag){
				if(flag)
					area=cpi()*r*r;
				return cpi()*r*r;
			}
	};
	inline ld cpi(){
		return 3.141592653589793238462643383279502884197169399;
	}
	inline ld cdistance(ld a1,ld a2,ld b1,ld b2){
		return sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
	}
	template<typename T>
	inline T cabs(T a){
		return a>0?a:-a;
	}
	inline int cmin(int a,int b){
		return a<b?a:b;
	}
	inline int cmax(int a,int b){
		return a>b?a:b;
	}
	inline int cgcd(int a,int b){
		return a==0?b:cgcd(b%a,a);
	}
	inline bool isprime(int a){
		if(a<2)	return false;
		for(int i=2;i<=sqrt(a);++i){
			if(a%i==0)	return false;
		}
		return true;
	}
	inline int cmakeprime(int a,int b){
		int prcnt=0;
		for(int i=a;i<=b;i++){
			if(isprime(i)){
				cprime[prcnt++]=i;
			}
		}
	}
	inline int crprimenum(int beg,int end){
		return cprime[crand::cyrand(beg,end)];
	}
	class frac{
		public:
			int son,mom;
			ld value(){
				return (ld)son/mom;
			}
			string take(bool flag){
				int c=cgcd(son,mom);
				son/=c;
				mom/=c;
				stringstream tmp1,tmp2;
				string aaa,bbb;
				tmp1<<son;
				tmp1>>aaa;
				tmp2<<mom;
				tmp2>>bbb;
				return (flag)?aaa+'/'+bbb:aaa+' '+bbb;
			}
			string fracr(bool flag){
				stringstream tmp1,tmp2;
				string aaa,bbb;
				tmp1<<son;
				tmp1>>aaa;
				tmp2<<mom;
				tmp2>>bbb;
				return (flag)?aaa+'/'+bbb:aaa+' '+bbb;
			}
			void huaj(){
				ll kk=cgcd(son,mom);
				son/=kk;
				mom/=kk;
			}//化简 
			bool fu(){
				huaj();
				if(son<0&&mom<0){
					son=-son;
					mom=-mom;
					return 0;
				}else if(son>0&&mom>0){
					return 0;
				}
				else return 1;
			}
			frac operator * (const frac b) const{
				frac c;
				c.son=son*b.son;
				c.mom=mom*b.mom;
				c.huaj();
				return c;
			}
			frac operator / (const frac b) const{
				frac c;
				c.son=son*b.mom;
				c.mom=mom*b.son;
				c.huaj();
				return c;
			}
			frac operator + (const frac b) const{
				frac c;
				c.mom=lcm(mom,b.mom);
				c.son=son*(c.mom/mom)+b.son*(c.mom/b.mom);
				c.huaj();
				return c;
			}
			frac operator - (const frac b) const{
				frac c;
				c.mom=lcm(mom,b.mom);
				c.son=son*(c.mom/mom)-b.son*(c.mom/b.mom);
				c.huaj();
				return c;
			}
			bool operator > (const frac b) const{
				frac c=*this-b; 
				if(c.fu()) return 0;
				else return 1;
			}
			bool operator < (const frac b) const{
				return b>*this;
			}
			bool operator <= (const frac b) const{
				return !(*this>b);
			}
			bool operator >= (const frac b) const{
				return !(b>*this);
			}
			bool operator != (const frac b) const{
				return (b>*this)||(*this>b);
			}
			bool operator == (const frac b) const{
				return !(*this>b)&&!(b>*this);
			}
	};
}
namespace inout{
	inline void inint(int a){
		string c,ccci,tnmp;
		stringstream ss,cci;
		if(cnt==0){
			cci<<ci;
			cci>>ccci;
			string name=dataname+ccci+".in";
			freopen(name.c_str(),"w",stdout);
			freopen(name.c_str(),"r",stdin);
		}
		ss<<a;
		ss>>c;
		cin>>tnmp;
		c=tnmp+c;
		cout<<c;
		bh;
	}
	inline void instring(string a){
		string ccci,tnmp;
		if(cnt==0){
			stringstream cci;
			cci<<ci;
			cci>>ccci;
			string name=dataname+ccci+".in";
			freopen(name.c_str(),"w",stdout);
			freopen(name.c_str(),"r",stdin);
		}
		cin>>tnmp;
		a=tnmp+a;
		cout<<a;
		bh;
	}
	void out(int a){/*参考了一下crayon完成了*/ 
		freopen("CON.exe","r",stdin);
		freopen("CON.exe","w",stdout);
		stringstream aa;
		string aaa;
		aa<<a;
		aa>>aaa;
		string abc;
		string name=dataname+aaa+".in";
		freopen(name.c_str(),"r",stdin);
		std::string outname=dataname+aaa+".out";
		freopen(outname.c_str(),"w",stdout);
		system("std.exe");
		freopen("CON.exe","r",stdin);
		freopen("CON.exe","w",stdout);
	}
	void makeout(int a){
		for(int i=1;i<=a;++i)
			out(i);
		fclose(stdin);
		fclose(stdout);
	}
	void closefile(){
		freopen("CON.exe","r",stdin);
		freopen("CON.exe","w",stdout);
	}
}
namespace ca{
	using namespace crand;
	using namespace cmath;
	using namespace inout;
}
#endif
