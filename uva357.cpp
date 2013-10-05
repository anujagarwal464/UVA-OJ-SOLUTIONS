#include <cstdio>
#include <cstring>

int coins[5]={1,5,10,25,50};

int main(){
 long long int ans[30010];
 memset(ans,0,sizeof(ans));
 ans[0]=1;
 for(int i=0;i<5;i++)
    for(int j=coins[i];j<=30000;j++)
      ans[j]+=ans[j-coins[i]];
 int n;
 while(scanf("%d",&n)==1){
  if(ans[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
  else          printf("There are %lld ways to produce %d cents change.\n",ans[n],n);
 }
 return 0;
}
