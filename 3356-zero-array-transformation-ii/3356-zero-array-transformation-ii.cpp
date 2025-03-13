class Solution {
public:
    bool isPossible(int mid, vector<int>&nums, vector<vector<int>>& q){
        int n = nums.size();
        vector<int>sl(n+1,0);
        for(int i = 0 ; i <= mid ; i++){
            int l = q[i][0], r = q[i][1], val = q[i][2];
            sl[l] -= val;
            sl[r+1] += val;
        }
        for(int i = 1 ; i < n ; i++){
            sl[i] += sl[i-1];
        }
        int sum = sl[0] + nums[0];
        if(sum > 0) return false;
        for(int i = 1 ;i < n ; i++){
            sl[i] += nums[i];
            if(sl[i] > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int ans = -1;
        bool isZero = true;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]) {
                isZero = false;
                break;
            }
        }
        if(isZero){
            return 0;
        }
        int l = 0, r = q.size() - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(mid,nums,q)){
                ans = mid+1;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};