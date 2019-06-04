string getHint1(string secret, string guess) {
    int bull(0), cow(0);
    unordered_map<char, int> hashmap;
    for(int i=0; i<secret.size(); i++){
        if(secret[i] != guess[i]){
            hashmap[secret[i]]++;
        }
        else
            bull++;
    }
    for(int i=0; i<secret.size(); i++){
        if(secret[i] != guess[i]){
            if(hashmap[guess[i]] > 0){
                hashmap[guess[i]]--;
                cow++;
            }
        }
    }
    string res = to_string(bull) + "A" + to_string(cow) + "B";
    return res;
}
string getHint2(string secret, string guess) {
    int aCnt = 0;
    int bCnt = 0;
    vector<int> sVec(10, 0); // 0 ~ 9 for secret
    vector<int> gVec(10, 0); // 0 ~ 9 for guess 
    if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
    for (int i = 0; i < secret.size(); ++i) {
        char c1 = secret[i]; char c2 = guess[i];
        if (c1 == c2) {
            ++aCnt; 
        } else {
            ++sVec[c1-'0'];
            ++gVec[c2-'0'];
        }
    }
    // count b 
    for (int i = 0; i < sVec.size(); ++i) {
        bCnt += min(sVec[i], gVec[i]);
    }
    return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
}
string getHint(string secret, string guess) {
    unordered_map<char, int> s_map;
    unordered_map<char, int> g_map;
    int n = secret.size();
    int A = 0, B = 0;
    for (int i = 0; i < n; i++)
    {
        char s = secret[i], g = guess[i];
        if (s == g)
            A++;
        else
        {
            (s_map[g] > 0) ? s_map[g]--, B++ : g_map[g]++;
            (g_map[s] > 0) ? g_map[s]--, B++ : s_map[s]++; 
        }
    }
    return to_string(A) + "A" + to_string(B) + "B";;
}
