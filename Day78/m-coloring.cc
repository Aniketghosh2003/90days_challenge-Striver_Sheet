bool issafe(int node,vector<vector<int>> &mat ,int n, int col,int color[]){
       for(int k = 0;k < n;k++){
          if(k != node && mat[k][node] == 1 && color[k] == col) return false;
       }
       return true;
}

bool solve(int node,vector<vector<int>> &mat, int m,int n, int color[]){
    if(node == n) return true;

    for(int i = 1;i <= m;i++){
        if(issafe(node,mat,n,i,color)){
            color[node] = i;
            if(solve(node+1,mat,m,n,color)) return true;
            color[i] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
        int n = mat.size();
         int color[n] = {0};

         if(solve(0,mat,m,n,color)) return "YES";
         else return "NO";
}