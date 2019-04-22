int singleNumber1(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++){
        nums[0] ^= nums[i];
    }
    return nums[0];
}
int singleNumber(vector<int>& nums) {
    map<int, int> res;
    for(auto num:nums){
        if(res.find(num) != res.end())
            res.erase(num);
        else
            res.insert(make_pair(num, 1));
    }
    for(auto num:res){
        return num.first;
    }
    return 0;
}
int singleNumber(vector<int>& nums) {
    unordered_set<int> s;
    for(int num : nums)
    {
        if(s.count(num))
            s.erase(num);
        else
            s.insert(num);
    }
    return *s.begin();
}
