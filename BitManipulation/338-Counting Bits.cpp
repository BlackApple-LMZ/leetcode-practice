vector<int> countBits1(int num) {
    vector<int> dp(num+1, 0);
    int k(0);
    for(int i=1; i<=num; i++){
        int n=1<<k, n1=n<<1;
        if(i>=n1){
            k++;
            n=n1;
        }
        dp[i] = 1+dp[i-n];
    }
    return dp;
}
vector<int> countBits(int num) {
    vector<int> ret(num+1, 0);
    for (int i = 1; i <= num; ++i)
        ret[i] = ret[i&(i-1)] + 1;
    return ret;
}
