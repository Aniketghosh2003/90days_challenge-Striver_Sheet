#include<bits/stdc++.h>

bool iscyclic(unordered_map<int , set<int> > &adj, unordered_map<int , bool> &visited, int node)

{

unordered_map<int , int> parent;

parent[node]= -1;

visited[node]=1;

queue<int > q;

q.push(node);

while(!q.empty())

{

int frontnode= q.front();

q.pop();

for(auto i:adj[frontnode])

{

if(visited[i]== true && i!= parent[frontnode])

{

return true;

}

else if (!visited[i])

{

q.push(i);

visited[i] = true;

parent[i] = frontnode;

}

}

}

return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)

{

unordered_map<int , set<int> > adj;

for(int i = 0 ;i<m;i++)

{

int u=edges[i][0];

int v= edges[i][1];

 

adj[u].insert(v);

adj[v].insert(u);

}

unordered_map<int,bool> visited;

for(int i =0;i<n;i++)

{

if(!visited[i])

{

bool ans= iscyclic(adj, visited,i);

if(ans==true)

return "Yes";

}

}

return "No";

}

 
