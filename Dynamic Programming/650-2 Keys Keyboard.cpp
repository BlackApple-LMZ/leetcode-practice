int minSteps(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;
    for(int i=2; i<=n; i++){
//            for (int j = i/2; j >= 2 && i % j == 0; --j)
//                dp[i] = min(dp[i], i/j + dp[j]);
        for(int j=1; j<=i/2; j++){
            if(!(i%j)){
                dp[i] = min(dp[i], i/j + dp[j]);
            }

        }
    }
    return dp[n];
}
int minSteps1(int n) {
    int s = 0;
    for (int d = 2; d <= n; d++) {
        while (n % d == 0) {
            s += d;
            n /= d;
        }
    }
    return s;
}
