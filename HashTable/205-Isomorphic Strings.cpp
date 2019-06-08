bool isIsomorphic(string s, string t) {
    char hash[128]= {0};
    char hash2[128]= {0};
    if(s.size() != t.size())
        return false;
    for(int i=0; i<s.size(); i++){
        if(hash[s[i]]){
            if(hash[s[i]] != t[i])
                return false;
        }

        else{
            if(hash2[t[i]])
                return false;
            hash[s[i]] = t[i];
            hash2[t[i]] = s[i];
        }

    }
    return true;
}

/*char map_s[128] = { 0 };
    char map_t[128] = { 0 };
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (map_s[s[i]]!=map_t[t[i]]) return false;
        map_s[s[i]] = i+1;
        map_t[t[i]] = i+1;
    }
    return true;  */
