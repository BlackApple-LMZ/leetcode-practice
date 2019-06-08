string frequencySort(string s) {
    int table[128] = {0};
    for(auto c:s){
        table[c]++;
    }
    vector<pair<int, char>> res;
    for(int i=0; i<128; i++){
        if(table[i])
            res.push_back(make_pair(table[i], (char)i));
    }
    sort(res.rbegin(), res.rend());
    string temp("");
    for(auto c:res){
        while(c.first>0){
            temp += c.second;
            c.first--;
        }
    }
    return temp;
}
// 重写sort
string frequencySort(string s) {
    int counts[256] = {0};
    for (char ch : s)
        ++counts[ch];
    sort(s.begin(), s.end(), [&](char a, char b) { 
        return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
    });
    return s;
}
string frequencySort(string s) {
    unordered_map<char,int> freq;
    vector<string> bucket(s.size()+1, "");
    string res;

    //count frequency of each character
    for(char c:s) freq[c]++;
    //put character into frequency bucket
    for(auto& it:freq) {
        int n = it.second;
        char c = it.first;
        bucket[n].append(n, c);
    }
    //form descending sorted string
    for(int i=s.size(); i>0; i--) {
        if(!bucket[i].empty())
            res.append(bucket[i]);
    }
    return res;
}
