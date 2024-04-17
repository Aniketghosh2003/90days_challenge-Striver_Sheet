vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    vector<int> ans;

    for(int i = 0;i < n;i++){
           mp[arr[i]]++;
    }
    
    for(auto i:mp){
        pq.push({i.second,i.first});
    }

    for(int i = 0;i < k;i++){
          auto temp = pq.top();
          pq.pop();
          ans.push_back(temp.second);
    }
    return ans;

}