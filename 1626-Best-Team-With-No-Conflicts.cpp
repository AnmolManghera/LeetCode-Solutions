class Solution {
public:
    int func(int prev, int curr, vector<vector<int>>&vec, vector<vector<int>>&dp){
        if(curr == vec.size()){
            return 0;
        }
        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }
        int op1 = func(prev,curr+1,vec,dp);
        int op2 = 0;
        if(prev == -1 || vec[curr][1] >= vec[prev][1]){
            op2 = vec[curr][1] + func(curr, curr+1, vec,dp);
        }
        return dp[prev+1][curr] = max(op1,op2);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>>vec;
        for(int i = 0 ; i < n ; i++){
            vec.push_back({ages[i],scores[i]});
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return func(-1,0,vec,dp);
    }
};