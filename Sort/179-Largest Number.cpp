string largestNumber1(vector<int>& nums) {
    vector<string> res;
    bool flag(false);
    for(auto num:nums){
        if(num)
            flag = true;
        res.push_back(to_string(num));
    }
    if(!flag)
        return "0";
    sort(res.begin(), res.end(), [](string a, string b){
        int i=0, j=0, n=a.size(), m=b.size();
        while(i<a.size() && j<b.size()){
            if(a[i%n] < b[j%m])
                return false;
            else if(a[i%n] > b[j%m])
                return true;
            else{
                i++;
                j++;
            }
        }
        return a.size()>b.size();
    });
    string r("");
    for(auto c:res){
        r += c;
        cout << c<<" ";
    }
    return r;
}
string largestNumber(vector<int> &num) {
    vector<string> arr;
    bool flag(false);
    for(auto i:num){
        if(i)
            flag = true;
        arr.push_back(to_string(i));
    }
    if(!flag)
        return "0";
    sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
    string res;
    for(auto s:arr)
        res+=s;
    return  res;
}
