bool PredictTheWinner1(vector<int>& nums) {
    int n=nums.size();
    if(!n)
        return false;
    bool odd = n%2;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        dp[i][i] = nums[i];
    }
    for(int length=2; length<=n; length++){
        for(int i=0; i<=n-length; i++){
            int j=i+length-1;
            if((length%2) ^ odd)
                dp[i][j] = min(dp[i][j-1]-nums[j], dp[i+1][j]-nums[i]);
            else
                dp[i][j] = max(dp[i][j-1]+nums[j], dp[i+1][j]+nums[i]);
            //cout<<dp[i][j]<<endl;
        }
    }
    return dp[0][n-1]>=0;
}
//空间优化到o(n)
bool PredictTheWinner(vector<int>& nums) {
    vector<int> r = nums;
    for (int m = 2; m <= nums.size(); m++) {
        for (int i = 0; i <= nums.size() - m; i++) {
            r[i] = max(nums[i] - r[i + 1], nums[i + m - 1] - r[i]);
        }
    }
    return r[0] >= 0;
}
