#include <bits/stdc++.h> 

bool issafe(int i ,int j , int n,vector<vector<int> > &vis,vector<vector<int> > &maze){
          if((i >= 0 && i < n) && (j >= 0 && j < n) && vis[i][j] == 0 && maze[i][j] == 1){
               return true;
               
          }
          else{
            return false;
          }
}

void solve(int i ,int j,int n ,vector<vector<int> > &maze,vector<vector<int> > &ans,vector<vector<int> > &vis){
    if(i == n-1 && j == n-1){
      vector<int > temp;
      vis[i][j] = 1;

      for(int i=0; i<n; i++) {

      for(int j=0; j<n; j++)

      temp.push_back(vis[i][j]);

    }

    vis[i][j] = 0;
    ans.push_back(temp);
    return;
    }

    vis[i][j] = 1;

    int nx = i+1;
    int ny = j;
    if(issafe(nx,ny,n,vis,maze)){
      solve(nx,ny,n,maze,ans,vis);
    }

    nx = i;
     ny = j+1;
    if(issafe(nx,ny,n,vis,maze)){
      solve(nx,ny,n,maze,ans,vis);
    }

      nx = i-1;
   ny = j;
    if(issafe(nx,ny,n,vis,maze)){
      solve(nx,ny,n,maze,ans,vis);
    }

      nx = i;
     ny = j-1;
    if(issafe(nx,ny,n,vis,maze)){
      solve(nx,ny,n,maze,ans,vis);
    }

    vis[i][j] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int> > ans;

  if(maze[0][0] == 0)
      return ans;

  vector<vector<int>> vis(n,vector<int>(n,0));

  solve(0,0,n,maze,ans,vis);

  return ans;

}