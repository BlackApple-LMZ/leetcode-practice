vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res; 
    vector<int> temp;
    int sum(0);
    sort(candidates.begin(), candidates.end());
    help(res, candidates, target, temp, sum, 0);

    return res;
}
void help(vector<vector<int>>& res, const vector<int>& candidates, int target, vector<int>& temp, int& sum, int i){

    for(int j=i; j<candidates.size(); j++){
        //if(!i)
            //cout<<sum<<" "<<i<<" "<<candidates[j-1]<<" "<<candidates[j]<<endl;
        //if(!sum && j && candidates[j-1] == candidates[j])
        if(j>i && candidates[j-1] == candidates[j])
            continue ;

        sum += candidates[j];
        temp.push_back(candidates[j]);
        if(sum >= target){
            if(sum == target)
                res.push_back(temp);
            temp.pop_back();
            sum -= candidates[j];
            return;
        }
        help(res, candidates, target, temp, sum, j+1);
        temp.pop_back();
        sum -= candidates[j];
    }

}
