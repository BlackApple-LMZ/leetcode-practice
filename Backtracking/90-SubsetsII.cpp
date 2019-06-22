vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> check;
    vector<vector<int>> result;
    vector<int> temp; 
    help1(0, nums, temp, check);
    //cout<<check.size()<<endl;
    for(auto num:check)
        result.push_back(num);
    return result;
}
void help1(int i, vector<int>& nums, vector<int> temp, set<vector<int>>& result){
    if(i == nums.size()){
        if(result.find(temp) == result.end())
            result.insert(temp);
        return ;
    }
    help1(i+1, nums, temp, result);

    temp.push_back(nums[i]);
    help1(i+1, nums, temp, result);
    return ;        
}
vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> temp; 
    help(0, nums, temp, result);
    return result;
}
void help(int i, vector<int>& nums, vector<int> temp, vector<vector<int>>& result){
    if(i == nums.size()){
        result.push_back(temp);
        return ;
    }
    int j=i;
    while(j<nums.size() && nums[j]==nums[i]) j++;
    help(j, nums, temp, result);
    for(int k=0; k<j-i; k++){
        temp.push_back(nums[i]);
        help(j, nums, temp, result);
    }
    return ;        
}
vector<vector<int> > subsetsWithDup3(vector<int> &S) {
    vector<vector<int> > totalset = {{}};
    sort(S.begin(),S.end());
    for(int i=0; i<S.size();){
        int count = 0; // num of elements are the same
        while(count + i<S.size() && S[count+i]==S[i])  count++;
        int previousN = totalset.size();
        for(int k=0; k<previousN; k++){
            vector<int> instance = totalset[k];
            for(int j=0; j<count; j++){
                instance.push_back(S[i]);
                totalset.push_back(instance);
            }
        }
        i += count;
    }
    return totalset;
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   vector<vector<int>> result;
   vector<int> subset;
   sort(nums.begin(),nums.end());
   subsetUtil(result,subset,0,nums); 
    return result;

}

void subsetUtil(vector<vector<int>> &result,vector<int> &subset,int start, vector<int> nums){
    result.push_back(subset);
    for(int i=start;i<nums.size();i++){
        if(i!=start && nums[i-1]==nums[i])
            continue;
        subset.push_back(nums[i]);
        subsetUtil(result,subset,i+1,nums);
        subset.pop_back();
    }
}
