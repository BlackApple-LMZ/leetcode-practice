map<char, vector<char>> table;
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.empty()){
        return res;
    }
    buildTable();
    string temp("");
    help(digits, res, temp);
    return res;
}
void help(string digits, vector<string>& res, string& temp){
    if(digits.empty()){
       res.push_back(temp);
        return ;
    }
    for(int i=0; i<table[digits[0]].size(); i++){
        temp += table[digits[0]][i];
        help(digits.substr(1), res, temp);
        temp.pop_back();
    }
}
void buildTable(){
    char a='2', b='a';
    for(int i=2; i<10; i++){
        vector<char> temp;
        temp.push_back(b++);
        temp.push_back(b++);
        temp.push_back(b++);
        if(i==7 || i==9)
            temp.push_back(b++);
        table[a++] = temp;
    }
}
