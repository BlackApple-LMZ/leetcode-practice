void setZeroes1(vector<vector<int>>& matrix) {
    int m(matrix.size()), n(matrix[0].size());
    int ms[m]={0}, ns[n]={0};

    for(int i=0; i<m; i++){
        //if(ms[i]) continue;
        for(int j=0; j<n; j++){
            //cout<<matrix[i][j]<<endl;
            if(matrix[i][j]==0){
                ms[i]=1;
                ns[j]=1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(ns[j] || ms[i]) 
                matrix[i][j]=0;
        }
    }
}
void setZeroes(vector<vector<int>>& matrix){
    bool isCol = false;
    int R = matrix.size();
    int C = matrix[0].size();

    for (int i = 0; i < R; i++) {
        if (matrix[i][0] == 0) {
            isCol = true;
        }

        for (int j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < C; j++) {
            matrix[0][j] = 0;
        }
    }

    if (isCol) {
        for (int i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
}
