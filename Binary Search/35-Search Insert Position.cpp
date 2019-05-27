int searchInsert1(vector<int>& nums, int target) {
    int begin(0), end(nums.size()-1);
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            begin = mid+1;
        else
            end = mid-1;
    }
    return begin;
}
int searchInsert(vector<int>& nums, int target) {
    return help(nums, target, 0, nums.size()-1);
}
int help(vector<int>& nums, int target, int l, int r){
    if(l>r)
        return l;
    int mid = (l+r)/2;
    if(target == nums[mid])
        return mid;
    else if(target > nums[mid])
        return help(nums, target, mid+1, r);
    else
        return help(nums, target, l, mid-1);
}
