std::vector<std::vector<std::string> > solveNQueens(int n) {
    std::vector<std::vector<std::string> > res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    solveNQueens(res, nQueens, 0, n);
    return res;
}
void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
    if (row == n) {
        res.push_back(nQueens);
        return;
    }
    for (int col = 0; col != n; ++col)
        if (isValid(nQueens, row, col, n)) {
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, row + 1, n);
            nQueens[row][col] = '.';
        }
}
bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
    //check if the column had a queen before.
    for (int i = 0; i != row; ++i)
        if (nQueens[i][col] == 'Q')
            return false;
    //check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (nQueens[i][j] == 'Q')
            return false;
    //check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (nQueens[i][j] == 'Q')
            return false;
    return true;
}

//方法二：
vector<vector<string>> solveNQueens2(int n) {
    vector<vector<string>> result;
    vector<vector<int>> mark;
    vector<string> location;
    for(int i=0; i<n; i++){
        mark.push_back(vector<int>());
        for(int j=0; j<n; j++){
            mark[i].push_back(0);
        }
        location.push_back("");
        location[i].append(n, '.');
    }
    help(0, n, mark, result, location);
    return result;
};
void help(int k, int n, vector<vector<int>>& mark, vector<vector<string>>& result, vector<string>& location){
    if(k == n){
        result.push_back(location);
        return ;
    }

    for(int i=0; i<n; i++){
        if(mark[k][i] == 0){
            vector<vector<int>> temp = mark;//记录
            location[k][i] = 'Q'; //更新显示
            put_down_the_queen(k, i, mark);
            help(k+1, n, mark, result, location);
            mark = temp;
            location[k][i] = '.';
        }
    }
};
void put_down_the_queen(int x, int y, vector<vector<int>>& mark){
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    mark[x][y] == 1;

    for(int i=0; i<mark.size(); i++){
        for(int j=0; j<8; j++){
            int new_x = x + dx[j]*i;
            int new_y = y + dy[j]*i;
            if(new_x>=0 && new_x<mark.size() && new_y>=0 && new_y<mark.size())
                mark[new_x][new_y] = 1;
        }
    }
}
