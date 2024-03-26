bool searchMatrix(vector<vector<int>>& mat, int target) {
        // for(int i = 0 ;i < mat.size();i++){
        //     for(int j = 0;j < mat[i].size();j++){
        //         if(mat[i][j] == target)
        //              return true;
        //     }
        // }
        // return false;

        int m = mat.size();
        int n  = mat[0].size();

        int low = 0;
        int high = m*n - 1;
        int mid,row,col;

        while(low <= high){
            mid = (low+high)/2;

            row = mid / n;
            col = mid % n;

            if(mat[row][col] > target){
                 high = mid - 1;
            }
            else if(mat[row][col] < target){
                   low = mid+1;
            }
            else if(mat[row][col] == target){
                return true;
            }
        }
        return false;
