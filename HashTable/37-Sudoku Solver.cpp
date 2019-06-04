int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
void solveSudoku(vector<vector<char>>& board) {
    queue<pair<int, int>> res;
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
            else{
                res.push(pair{i, j});
                //cout<<i<<" "<<j<<endl;
            }
    help(board, res);
}
bool help(vector<vector<char>>& board, queue<pair<int, int>> res) {
    if(res.empty())
        return true;

    pair<int, int> now = res.front();
    res.pop();
    int i=now.first, j=now.second;
    int k=i/3 * 3+j/3;
    for(int num=0; num<9; num++){
        if(used1[i][num] || used2[j][num] || used3[k][num])
            continue;

        used1[i][num] = used2[j][num] = used3[k][num] = 1;
        board[i][j] = '0' + 1 + num;
        //cout<<i<<" "<<j<<" "<<num+1<<endl;
        if(help(board, res))
            return true;

        used1[i][num] = used2[j][num] = used3[k][num] = 0;
        board[i][j] = '.';
    }  
    return false;
}
//取消queue 直接传递ij 快了很多
int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
void solveSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
    help(board, 0, 0);
}
bool help(vector<vector<char>>& board, int i, int j) {
    if(i==9) return true;
    if(j==9) return help(board, i+1, 0);
    if(board[i][j] != '.') return help(board, i, j+1);

    int k=i/3 * 3+j/3;
    for(int num=0; num<9; num++){
        if(used1[i][num] || used2[j][num] || used3[k][num])
            continue;

        used1[i][num] = used2[j][num] = used3[k][num] = 1;
        board[i][j] = '0' + 1 + num;
        //cout<<i<<" "<<j<<" "<<num+1<<endl;
        if(help(board, i, j+1))
            return true;

        used1[i][num] = used2[j][num] = used3[k][num] = 0;
        board[i][j] = '.';
    }  
    return false;
}
