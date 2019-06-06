bool containsNearbyDuplicate2(vector<int>& nums, int k) {
    unordered_map<int,int> mark;
    for(int i=0;i<nums.size();i++){
        if(i>k)             //处理超出滑动窗的元素
            mark[nums[i-k-1]]--;   
      //注意这里的下标为i-k-1,也可以将这句放在最后面，不过那样的话下标要改成i-k了
        mark[nums[i]]++;
        if(mark[nums[i]]>1)
            return true;
    }
    return false;
}
bool containsNearbyDuplicate1(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for(int i=0; i<nums.size(); i++){
        if(hash.count(nums[i]) && (i-hash[nums[i]])<=k){
            return true;
        }
        else
            hash[nums[i]] = i;
    }
    return false;
}
