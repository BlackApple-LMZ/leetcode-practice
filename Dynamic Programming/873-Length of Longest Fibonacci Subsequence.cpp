int lenLongestFibSubseq(vector<int>& A) {
    if(A.size()<3)
        return 0;
    int n = A.size();
    unordered_map<int, int> hash;
    for(int i=0; i<n; i++){
        hash[A[i]] = i;
    }
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[j]-A[i] < A[i] && hash.count(A[j]-A[i])){
                dp[i][j] = dp[hash[A[j]-A[i]]][i] + 1;
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 2;
        }
    }
    return res;
}


int lenLongestFibSubseq1(vector<int>& A) {
    int N = A.size();
    unordered_map<int, int> index;
    for (int i = 0; i < N; ++i)
        index[A[i]] = i;

    unordered_map<int, int> longest;
    int ans = 0;
    for (int k = 0; k < N; ++k)
        for (int j = 0; j < k; ++j) {
            if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                int i = index[A[k] - A[j]];
                longest[j * N + k] = longest[i * N + j] + 1;
                ans = max(ans, longest[j * N + k] + 2);
            }
        }

    return ans >= 3 ? ans : 0;
}
