#ifndef CRAYON_H
#define CRAYON_H 
#include<bits/stdc++.h>
#define db double
#define ll long long
#define ld long db
#define makein(m,n) for(ci=m;ci<=n;ci++)
#define bh ++cnt
#define ns "-1"
#define fs(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(ll i=x;i>=y;i+=z) 
#define ull unsigned long long
#define ms(a,b) memset(a,b,sizeof(a))
#define sz(a) sizeof(a)
#define lcm(x,y) (x/cgcd(x,y)*y)
std::string dataname;
int cprime[1000000];
int ci;
int cnt;
const int N=151,inf=0x7f7f7f7f,moda=1000000007;
bool ___flag=false;
void csh(){
	cnt=0;
}
long double runtime[300];
namespace cconst{
	const long double PI=3.141592653589793238462643383279502884197169399;
	const long double E=2.7182818284590452353602874713527;
	const std::string ALPHABET_SMALL="abcdefghijklmnopqrstuvwxyz";
	const std::string ALPHABET_CAPITAL="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string ALPHABET="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string NUMBERS="0123456789";
}
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
	inline char cyrand_letter(){
		return cyrand(32,126);
	}
	inline char cyrand_engs(){
		return 'a'+cyrand(0,26);
	}
	inline char cyrand_engb(){
		return 'A'+cyrand(0,26);
	}
	inline char cyrand_fomatc(){
		switch(cyrand(0,4)){
			case 0:{
				return '\n';
				break;
			}
			case 1:{
				return '\t';
				break;
			}
			case 2:{
				return '\r';
				break;
			}
			case 3:{
				return '\v';
				break;
			}
			case 4:{
				return '\f';
				break;
			}
		}
	}
	inline std::string cyrand_word(int a){
		std::string chen_zhe;
		for(int kkksc03=0;kkksc03<a;kkksc03++){
			if(cyrand_bool()){
				chen_zhe[kkksc03]=cyrand_engs();
			}
			else{
				chen_zhe[kkksc03]=cyrand_engb();
			}
		}
		return chen_zhe;
	}
	inline std::string cyrand_article(int a){
		std::string soha;
		soha=cyrand_word(cyrand(1,10));
		for(int lzn=1;lzn<a;lzn++){
			soha=soha+" "+cyrand_word(cyrand(1,10));
		}
		return soha;
	}
	template<typename T>
	inline T choice(T* a,int lbound,int ubound){
		return a[cyrand(lbound,ubound)];
	}
	inline double doubleRandom(){
		srand(time(0));
		return (double)(rand()/(double)RAND_MAX);
	}
}
namespace cmath{
	class quadtri{
		public:
			int a,b,c;
			char s;
			quadtri make(char abc){
				quadtri tmp;
				tmp.s=abc;
				tmp.a=crand::cyrand(-100,100);
				tmp.b=crand::cyrand(-100,100);
				tmp.c=crand::cyrand(-100,100);
				return tmp;
			}
			int aaa;
			quadtri makecanfac(char abc){
				quadtri tmp;
				do{
					tmp.s=abc;
					tmp.a=crand::cyrand(-100,100);
					tmp.b=crand::cyrand(-100,100);
					tmp.c=crand::cyrand(-100,100);
					aaa=b*b-4*a*c;
				}while(!(aaa==(int)sqrt(aaa)*(int)sqrt(aaa)));
				return tmp;
			}
			quadtri operator + (const quadtri b)const{
				quadtri tmp;
				tmp.a=tmp.a+b.a;
				tmp.b=tmp.b+b.b;
				tmp.c=tmp.c+b.c;
				return tmp;
			}
			quadtri operator - (const quadtri b)const{
				quadtri tmp;
				tmp.a=tmp.a-b.a;
				tmp.b=tmp.b-b.b;
				tmp.c=tmp.c-b.c;
				return tmp;
			}
	};
	class stpolyon{
		public:
			ld length,perimeter;
			ll edge;
			ld oprc(bool flag){
				if(flag){
					perimeter=(ld)edge*length;
				}
				return (ld)edge*length;
			}
	}; 
	class kucan{//By Billy2007
		public:
    		ll p,q,dlt[N][N];
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
	                	std::cout<<dlt[i][j];
	                	std::cout<<' ';
	            	}
	            	std::cout<<std::endl;
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
			circle operator + (const circle x) const{
				circle tmp;
				tmp.r=tmp.r+x.r;
				tmp.c=2*tmp.r*cpi();
				tmp.area=cpi()*tmp.r*tmp.r;
				return tmp;
			}
			circle operator - (const circle x) const{
				circle tmp;
				tmp.r=tmp.r-x.r;
				tmp.c=2*tmp.r*cpi();
				tmp.area=cpi()*tmp.r*tmp.r;
				return tmp;
			}
			bool operator > (const circle b) const{
				circle c=*this-b;
				if(c.r>0)	return true;
				else return false;
			}
			bool operator >= (const circle b) const{
				return !(b>*this);
			}
			bool operator < (const circle b) const{
				return b>*this;
			}
			bool operator <= (const circle b) const{
				return !(*this>b); 
			}
			bool operator == (const circle b) const{
				return !(*this>b)&&!(b>*this);
			}
			bool operator != (const circle b) const{
				return !(*this==b);
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
	class rectangle{
		public:
			int a,b,peri,area;
	}; 
	class frac{//By GoneTime&luosw
		private:
			void huaj(){
				ll kk=cgcd(son,mom);
				son/=kk;
				mom/=kk;
			}
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
		public:
			int son,mom;
			ld value(){
				return (ld)son/mom;
			}
			std::string take(bool flag){
				int c=cgcd(son,mom);
				son/=c;
				mom/=c;
				std::stringstream tmp1,tmp2;
				std::string aaa,bbb;
				tmp1<<son;
				tmp1>>aaa;
				tmp2<<mom;
				tmp2>>bbb;
				return (flag)?aaa+'/'+bbb:aaa+' '+bbb;
			}
			std::string fracr(bool flag){
				std::stringstream tmp1,tmp2;
				std::string aaa,bbb;
				tmp1<<son;
				tmp1>>aaa;
				tmp2<<mom;
				tmp2>>bbb;
				return (flag)?aaa+'/'+bbb:aaa+' '+bbb;
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
		std::string c,ccci,tnmp;
		std::stringstream ss,cci;
		if(cnt==0){
			if(!___flag){
				std::string a666="mkdir data-"+dataname;
				system(a666.c_str());
				___flag=true;
			}
			cci<<ci;
			cci>>ccci;
			std::string name="data-"+dataname+"./"+dataname+ccci+".in";
			freopen(name.c_str(),"w",stdout);
			freopen(name.c_str(),"r",stdin);
		}
		ss<<a;
		ss>>c;
		std::cin>>tnmp;
		c=tnmp+c;
		std::cout<<c;
		bh;
	}
	inline void instring(std::string a){
		std::string ccci,tnmp;
		if(cnt==0){
			if(!___flag){
				std::string a666="mkdir data-"+dataname;
				system(a666.c_str());
				___flag=true;
			}
			std::stringstream cci;
			cci<<ci;
			cci>>ccci;
			std::string name="data-"+dataname+"./"+dataname+ccci+".in";
			freopen(name.c_str(),"w",stdout);
			freopen(name.c_str(),"r",stdin);
		}
		std::cin>>tnmp;
		a=tnmp+a;
		std::cout<<a;
		bh;
	}
	inline void out(int a){
		freopen("CON.exe","w",stdout);
		freopen("CON.exe","r",stdin);
		std::stringstream aa;
		std::string aaa;
		aa<<a;
		aa>>aaa;
		std::string abc;
		std::string name="data-"+dataname+"./"+dataname+aaa+".in";
		freopen(name.c_str(),"r",stdin);
		std::string outname="data-"+dataname+"./"+dataname+aaa+".out";
		freopen(outname.c_str(),"w",stdout);
		system("std.exe");
	}
	inline void makeout(int b,int a){
		for(int i=b;i<=a;++i){
			out(i);
			freopen("CON.exe","r",stdin);
			freopen("CON.exe","w",stdout);
			std::stringstream _a;
			std::string _i;
			_a<<i;
			_a>>_i;
			std::string fff="Generating:"+dataname+_i+".out...\n";
			printf(fff.c_str());
		}
		printf("out files are already generated, you can find them in the new folder in this directory.\n");
	}
	inline void closefile(){		
		freopen("CON.exe","w",stdout);
		freopen("CON.exe","r",stdin);
	}
}
namespace cydebug{
	void makeDebugFile(int a,int b){
		std::string ___a="mkdir debug-"+dataname;
		system(___a.c_str());
		for(int i=a;i<=b;++i){
			freopen("CON.exe","w",stdout);
			freopen("CON.exe","r",stdin);
			std::stringstream debug1;
			std::string Debug1;
			debug1<<i;
			debug1>>Debug1;
			std::string debugname1="debug-"+dataname+"./"+dataname+Debug1+".ans";
			std::string debugname2="data-"+dataname+"./"+dataname+Debug1+".in";
			freopen(debugname1.c_str(),"w",stdout);
			freopen(debugname2.c_str(),"r",stdin);
			long double clock1=clock(); 
			system("myprogram.exe");
			runtime[i]=clock()-clock1;
		}
	}
	void compareFile(int a,int b){
		freopen("Debug.log","w",stdout);
		for(int i=a;i<=b;i++){
			std::cout<<"Comparing "<<i<<".out and "<<i<<".ans...\n";
			freopen("CON.exe","w",stdout);
			freopen("CON.exe","r",stdin);
			std::stringstream debug1;
			std::string Debug1;
			debug1<<i;
			debug1>>Debug1;
			std::string command="tools\\Compare\\NOIPStyle.exe debug-"+dataname+"//"+dataname+Debug1+".ans data-"+dataname+"//"+dataname+Debug1+".out";
			int flag=system(command.c_str()); 
			freopen("Debug.log","a",stdout);
			if(flag==1){
				std::cout<<"TestCase "<<i<<", result: AC.\n";
			}
			else if(flag==0){
				std::cout<<"TestCase "<<i<<", result: WA.\n";
			}
			else{
				std::cout<<"TestCase "<<i<<", result: UKE.\n";
			}
		}
	}
	void debug(int a,int b){
		makeDebugFile(a,b);
		compareFile(a,b);
	}	
}
namespace cgraph{
	template<typename T> struct edge {
		int v;
		T w;
		bool operator<(const edge& rw )const  //priority_queue
		{
			return w>rw.w;
		}
	};	
	template<typename T> struct U {
		std::vector<edge<T> >u;
	};
	template<typename T> struct graph {  //graph
		int n,m;
		std::vector<U<T> >g;
		graph() {
			;
		}

		void update(int ntemp) {
			U<T> updatemp;
			updatemp.u.clear();
			while(g.size()<=ntemp) g.push_back(updatemp);
		}
		void addedge(int u,int v,T w) {
			n=cmath::cmax(n,u);
			n=cmath::cmax(n,v);
			update(cmath::cmax(u,v));
			m++;
			edge<T> tmp;tmp.v=v,tmp.w=w;
			g[u].u.push_back(tmp);
		}
		bool is_connect() {
			const int vstsize=n+1;
			int vstn=0;
			bool vst[vstsize];
			memset(vst,false,sizeof(vst));
			std::queue<int>q;
			int begin=crand::cyrand(1,n);
			vst[begin]=true;
			vstn=1;
			q.push(begin);			
			while(!q.empty()) {
				int tmp=q.front();
				q.pop();
				for(int i=0;i<g[tmp].u.size();i++) {
					if(!vst[g[tmp].u[i].v]) {
						vst[g[tmp].u[i].v]=true;
						vstn++;
						q.push(g[tmp].u[i].v);
					}
				}
			}	
			return((vstn==n)?true:false);
		}
		void output(graph<T> c){			
			std::cout<<c;
		}
	};
	template<typename T> std::ostream&operator<<(std::ostream&os,const graph<T>&c) {
		os<<c.n<<' '<<c.m<<'\n';
		for(int i=1;i<=c.n;i++)
		{
			for(int j=0;j<c.g[i].u.size();j++) os<<i<<' '<<c.g[i].u[j].v<<' '<<c.g[i].u[j].w<<'\n';
		}
		return os;
	}
	template<typename T> graph<T> operator+(graph<T> a,graph<T> b) {
		graph<T> ret;
		ret=a;
		ret.m=a.m+b.m;
		ret.update(ret.n);
		for(int i=1;i<=b.n;i++) {
			for(int j=0;j<b.g[i].u.size();j++) {
				ret.g[i].u.push_back(b.g[i].u[j]);
			}
		}
		return ret;
	}
	
	template<typename T> graph<T> rand_graph(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.n=n;
		ret.m=m;
		
		
		ret.update(n);
		
		for(int i=1;i<=m;i++) {
			edge<T> tmp; 
			tmp.v=crand::cyrand(1,m);
			tmp.w=randfunc(mn,mx);
			ret.g[crand::cyrand(1,n)].u.push_back(tmp);
		}
		return ret;
	}
	
	struct crayon_node2{
		int num,id1,id2;
	};
	
	bool crayon_cmp1(crayon_node2 a,crayon_node2 b) {return a.num<b.num;}

	template<typename T> graph<T> rand_dag(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.update(n);
		ret.n=n;
		ret.m=m;
		for(int i=1;i<=m;i++) {
			edge<T> tmp;
			int utmp=crand::cyrand(1,crand::cyrand(1,n-1));
			tmp.v=crand::cyrand(utmp+1,n);
			tmp.w=randfunc(mn,mx);
			ret.g[utmp].u.push_back(tmp);
		}
		return ret;
	}
	
	struct caryon_node1{
		int id;
		int soncnt;
	};
	
	template<typename T> graph<T> rand_tree(int n,int k,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.n=n;
		ret.m=n-1;
		ret.update(n);
		std::vector<caryon_node1>t;
		std::vector<int>hash;
		for(int i=1;i<=n;i++) {
			hash.push_back(i);
		}
		random_shuffle(hash.begin(),hash.end());
		caryon_node1 updatemp;
		updatemp.id=hash[0];
		updatemp.soncnt=0;
		t.push_back(updatemp);
		for(int j=2;j<=n;j++) {
			int i=hash[j-1];
			std::swap(t[crand::cyrand(0,t.size()-1)],t[t.size()-1]);
			t[t.size()-1].soncnt++;
			if(t[t.size()-1].soncnt==k) t.pop_back();
			edge<T> tmp;
			tmp.v=t[t.size()-1].id;
			tmp.w=randfunc(mn,mx);
			ret.g[i].u.push_back(tmp);
			updatemp.id=i;
			updatemp.soncnt=0;
			t.push_back(updatemp);
		}
		return ret;
	}
	
	template<typename T> graph<T> connect_graph(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		int k=crand::cyrand(1,n);
 		graph<T> ret;
		ret=rand_tree(n,k,mn,mx,randfunc);
		ret.m=m;
		for(int i=n;i<=m;i++) {
			edge<T> tmp;
			tmp.v=crand::cyrand(1,n);
			tmp.w=randfunc(mn,mx);
			ret.g[crand::cyrand(1,n)].u.push_back(tmp);
		}
		return ret;
	}
}
#if __cplusplus >= 201103
namespace caryon_cpp11{
	template<typename T> T choice_plus(std::initializer_list<T>a) {
		std::vector<T>b;
		for(auto i:a) {
			b.push_back(i);
		}
		return b[crand::cyrand(1,b.size())-1];
	}
}
#endif //#if __cplusplus>=201103
namespace ca{
	using namespace crand;
	using namespace cmath;
	using namespace inout;
	using namespace cydebug;
	using namespace cconst;
	using namespace cgraph;
	#if __cplusplus >= 201103
	using namespace caryon_cpp11;
	#endif //#if __cplusplus>=201103
}
#endif
