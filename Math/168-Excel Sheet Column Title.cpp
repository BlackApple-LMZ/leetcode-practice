int titleToNumber(string s) {
    int res(0);
    for(auto c:s)
        res = res*26 -'A'+c+1;
    return res;
}
string convertToTitle(int n) {
    string res;
    char tmp;
    while(n){
        n -= 1;
        tmp = 'A' + n % 26;
        res = tmp + res;
        n /= 26;

    }
    return res;
}
