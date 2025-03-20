class Disjointset{
    public:
    vector<int>rank,parent,parentAnd;
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        parentAnd.resize(n+1,-1);
        for(int i =0 ; i<=n ; i++){
            parent[i]=i;
            parentAnd[i] = -1;
        }
    }

    int find_up(int node){
        if(node == parent[node])return node;
        return parent[node] = find_up(parent[node]);
    }

    //combining two nodes
    void unionByRank(int u , int v){
        int ulp_u = find_up(u) , ulp_v = find_up(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        Disjointset ds(n);
        for(auto it : edges){
            ds.unionByRank(it[0],it[1]);
            int up = ds.find_up(it[0]);
            if(ds.parentAnd[up] == -1) {
                ds.parentAnd[up] = it[2];
            }
            else{
                int currAnd = ds.parentAnd[up];
                ds.parentAnd[up] = currAnd & it[2];
            }
            // int up2 = ds.find_up(it[1]);
            // if(ds.parentAnd[up2] == -1) {
            //     ds.parentAnd[up2] = it[2];
            // }
            // else{
            //     int currAnd = ds.parentAnd[up2];
            //     ds.parentAnd[up2] = currAnd & it[2];
            // }
        }
        for(int i = 0 ; i < n; i++){
            if(ds.find_up(i) != i && ds.parentAnd[i] != -1){
                ds.parentAnd[ds.find_up(i)] &= ds.parentAnd[i];
            }
            // cout<<i<<" "<<ds.parent[i]<<" "<<ds.parentAnd[i]<<endl;
        }
        int qs = q.size();
        vector<int>ans(qs);
        for(int i = 0 ; i < q.size() ; i++){
            if(ds.find_up(q[i][0]) != ds.find_up(q[i][1])) ans[i] = -1;
            else ans[i] = ds.parentAnd[ds.find_up(q[i][0])];
        }
        return ans;
    }
};