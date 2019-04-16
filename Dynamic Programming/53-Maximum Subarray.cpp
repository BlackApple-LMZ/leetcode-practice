int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int cur = 0;
    int maxarry = -INT_MAX;
    for(int i=0; i<n; i++){
        cur += nums[i];
        maxarry = max(cur, maxarry);
        cur = cur>0 ? cur : 0;
    }
    return maxarry;
}
int maxSubArray1(vector<int>& nums) {
    vector<int> max_add(nums.size());
    max_add[0] = nums[0];
    int result = nums[0];
    for(int i = 1; i < nums.size(); i ++)
    {
        max_add[i] = max_add[i - 1] > 0 ? max_add[i - 1] + nums[i] : nums[i];
        result = max(result, max_add[i]); 
    }
    return result;
}
