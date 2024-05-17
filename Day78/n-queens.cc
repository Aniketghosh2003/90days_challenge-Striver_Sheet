 // bool ifsafe(int row,int col,vector<vector<int>> &board,int n){
//        int drow = row;
//        int dcol = col;

//        while(row >= 0 && col >= 0){
//            if(board[row][col] == 1) return  false;
//            col--;
//            row--;
//        }

//        row = drow;
//        col = dcol;

//        while(col >= 0){
//            if(board[row][col] == 1) return  false;
//            col--;
//        }

//        row = drow;
//        col = dcol;

//        while (row < n && col >= 0) {
//            if (board[row][col] == 1)
//              return false;
//            col--;
//            row++;
//        }

//        return true;
// }

// void solve(int col,vector<vector<int>>& ans,vector<vector<int>> &board,int n){
//     if(col == n) {
//         vector<int> temp;
//         for(int i = 0;i < n;i++){
//             for(int j = 0;j < n;j++){
//                 temp.push_back(board[i][j]);
//             }
//         }
//         ans.push_back(temp);
//         return;
//     }

//     for(int row = 0;row < n;row ++){
//         if(ifsafe(row,col,board,n)){
//             board[row][col] = 1;
//             solve(col+1, ans, board, n);
//             board[row][col] = 0;
//         }
//     }
// }


void solve(int col ,int n, vector<vector<int>> &ans , vector<vector<int>> &board,
                vector<int> &leftrow,vector<int> &upperrow, vector<int> &lowerrow){

        if(col == n) {
        vector<int> temp;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }  
    for(int row = 0;row < n;row ++){
        if((leftrow[row] == 0) && (upperrow[(n-1)+col-row] == 0) && (lowerrow[row+col] == 0)){
            leftrow[row] = 1;
            upperrow[(n-1)+col-row] = 1;
            lowerrow[row+col] = 1;
            board[row][col] = 1;
             solve(col+1,n,ans,board,leftrow,upperrow,lowerrow);
            board[row][col] = 0;
            leftrow[row] = 0;
            upperrow[(n-1)+col-row] = 0;
            lowerrow[row+col] = 0;
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
     vector<vector<int>> ans;
     vector<vector<int>> board(n,vector<int>(n,0));


     vector<int> leftrow(n,0);
     vector<int> upperrow(2*n-1,0);
     vector<int> lowerrow(2*n-1,0);
     solve(0,n,ans,board,leftrow,upperrow,lowerrow);
     return ans;
}