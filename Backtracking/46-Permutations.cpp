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
//方法二 加一个used数组来判断
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    vector<int> used(nums.size(), 0);
    help(nums, res, temp, used);
    return res;
}

void help(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<int>& used){
    if(temp.size() == nums.size()){
        res.push_back(temp);
        return ;
    }
    for(int i=0; i<nums.size(); i++){
        if(!used[i]){
            cout<<i<<" ";
            used[i] = 1;
            temp.push_back(nums[i]);
            help(nums, res, temp, used);
            used[i] = 0;
            cout<<i<<" ";
            temp.pop_back();
        }
    }
}
