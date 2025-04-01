class Solution {
public:
    long long dp[100005];
    long long func(int idx,vector<vector<int>>& ques, int n){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long pick = ques[idx][0] + func(idx + ques[idx][1] + 1,ques,n);
        long long notPick = func(idx+1,ques,n);
        return dp[idx] = max(pick,notPick);
    }
    long long mostPoints(vector<vector<int>>& q) {
        memset(dp,-1,sizeof(dp));
        return func(0,q,q.size());
    }
};