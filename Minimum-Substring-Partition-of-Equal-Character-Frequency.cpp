class Solution {
public:
    bool isEqual(vector<int>&freq){
        int val = -1;
        for(int i = 0 ; i < 26 ; i++){
            if(val == -1 && freq[i] > 0){
                val = freq[i];
            }
            else if(freq[i] > 0){
                if(freq[i] != val) return false;
            }
        }
        return true;
    }
    int func(int idx, string s, vector<int>&dp){
        if(idx == s.length()) return 0;
        if(dp[idx] != -1) return dp[idx];
        vector<int>freq(26,0);
        int ans = 1e9;
        for(int i = idx ; i < s.length() ; i++){
            freq[s[i]-'a']++;
            if(isEqual(freq)){
                ans = min(ans, 1 + func(i+1, s, dp));
            }
        }
        return dp[idx] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        vector<int>dp(s.length(),-1);
        return func(0,s,dp);
    }
};