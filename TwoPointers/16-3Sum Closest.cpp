int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<3)
        return -1;
    sort(nums.begin(), nums.end());
    int left(0), right(nums.size()-1);
    int sum(0), mintar(INT_MAX); 
    for(int i=0; i<nums.size()-2; i++){
        left = i+1;
        right = nums.size()-1;
        int tar = target-nums[i];
        while(left<right){
            int temp = nums[left]+nums[right];
            if(abs(tar-temp)<mintar){
                mintar = abs(tar-temp);
                sum = temp + nums[i];
                //cout<<mintar<<" "<<i<<" "<<left<<" "<<right<<endl;
            }
            //cout<<i<<" "<<left<<" "<<right<<" "<<mintar<<" "<<endl;
            if(temp > tar)
                right--;
            else if(temp < tar)
                left++;
            else
                return target;
        }
    }
    return sum;
}
