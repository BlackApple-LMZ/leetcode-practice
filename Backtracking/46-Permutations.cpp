void permutation(vector<int>& nums, int left, int right, vector<vector<int>>& result) {
    if (left == right) {
        result.push_back(nums);
        return ;
    }

    for (int i = left; i <= right; i++) {
        swap(nums[left], nums[i]);
        permutation(nums, left + 1, right, result);
        swap(nums[left], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permutation(nums, 0, nums.size() - 1, result);
    return result;
}
