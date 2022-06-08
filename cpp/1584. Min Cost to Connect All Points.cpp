int minCostConnectPoints(vector<vector<int>>& points) {
    int ans = 0;
    int n = points.size();
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            adj[i].push_back({j,abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
        }
    }
    vector<int> vis(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        int u = cur.second;
        if(vis[u]) continue;
        vis[u] = true;
        ans+=cur.first;
        for(auto it : adj[u])
        {
            int node = it.first;
            int wt = it.second;
            if(vis[node]==false)
                pq.push({wt,node});
        }
    }
    return ans;
}
