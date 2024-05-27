bool dfs(int start,int color,vector<int> adj[],vector<int> &vis){
	vis[start] = color;
	for(auto it:adj[start]){
		if(vis[it] == -1){
			if(dfs(it,!color,adj,vis) == false){
				return false;
			}
		}
		else if(vis[it] == color){
			return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	  int n=edges.size();

    int m=edges[0].size();

    vector<int>adj[n];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

                        if (edges[i][j] == 1) {

                                adj[i].push_back(j);
                        }
        }
    }
      vector<int> vis(n,-1);
	  for(int i =0;i < n;i++){
		 if(vis[i] == -1){
			  if(dfs(i,0,adj,vis) == false)
		     return false;
		 }
	  }

	  return true;
}