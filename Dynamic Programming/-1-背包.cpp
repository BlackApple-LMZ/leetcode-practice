  //这个是01背包用二维dp的情况
  int backPack(int m, vector<int> &cost, vector<int> &vol) {
      vector<vector<int>> dp(cost.size()+1, vector<int>(m+1, 0));

      for(int i=1; i<=cost.size(); i++){
          for(int j=1; j<=m; j++){
              if(j-vol[i-1] >= 0)
                  dp[i][j] = max(dp[i-1][j], dp[i-1][j-vol[i-1]]+cost[i-1]);
              else
                  dp[i][j] = dp[i-1][j];
          }
      }

      return dp[cost.size()][m];
  }
  
  //优化成两个一维dp
  int backPack(int m, vector<int> &A) {
    vector<int> dp_pre(m+1, 0);
    vector<int> dp_cur(m+1, 0);
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=m; j++){
            if(j-A[i-1] >= 0)
                dp_cur[j] = max(dp_pre[j], dp_pre[j-A[i-1]]+A[i-1]);
            else
                dp_cur[j] = dp_pre[j];
        }
        dp_pre = dp_cur;
    }
    return dp_pre[m];
}
//真 优化成一维dp
int backPack(int m, vector<int> &A) {
    vector<int> dp(m+1, 0);
    for(int i=1; i<=A.size(); i++){
        for(int j=m; j>=0; j--){
            if(j-A[i-1] >= 0)
                dp[j] = max(dp[j], dp[j-A[i-1]]+A[i-1]);
        }
    }
    return dp[m];
}

//完全背包问题 下面两个结果应该是一样的，因为递推表达式和上一层没有关系 注意和01背包的区别，01背包是cur和pre的关系，这个是空间优化后的结果
int backPack1(int m, vector<int> &A) {
    vector<int> dp(m+1, 0);
    for(int i=1; i<=m; i++){
        for(int j=0; j<A.size(); j++){
            if(i >= A[j])
                dp[i] = max(dp[i], dp[i-A[j]]+A[j]);
        }
    }
    return dp[m];
}
int backPack(int m, vector<int> &A) {
    vector<int> dp(m+1, 0);
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=m; j++){
            if(j-A[i-1] >= 0)
                dp[j] = max(dp[j], dp[j-A[i-1]]+A[i-1]);
        }
    }
    return dp[m];
}

//多重背包问题 将多重背包转成01背包 用2^k转 logn优化 妙啊！！！！！！！！！！！
#include <bits/stdc++.h>
 
using namespace std;
 
struct E
{
    int w;  //体积
    int v;  //重量
} lis[2001];
 
int dp[101];
 
int main()
{
    int T,n,m;
    int p,h,k;
    int i,j;
    int index,c;
    scanf("%d%d",&n,&m);                //n表示容量，m表示种类
    index = 0;  //拆分后物品总数
    for( i=1; i<=m; i++)
    {
        c = 1;
        scanf("%d%d%d",&p,&h,&k);       //p表示价格，h表示重量，k表示大米袋数。
        while( k-c>0)
        {
            k -= c;
            lis[++index].w = c*p;
            lis[index].v = c*h;
            c *= 2;
        }
        lis[++index].w = p*k;  //补充不足指数的差值
        lis[index].v = h*k;
    }
    for( i=0; i<=n; i++) dp[i]=0;
    for( i=1; i<=index; i++)   //对拆分后的物品进行0-1背包
    {
        for( j=n; j>=lis[i].w; j--)
            dp[j] = max( dp[j],dp[j-lis[i].w]+lis[i].v);
    }
        printf("%d\n",dp[n]);
    return 0;
