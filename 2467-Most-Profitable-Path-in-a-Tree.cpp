class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>&path, int curr, int end, vector<int>&vis){
        path.push_back(curr);
        if(curr == end){
            return true;
        }
        vis[curr] = 1;
        for(auto it : adj[curr]){
            if(!vis[it]){
                vis[it] = 1;
                if(dfs(adj,path,it,end,vis) == true) return true;
                vis[it] = 0;
                path.pop_back();
            }
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //path from bob to alice
        int n = amount.size();
        vector<vector<int>>adj(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int>path;
        vector<int>vis(n,0);
        dfs(adj,path,bob,0,vis);
        if((path.size() % 2) == 1){
            amount[path[path.size() / 2]] /= 2;
        }
        for(int i = 0 ; i < path.size()/2 ; i++){
            amount[path[i]] = 0;
        }
        int ans = INT_MIN;
        queue<vector<int>>q; // node,parent,sum
        q.push({0,-1,amount[0]});
        while(!q.empty()){
            vector<int>curr = q.front();
            q.pop();
            if((curr[0] != 0) && adj[curr[0]].size() == 1){
                ans = max(ans,curr[2]);
                continue;
            }
            for(auto it : adj[curr[0]]){
                if(it != curr[1]){
                    q.push({it,curr[0],curr[2] + amount[it]});
                }
            }
        }
        return ans;
    }
};