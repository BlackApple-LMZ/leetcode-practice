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
  
  //优化成一维dp
  int backPack(int m, vector<int> &A) {
    vector<vector<int>> dp(A.size()+1, vector<int>(m+1, 0));
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
