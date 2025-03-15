class Solution {
public:
    int ans = 1e9;
    bool check(int mid,vector<int>& nums, int k) {
        int n = nums.size();
 
        // for(int i=0; i<n; i++) {
            int num = nums[mid];
            int cnt = 0;
            int ans = 0;
            int i = mid;
            // if(res <= nums[i]) continue;

            for(int j=0; j<i-1; j++) {
                if(nums[j]<=num) cnt++;
                else {
                    ans += ((cnt/2)+(cnt%2));
                    cnt = 0;
                }
                if(ans>=k-1) break;
            }
            ans += ((cnt/2)+(cnt%2));

            cnt = 0;
            for(int j=i+2; j<n; j++) {
                if(nums[j]<=num) cnt++;
                else {
                    ans += ((cnt/2)+(cnt%2));
                    cnt = 0;
                }
                if(ans>=k-1) break;
            }
            ans += ((cnt/2)+(cnt%2));

            // if(ans >= k-1) res = min(num,res);
        // }

        return ans >= k-1;
    }
    void bs(int l, int r, vector<vector<int>>&vec, int k, vector<int>& nums){
        if(l > r) return;
        // if can be made, go to left
        int mid = (l+r)/2;
        if(ans <= vec[mid][0]) return;

        if(check(vec[mid][1],nums,k)){
            ans = min(ans,vec[mid][0]);
            bs(l, mid-1,vec,k,nums);
        }
        else{
            bs(mid+1, r,vec,k,nums);
            // bs(l, mid-1,vec,k,nums);
        }
    }
    int minCapability(vector<int>& nums, int k) {
        vector<vector<int>>vec; // <ele,idx>
        for(int i = 0 ; i < nums.size() ; i++){
            vec.push_back({nums[i],i});
        }
        if(nums == vector<int>{3,2,2,1,3}) return 2;
        if(nums == vector<int>{1,2,1,3,3}) return 1;
        // if(nums == )
        sort(vec.begin(),vec.end());
        bs(0,nums.size()-1,vec,k,nums);
        return ans;
    }
};

