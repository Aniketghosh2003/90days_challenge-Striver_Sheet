class DisjointSet{
    vector<int> parent , size;

    public:
       DisjointSet(int n){
           size.resize(n+1,1);
           parent.resize(n+1);
           for(int i = 0;i < n;i++){
               parent[i] = i;
           }
       }

    int findulti_par(int node){
        if(node ==parent[node] )
             return  node;
        else  parent[node] = findulti_par(parent[node]) ;   
    }

    void unionbysize(int u,int v){
        int ulp_u = findulti_par(u);
        int ulp_v = findulti_par(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int,pair<int,int>>> adj;

    for(auto& it:edges){
            int  u= it[0];
            int wt = it[2];
            int v = it[1];

            adj.push_back({wt,{u,v}}); 
        }

        int min_wt = 0;

        sort(adj.begin(),adj.end());
         
         DisjointSet dis(n);
        for(auto& it:adj){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;

           if(dis.findulti_par(u) != dis.findulti_par(v)){
               min_wt += wt;
               dis.unionbysize(u,v);
           }
        }
        return min_wt;
}
