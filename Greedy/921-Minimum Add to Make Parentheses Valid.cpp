int minAddToMakeValid(string S) {
    vector<char> res;
    for(auto c:S){
        if(res.empty()){
            res.push_back(c);
        }
        else{
            if(res.back() == '(' && c == ')')
                res.pop_back();
            else
                res.push_back(c);
        }
    }
    return res.size();
}
int minAddToMakeValid(string S) {
    int left(0), right(0);
    for(auto c:S){

        if(c == '(')
            left++;
        else{
            left--;
            if(left<0){
                left = 0;
                right++;
            }
        }
    }
    return left+right;
}
