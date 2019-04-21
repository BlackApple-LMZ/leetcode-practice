int nthUglyNumber1(int n) {
    if(!n)
        return 0;
    int i(1), count(0);
    while(count<n){
        int temp = i;
        for (int d = 2; d <= 5; d++) {
            while (temp % d == 0) {
                temp /= d;
            }
        }
        if(temp==1)
            count++;
        i++;
    }
    return i-1;
}
int nthUglyNumber(int n) {
    vector<int> dp(n+1, 0);

    dp[1] = 1;
    int i2(1), i3(1), i5(1);
    for(int i=2; i<=n; i++){
        dp[i] = min(2*dp[i2], min(3*dp[i3], 5*dp[i5]));

        if(dp[i] == 2*dp[i2]) 
            i2++;
        if(dp[i] == 3*dp[i3]) 
            i3++;
        if(dp[i] == 5*dp[i5]) 
            i5++;
    }
    return dp[n];
}
