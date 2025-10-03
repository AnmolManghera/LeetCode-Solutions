class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // we can proceed to next course only if its dependency is resolved
        // a task can be started only when its bottleneck dependency is done
        // all tasks with no dependency can be completed at time 0

        stack<vector<int>> st; // node, start time
        vector<vector<int>> adj(n+1);
        for(auto it : relations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(n+1, 0), start(n+1, 0);
        for(int i = 0 ; i < relations.size() ; i++){
            indegree[relations[i][1]]++;
        }

        for(int i = 1 ; i <= n ; i++) {
            if(indegree[i] == 0) st.push({i, 0});
        }

        while(!st.empty()) {
            int course = st.top()[0], startTime = st.top()[1];
            st.pop();

            for(auto it : adj[course]) {
                start[it] = max(start[it], startTime + time[course-1]);
                indegree[it]--;
                if(indegree[it] == 0) {
                    st.push({it, start[it]});
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            ans = max(ans, start[i] + time[i-1]);
        }
        return ans;
    }
};