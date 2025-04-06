class Solution { 
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> prevIdx(n,-1);
        int maxCnt = 0, maxIdx = -1;
        for(int i = 0 ; i < n ; i++) {
            for(int prev = 0 ; prev < i ; prev++) {
                if(nums[i] % nums[prev] == 0) {
                    if(1 + dp[prev] > dp[i]){
                        dp[i] = 1 + dp[prev];
                        prevIdx[i] = prev;
                    }
                }
            }
            if(dp[i] > maxCnt) {
                maxCnt = dp[i];
                maxIdx = i;
            }
        }
        vector<int>ans;
        int idx = maxIdx;
        while(idx != -1) {
            ans.push_back(nums[idx]);
            idx = prevIdx[idx];
        }
        return ans;
    }
};