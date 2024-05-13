void dfs(vector<int>& vis, vector<int> g[], int node, vector<int>& temp) {
    vis[node] = 1;
    temp.push_back(node);
    for(auto child : g[node]) {
        if(!vis[child]) {
            dfs(vis, g, child, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> g[V];
    
    for(int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
   
    vector<vector<int>> res;
    vector<int> vis(V, 0);
   
    for(int i = 0; i < V; ++i) {
        if (!vis[i]) {
            vector<int> temp;
            dfs(vis, g, i, temp);
            res.push_back(temp);
        }
    }
    return res;
    
}