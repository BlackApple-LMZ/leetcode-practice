int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());

    int begin(0), end(citations.size()-1), num(citations.size()-1);
    int res(0);
    while(begin<=end){
        int mid = (begin+end)/2;
        int length = num-mid+1;
        if(length == citations[mid])
            return length;
        else if(length > citations[mid]){
            begin = mid+1;
            res = max(res, citations[mid]);
        }
        else{
            end = mid-1;
            res = max(res, length);
        }

    }
    return res;
}
