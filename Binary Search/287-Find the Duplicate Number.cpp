int findDuplicate1(vector<int>& nums) {
    unordered_map<int, int> res;
    for(auto num:nums){
        if(++res[num] > 1)
            return num;
    }
    return -1;
}
int findDuplicate2(vector<int>& nums) {
    unordered_set<int> res;
    for(auto num:nums){
        if(res.count(num))
            return num;
        else
            res.insert(num);
    }
    return -1;
}
int findDuplicate3(vector<int>& nums) {
    int slow(0), fast(0);
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    slow = 0;
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}
