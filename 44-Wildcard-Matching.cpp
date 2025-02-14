class Solution {
public:
    bool func(string &s, string &p, int i, int j,int m,int n,vector<vector<int>>&dp){
        if(i == m && j == n) return true;
        if(i == m){
            for(int k = j ; k < n ; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(j == n && i < m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = func(s,p,i+1,j+1,m,n,dp);
        if(p[j] == '*'){
            return dp[i][j] = func(s,p,i+1,j,m,n,dp) || func(s,p,i,j+1,m,n,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m][n] = 1;
        for(int j = n-1 ; j >= 0 ; j--){
            if(p[j] != '*') break;
            dp[m][j] = 1;
        }
        for(int i = m-1 ;i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(s[i] == p[j] || p[j] == '?') dp[i][j] = dp[i+1][j+1];
                if(p[j] == '*') dp[i][j] = dp[i+1][j] || dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};