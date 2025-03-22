class Solution {
public:
     void dfs(int node,vector<int>&visited,vector<int>adj[]){
        visited[node]= 1;
        for(int adjnode :  adj[node]){
            if(!visited[adjnode]){
                dfs(adjnode,visited,adj);
            }
        }
    }
    bool check(vector<int>visi, map<int,set<int>>mpp,int n){
        int nodes = 0 ;
        for(int i = 0 ;i < n ; i++){
            if(visi[i]==1){
                nodes++;
            }
        }
        
        for(int i = 0 ;i < n ; i++){
            if(visi[i]==1){
                if(mpp[i].size() != nodes-1) return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        map<int,set<int>>mpp;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mpp[it[0]].insert(it[1]);
            mpp[it[1]].insert(it[0]);
        }

        int ans = 0;
        vector<int>vis(n,0);
        vector<int>store;
        for(int i = 0 ; i < n ;i++){
            if(vis[i]==0){
                store.push_back(i);
                dfs(i,vis,adj);
            }
        }
        for(auto it:store){
            vector<int>visi(n,0);
            dfs(it,visi,adj);
            if(check(visi,mpp,n)){
                ans++;
            }
        }
        return ans;
    }
};