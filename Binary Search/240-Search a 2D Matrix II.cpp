bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m=matrix.size(), n=matrix[0].size();
    if(m<n){
        for(int i=0; i<m; i++){
            int end = n-1, begin = 0;
            while(begin<=end){
                int mid = (begin+end)/2;
                if(target == matrix[i][mid])
                    return true;
                else if(target > matrix[i][mid])
                    begin = mid+1;
                else
                    end = mid-1;
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            int begin(0), end(m-1);
            while(begin<=end){
                int mid = (begin+end)/2;
                if(target == matrix[mid][i])
                    return true;
                else if(target > matrix[mid][i])
                    begin = mid+1;
                else
                    end = mid-1;
            }
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m=matrix.size(), n=matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }

    return false;
}
