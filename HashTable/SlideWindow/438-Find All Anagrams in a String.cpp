vector<int> findAnagrams(string s, string p) {
    vector<int> mark(26,0), mark2(26,0), res;
    if(s.size() < p.size())
       return res;
    for(int i = 0; i < p.size(); ++i){
        ++mark[p[i]-'a'];
        ++mark2[s[i]-'a'];
    }
    if(mark == mark2)
       res.push_back(0);
    for(int i = p.size(); i < s.size(); ++i) 
    {
        ++mark2[s[i]-'a'];
        --mark2[s[i-p.size()]-'a']; 
        if(mark == mark2)  
           res.push_back(i-p.size()+1);
    }
    return res;
}
vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(s.size()<p.size())
        return res;

    vector<int> mark(26,0);
    for(auto x:p)
        mark[x-'a']++;
    int count = p.size();
    for(int begin = 0,end = 0;end <s.size();end++){
        if(end - begin == p.size())
            if(mark[s[begin++]-'a']++>=0)
                count++;
        if(mark[s[end]-'a']-->0)
            count--;
        if(count == 0)
            res.push_back(begin);
    }
    return res;
}
