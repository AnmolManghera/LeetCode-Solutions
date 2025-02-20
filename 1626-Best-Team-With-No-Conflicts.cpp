class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>>vec;
        for(int i = 0 ; i < n ; i++){
            vec.push_back({ages[i],scores[i]});
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>next(n+1,0), cur(n+1,0);
        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){
                int op1 = next[prev+1];
                int op2 = 0;
                if(prev == -1 || vec[curr][1] >= vec[prev][1]){
                    op2 = vec[curr][1] + next[curr+1];
                }
                cur[prev+1] = max(op1,op2);
            }
            next = cur;
        }
        return next[0];
    }
};