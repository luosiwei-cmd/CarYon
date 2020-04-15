#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
inline int read() {
    re int t=0,f=0;
    re char v=getchar();
    while(v<'0')f|=(v=='-'),v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return f?-t:t;
}
using namespace std;
long long dp[202][202][502][2],ans;
int n,p;
struct node{
    int x,t,v;
}a[202];
inline bool cmp(re node x,re node y){
    return x.x<y.x;
}
inline long long max(re long long x,re long long y){
    return x>y?x:y;
}
signed main(){
    n=read();
    for(re int i=1;i<=n;++i)a[i].x=read(),a[i].v=read(),a[i].t=read();
    a[++n].x=0;a[n].t=-1;a[n].v=0;
    sort(a+1,a+n+1,cmp);
    for(re int i=1;i<=n;++i)if(a[i].t==-1)p=i;
    for(re int i=p;i;--i)for(re int j=p;j<=n;++j)for(re int k=0;k<=500;++k)dp[i][j][k][0]=dp[i][j][k][1]=-(1ll<<61);
    memset(dp[p][p],0,sizeof(dp[p][p]));
    for(re int i=p;i;--i){
        for(re int j=p;j<=n;++j){
            for(re int k=0;k+a[j].x-a[i].x<=500;++k){
                dp[i][j][k+a[j].x-a[i].x][0]=max(dp[i][j][k+a[j].x-a[i].x][0],dp[i][j][k][1]);
                dp[i][j][k+a[j].x-a[i].x][1]=max(dp[i][j][k+a[j].x-a[i].x][1],dp[i][j][k][0]);
            }
            for(re int k=1;k<=500;++k){
                dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j][k-1][0]);
                dp[i][j][k][1]=max(dp[i][j][k][1],dp[i][j][k-1][1]);
            }
            for(re int k=0;k+a[j+1].x-a[j].x<=500;++k)dp[i][j+1][k+a[j+1].x-a[j].x][1]=max(dp[i][j+1][k+a[j+1].x-a[j].x][1],dp[i][j][k][1]+(k+a[j+1].x-a[j].x<=a[j+1].t?a[j+1].v:0));
            for(re int k=0;k+a[i].x-a[i-1].x<=500;++k)dp[i-1][j][k+a[i].x-a[i-1].x][0]=max(dp[i-1][j][k+a[i].x-a[i-1].x][0],dp[i][j][k][0]+(k+a[i].x-a[i-1].x<=a[i-1].t?a[i-1].v:0));
        ans=max(ans,max(dp[i][j][500][0],dp[i][j][500][1]));}
    }
    printf("%lld\n",ans);
}
