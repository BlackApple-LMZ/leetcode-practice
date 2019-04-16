int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty() || obstacleGrid[0].empty())
        return 0;
    int m = obstacleGrid[0].size();
    int n = obstacleGrid.size();
    vector<long int> dp_pre(m+1, 0);
    for(int i=1; i<=m; i++){
        if(obstacleGrid[0][i-1] == 0)
            dp_pre[i] = 1;
        else
            break;
    }
    vector<long int> dp_cur = dp_pre;

    for(int i=1; i<n; i++){
        for(int j=1; j<=m; j++){
            if(obstacleGrid[i][j-1])
                dp_cur[j] = 0;
            else
                dp_cur[j] = dp_cur[j-1] + dp_pre[j];
        }
        dp_pre = dp_cur;
    }
    return dp_cur[m];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int M = obstacleGrid.size(), N = obstacleGrid[0].size(); 
    vector<vector<long int>> dp(M + 1, vector<long int>(N + 1, 0)); 
    if (obstacleGrid[0][0] != 1) 
        dp[1][1] = 1; 
    for (int i = 1; i < M + 1; ++i) { 
        for (int j = 1; j < N + 1; ++j) { 
            if (i == 1 && j == 1) 
                continue; 
            if (obstacleGrid[i - 1][j - 1] != 1) 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
        } 
    } 
    return dp[M][N];
}
