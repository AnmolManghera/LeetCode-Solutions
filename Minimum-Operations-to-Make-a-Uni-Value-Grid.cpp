class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>vec;
        int totalSum = 0,ans = INT_MAX;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                vec.push_back(grid[i][j]);
                totalSum += grid[i][j];
            }
        }
        sort(vec.begin(),vec.end());
        if(vec.size() == 1){
            return 0;
        }
        for(int i = 1 ; i < vec.size() ; i++){
            int diff = vec[i] - vec[i-1];
            if(diff % x != 0) return -1;
        }
        int runningSum = 0;
        for(int i = 0 ; i < vec.size() ; i++) {
            // int total = totalSum - (vec.size())*vec[i];
            int total = i*vec[i] - runningSum + totalSum - vec[i] - runningSum - (vec.size()-i-1)*vec[i];
            ans = min(ans, abs(total/x));
            runningSum += vec[i];
        }
        return ans;
    }   
};