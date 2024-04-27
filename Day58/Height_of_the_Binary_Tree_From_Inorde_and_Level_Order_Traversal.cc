#include <bits/stdc++.h> 
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
queue<pair<int, int>> que;
   map<int, int>hMap;
   map<int, bool>visited;
   int levelCounter = 0;
   int n = inorder.size();
   int height = 0;
   
   for(int i=0; i<inorder.size(); i++) {
       hMap[inorder[i]] = i;
       visited[inorder[i]] = false;
   }
   
   pair<int, int>in;
   in.first = levelOrder[0];
   in.second = 0;
   que.push(in);
   visited[levelOrder[0]] = true;
   
   while(!que.empty()) {
       pair<int, int>front = que.front();
       que.pop();
       
       int position = hMap[front.first];
       //leftSide
       if(position > 0 && !visited[inorder[position-1]]) {
           pair<int, int>in;
           in.first = levelOrder[++levelCounter];
           in.second = front.second + 1;
           height = max(height, in.second);
           visited[in.first] = true;
           que.push(in);
       }
       //rightSide
       if(position < n-1 && !visited[inorder[position+1]]) {
           pair<int, int>in;
           in.first = levelOrder[++levelCounter];
           in.second = front.second + 1;
           height = max(height, in.second);
           visited[in.first] = true;
           que.push(in);
       }
   }
   
   return height;
}