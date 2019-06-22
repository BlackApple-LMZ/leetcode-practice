vector<int> singleNumber1(vector<int>& nums) {
    unordered_map<int, int> hash;
    for(auto n:nums){
        hash[n]++;
    }
    vector<int> res;
    for(auto n:hash){
        if(n.second==1)
            res.push_back(n.first);
    }
    return res;
}
vector<int> singleNumber(vector<int>& nums) 
{
    // Pass 1 : 
    // Get the XOR of the two numbers we need to find
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    // Get its last set bit
    diff &= -diff;

    // Pass 2 :
    vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
    for (int num : nums)
    {
        if ((num & diff) == 0) // the bit is not set
        {
            rets[0] ^= num;
        }
        else // the bit is set
        {
            rets[1] ^= num;
        }
    }
    return rets;
}
