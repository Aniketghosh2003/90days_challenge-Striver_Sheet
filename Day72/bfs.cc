vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    vector<int> vis(n+1,0);
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    

    while(!q.empty()){
         int curr = q.front();
         q.pop();
         ans.push_back(curr);

         for(auto i: adj[curr]){
             if(vis[i] != 1){
                 vis[i] = 1;
                 q.push(i);
             }
         }

    }
    return ans;
}