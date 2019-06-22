int missingNumber0(vector<int>& nums) {
    int n=nums.size();
    int sum = n*(n+1)/2;
    for(auto n:nums)
        sum -= n;
    return sum;
}
int missingNumber1(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        result += (i+1)-nums[i];
    }
    return result;
}
int missingNumber(vector<int>& nums) {
    int res=nums.size();
    for(int i=0; i<nums.size(); i++){
        res = res^i^nums[i];
    }
    return res;
}
