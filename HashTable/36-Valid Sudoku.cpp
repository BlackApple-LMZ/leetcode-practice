bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char, vector<int>> hashmap;
    if(board.size()!=9 || board[0].size()!=9)
        return false;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<9; j++){
            char c = board[i][j];
            if(c>='1' && c<='9'){
                int temp = hashF(i, j);
                if(count(hashmap[c].begin(), hashmap[c].end(), i+1) || count(hashmap[c].begin(), hashmap[c].end(), j+10) || count(hashmap[c].begin(), hashmap[c].end(), temp)){
                    return false;
                }
                else{
                    hashmap[c].push_back(i+1);
                    hashmap[c].push_back(j+10);
                    hashmap[c].push_back(temp);
                }
            }
        }
    }
    return true;
}
int hashF(int i, int j){
    return (i/3+7)*(j/3+3);
}
bool isValidSudoku(vector<vector<char> > &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }

    return true;
}
