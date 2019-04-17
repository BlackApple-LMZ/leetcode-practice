vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res; 
    vector<int> temp;
    int sum(0), i(0);
    sort(candidates.begin(), candidates.end());
    help(res, candidates, target, temp, sum, i);

    return res;
}
void help(vector<vector<int>>& res, const vector<int>& candidates, int target, vector<int>& temp, int& sum, int& i){
    cout<<sum<<endl;
    if(sum == target){
        res.push_back(temp);
        return;
    }

    for(int j=i; j<candidates.size(); j++){
        sum += candidates[j];
        temp.push_back(candidates[j]);
        if(sum > target){
            temp.pop_back();
            sum -= candidates[j];
            return;
        }

        help(res, candidates, target, temp, sum, j);
        temp.pop_back();
        sum -= candidates[j];
    }

}
std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int> > res;
    std::vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
}
void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
    if (!target) {
        res.push_back(combination);
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], res, combination, i);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
    vector<vector<int>> res; 
    vector<int> temp;
    int sum(0), i(0);
    //sort(candidates.rbegin(), candidates.rend());
    help1(res, candidates, target, temp, sum, i);

    return res;
}
void help1(vector<vector<int>>& res, const vector<int>& candidates, int target, vector<int>& temp, int& sum, int& i){
    cout<<sum<<endl;
    if(i >= candidates.size() || sum > target)
        return;
    if(sum == target){
        res.push_back(temp);
        return;
    }

    for(int j=i; j<candidates.size(); j++){
        sum += candidates[j];
        temp.push_back(candidates[j]);
        help1(res, candidates, target, temp, sum, j);
        temp.pop_back();
        sum -= candidates[j];
    }

}
