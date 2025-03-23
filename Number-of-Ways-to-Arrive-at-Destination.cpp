class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 +7;
        vector<pair<long long,long long>>adj[n];
        for(vector v:roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector<long long>ways(n,0);
        vector<long long>dist(n,LONG_MAX);
        // <dist,node>
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        ways[0] = 1;
        dist[0] = 0;
        while(!pq.empty()){
            long long distance = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long long adjNode = it.first;
                long long edgeWt = it.second;
                //this is the first time i m coming with this short dist
                if(edgeWt + distance < dist[adjNode] ){
                    dist[adjNode] = (edgeWt + distance);
                    pq.push({edgeWt + distance,adjNode});
                    ways[adjNode] = ways[node]%MOD;
                }
                else if(edgeWt + distance == dist[adjNode]){
                    ways[adjNode] += (ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};