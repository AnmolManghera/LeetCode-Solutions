class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int>rangeDiffMax(n,-1);
        int maxNo = nums[0];
        for(int i = 1 ; i < n ; i++) {
            if(maxNo - nums[i] >= 0) {
                rangeDiffMax[i] = maxNo - nums[i];
            }
            maxNo = max(nums[i],maxNo);
        }
        
        maxNo = nums[n-1];
        for(int i = n-2 ; i >= 1 ; i--) {
            if(rangeDiffMax[i] != -1) {
                ans = max(ans, 1LL*rangeDiffMax[i]*maxNo);
            }
            maxNo = max(nums[i],maxNo);
        }
        
        return ans;
    }
};