int findMaxLength1(vector<int>& nums) {
    vector<int> sum(nums.size()+1, 0);
    int length(0);
    for(int i=0; i<nums.size(); i++){
        if(nums[i]<1)
            sum[i+1] = sum[i] - 1;
        else
            sum[i+1] = sum[i] + nums[i];

        for(int j=0; j<i; j++){
            if(sum[i+1]-sum[j] == 0){
                length = max(length, i-j+1);
                break;
            }
        }

    }
    return length;
}
int findMaxLength2(vector<int>& nums) {
    map<int, int> map;
    map[0] = -1;
    int maxlen = 0, count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count = count + (nums[i] == 1 ? 1 : -1);
        if (map.count(count)) {
            maxlen = max(maxlen, i - map[count]);
        } 
        else {
            map[count] = i;
        }
    }
    return maxlen;
}
int findMaxLength(vector<int>& nums) {
    int size = nums.size(), ballance = size, max_len = 0;
    int ballances[size * 2 + 1] = {};
    for (auto i = 0; i < size; ++i) {
        ballance += nums[i] == 0 ? -1 : 1;
        if (ballance == size) max_len = i + 1;
        else {
            if (ballances[ballance] != 0) max_len = max(max_len, i - ballances[ballance] + 1);
            else ballances[ballance] = i + 1;
        }
    }
    return max_len;
}
