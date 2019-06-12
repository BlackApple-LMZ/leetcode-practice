void sortColors1(vector<int>& nums) {
    int color[3] = {0};
    for(auto num:nums){
        color[num]++;
    }
    for(int i=0; i<nums.size(); i++){
        nums[i] = color[0]-- > 0 ? 0 : (color[1]-- > 0 ? 1 : 2);
    }
    return ;
}
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int j = 0, k = n-1;
    for (int i=0; i <= k; i++) {
        if (nums[i] == 0)
            swap(nums[i], nums[j++]);
        else if (nums[i] == 2)
            swap(nums[i--], nums[k--]);
    }
}
