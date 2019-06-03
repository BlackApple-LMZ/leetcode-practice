bool wordPattern(string pattern, string str) {
    map<string, char> hash;
    char used[128] = {0};
    string word;
    int pos(0);
    str += ' ';
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            if(pos == pattern.size()){
                return false;
            }

            if(hash.find(word) != hash.end()){
                if(hash[word] != pattern[pos]){
                    return false;
                }
            }
            else{
                if(used[pattern[pos]]){
                    return false;
                }
                hash[word] = pattern[pos];
                used[pattern[pos]] = 1;
            }
            pos++;
            word = "";
        }
        else
            word += str[i];
    }
    if(pos != pattern.size()){
        return false;
    }
    return true;
}
