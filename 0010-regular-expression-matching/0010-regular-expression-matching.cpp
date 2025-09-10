class Solution {
public:
    int dp[25][25];
    bool f(string s,string p,int i,int j,int m,int n){
        if(i>=m && j>=n) return dp[i][j] = true;
        if(j>=n) return dp[i][j] = false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = (i<m) && (s[i] == p[j] || p[j] == '.');
        if(j+1 < n && p[j+1] == '*'){
            return dp[i][j] = f(s,p,i,j+2,m,n) || (match && f(s,p,i+1,j,m,n));
        }
        if(match) return dp[i][j] = f(s,p,i+1,j+1,m,n);
        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
        memset(dp,-1,sizeof(dp));
        return f(s,p,0,0,m,n);
    }
};