vector<int> twoSum1(vector<int>& numbers, int target) {
    vector<int> res(2, 0);
    for(int i=0; i<numbers.size(); i++){
        int j = searchInsert(numbers, target-numbers[i], i+1);
        if(j>0){
            res[0]=i+1;
            res[1]=j+1;
            return res;
        }
    }
    return res;
}
int searchInsert(vector<int>& nums, int target, int be) {
    int begin(be), end(nums.size()-1);
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            begin = mid+1;
        else
            end = mid-1;
    }
    return -1;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int l = 0;
    int r = numbers.size() -1;
    while(l < r){
        if(numbers[l] + numbers[r] == target){
            vector<int> res{l+1,r+1};
            return res;
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
return res;
}
