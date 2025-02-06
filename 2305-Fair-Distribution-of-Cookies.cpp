class Solution {
public:
    int ans,n;
    void func(int cookie_idx,vector<int>& cookies, int k,vector<int>&cookieHolder){
        if(cookie_idx >= n){
            ans = min(ans,*max_element(cookieHolder.begin(),cookieHolder.end()));
            return;
        }
        for(int i = 0 ; i < k ; i++){
            cookieHolder[i] += cookies[cookie_idx];
            func(cookie_idx+1,cookies,k,cookieHolder);
            cookieHolder[i] -= cookies[cookie_idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        n = cookies.size();
        vector<int>cookieHolder(k,0);
        func(0,cookies,k,cookieHolder);
        return ans;
    }
};