#include <bits/stdc++.h> 

void dfs(int node, vector<bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
       vis[node] = true;
       for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
        }
       }
       st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>> adj;
    for(int i = 0;i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);

    }

    vector<bool> vis(v,false);
    stack<int> st;
    for(int i= 0;i < v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}