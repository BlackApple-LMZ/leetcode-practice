int climbStairs1(int n) {
    vector<int> dp(n+1, 1);
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int climbStairs(int n) {
    int pre(1), prepre(1), cur(1);
    for(int i=2; i<=n; i++){
        cur = pre + prepre;
        prepre = pre;
        pre = cur;
    }
    return cur;
}
