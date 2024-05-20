#include<bits/stdc++.h>

void bfs(int** arr, int n, int m,int row,int col,vector<vector<int>> &vis){
       vis[row][col] = 1;

       queue<pair<int,int>> q;
       q.push({row,col});

       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();

           for(int drow = -1;drow <= 1;drow++){
               for(int dcol = -1;dcol <= 1;dcol++){
                   int nrow = row + drow;
                   int ncol = col + dcol;

                   if(nrow >=  0 && ncol >= 0&& nrow < n && ncol < m && arr[nrow][ncol] == 1 && 
                        !vis[nrow][ncol]){
                            vis[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
               }
           }
       }
}

int getTotalIslands(int** arr, int n, int m)
{
   int ans = 0;
   vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int row = 0;row < n;row++){
        for(int col = 0;col < m;col++){
            if(!vis[row][col] && arr[row][col] == 1){
                ans++;
                bfs(arr,n,m,row,col,vis);
            }
        }
    }
    return ans;

}
