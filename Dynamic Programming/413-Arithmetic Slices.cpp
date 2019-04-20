int numberOfArithmeticSlices1(vector<int>& A) {
    if(A.size()<3)
        return 0;
    int n = A.size();
    int res(0);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n-2; i++){
        if((A[i+2]-A[i+1]) == (A[i+1]-A[i])){
            dp[i][i+2] = 1;
            res++;
        }
    }
    for(int length=4; length<=n; length++){
        for(int j=0; j<=n-length; j++){
            int i = j+length-1;
            if(dp[j][i-1] && (A[i]-A[i-1] == A[i-1]-A[i-2])){
                dp[j][i] = 1;
                res++;
            }
        }
    }
    return res;
}
int numberOfArithmeticSlices2(vector<int>& A) {
    if(A.size()<3)
        return 0;
    int n = A.size();
    int res(0);
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++){
        for(int j=i+2; j<n; j++){
            if(A[j]-A[j-1] == A[j-1]-A[j-2]){
                dp[j] = dp[j-1] + j-i-1;
                if(j == n-1)
                    return res + dp[j];
            }
            else{
                i = j-2;
                res += dp[j-1];
                break;
            }
        }
    }
    return res;
}
int numberOfArithmeticSlices(vector<int>& A) {
    int count = 0;
    int addend = 0;

    for (int i = 2; i < A.size(); i++)
        if (A[i - 1] - A[i] == A[i - 2] - A[i - 1])
            count += ++addend;
        else 
            addend = 0;

    return count;
}
