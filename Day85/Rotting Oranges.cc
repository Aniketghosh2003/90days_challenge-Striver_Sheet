#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)

{

    queue<pair<pair<int,int>,int>>q;

    int vis[n][m];

    int cntfresh = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(grid[i][j] == 2){

                q.push({{i,j},0});

                vis[i][j] = 1;

            }

            else{

                vis[i][j] = 0;

            }

            if(grid[i][j] == 1)cntfresh++;

        }

    }

 

    int cnt = 0;

    int dr[4] = {-1,0,1,0};

    int dc[4] = {0,1,0,-1};

    int tm = 0;

    while(!q.empty()){

        int r = q.front().first.first;

        int c = q.front().first.second;

        int t = q.front().second;

        tm = max(t,tm);

        q.pop();

       for(int i=0;i<4;i++){

           int nrow = r+dr[i];

           int ncol = c+dc[i];

           if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){

                q.push({{nrow, ncol}, t + 1});

                vis[nrow][ncol] = 1;

                cnt++;

           }

       }

    }

    if(cntfresh != cnt)return -1;

    return tm;

}

 