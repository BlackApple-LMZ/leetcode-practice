bool canPartition1(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2)
        return false;
    sum /= 2;
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i=0; i<nums.size(); i++){
        for(int j=sum; j>=nums[i]; j--)
            dp[j] = max(dp[j], dp[j-nums[i]]);
    }
    return dp[sum];
}
bool canPartition2(vector<int>& nums) {
    bitset<5001> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (auto n : nums) bits |= bits << n;
    return !(sum & 1) && bits[sum >> 1];
}
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
    if (sum & 1) return false;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(auto num : nums) 
        for(int i = target; i >= num; i--)
            dp[i] = dp[i] || dp[i - num];
    return dp[target];
}
