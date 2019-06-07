int characterReplacement(string s, int k) {
    vector<int> mark(26, 0);
    int begin(0), end(0);
    int res(0), maxChar(0);

    while(end<s.size()){
        mark[s[end]-'A']++;
        maxChar = max(maxChar, mark[s[end]-'A']);
        end++;
        while(end-begin-maxChar>k){
            mark[s[begin]-'A']--;
            maxChar = *max_element(mark.begin(), mark.end());
            begin++;
        }
        res = max(res, end-begin);
    }
    return res;
}
int characterReplacement4(string s, int k) {
    int n = s.length();
    vector<int> vec(26,0);
    int count = 0, prev = 0;
    for(int i=0; i< s.length(); i++) {
        vec[s[i] - 'A']++;
        count = max(count, vec[s[i] - 'A']);
        if(count+k < i-prev+1) {
            vec[s[prev] - 'A']--;
            prev++;
        }
    }
    return n-prev;
}
