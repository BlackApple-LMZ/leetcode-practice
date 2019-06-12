//自己写的垃圾代码：
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    if(intervals.empty() || intervals[0].empty()){
        res.push_back(newInterval);
        return res;
    }

    int minl(newInterval[0]), maxr(newInterval[1]);
    bool end(false);
    for(int i=0; i<intervals.size(); i++){
        if(end){
            res.push_back({intervals[i][0], intervals[i][1]});
            continue;
        }
        if(minl>intervals[i][1]){
            res.push_back({intervals[i][0], intervals[i][1]});
            if(i==intervals.size()-1)
                res.push_back({minl, maxr});
        }
        else if(minl<intervals[i][0]){
            if(maxr<intervals[i][0]){
                res.push_back({minl, maxr}); //先等一等
                res.push_back({intervals[i][0], intervals[i][1]});
                end = true;
            }
            else if(maxr>intervals[i][1]){
                if(i==intervals.size()-1)
                    res.push_back({minl, maxr});
                continue;
            }

            else {
                res.push_back({minl, intervals[i][1]});
                end = true;
            }
        }
        else{
            if(maxr<=intervals[i][1]){
                res.push_back({intervals[i][0], intervals[i][1]});
                end = true;
            }
            else {
                minl = intervals[i][0];
                if(i==intervals.size()-1)
                    res.push_back({minl, maxr});
            }
        }

    }
    return res;
}
//大佬们如此简洁又易懂的代码 差距啊
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    int index = 0;
    while(index < intervals.size() && intervals[index].end < newInterval.start){
        res.push_back(intervals[index++]);
    }
    while(index < intervals.size() && intervals[index].start <= newInterval.end){
        newInterval.start = min(newInterval.start, intervals[index].start);
        newInterval.end = max(newInterval.end, intervals[index].end);
        index++;
    }
    res.push_back(newInterval);
    while(index < intervals.size()){
        res.push_back(intervals[index++]);
    }
    return res;
}
