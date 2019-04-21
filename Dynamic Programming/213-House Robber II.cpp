int rob(vector<int>& nums) {
    int n=nums.size();
    if(n<1)
        return 0;
    if(n<2)
        return nums[0];

    vector<int> dp1(n, 0);
    dp1[1] = nums[0];
    for(int i=2; i<n; i++){
        dp1[i] = max(dp1[i-2]+nums[i-1], dp1[i-1]);
    }

    vector<int> dp2(n, 0);
    dp2[1] = nums[1];
    for(int i=3; i<=n; i++){
        dp2[i-1] = max(dp2[i-3]+nums[i-1], dp2[i-2]);
    }
    return max(dp1[n-1], dp2[n-1]);
}
