NumArray(vector<int> nums) {
    sum.push_back(0);
    for(int i=1; i<=nums.size(); i++){
        sum.push_back(sum[i-1] + nums[i-1]);
    }
}
vector<int> sum;
int sumRange(int i, int j) {
    return sum[j+1]-sum[i];
}
