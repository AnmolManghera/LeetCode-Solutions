class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        vector<vector<int>>realTasks;
        for(int i = 0 ; i < tasks.size(); i++){
            realTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(realTasks.begin(),realTasks.end());
        long long currTime = realTasks[0][0];
        int idx = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>av;
        while(idx < realTasks.size() || av.size()){
            if(av.empty()){
                currTime = max(1LL*realTasks[idx][0],currTime);
            }
            while(idx < realTasks.size() && realTasks[idx][0] <= currTime){
                av.push({realTasks[idx][1],realTasks[idx][2]});
                idx++;
            }
            if(av.size()){
                vector<int>task = av.top();
                av.pop();
                ans.push_back(task[1]);
                currTime = currTime + task[0];
            }
        }
        return ans;
    }
};