class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxRangeDiff = 0;
        int maxNo = nums[0];
        for(int i = 1 ; i < n ; i++) {
            if(i >= 2) {
                if(maxRangeDiff != -1) {
                    ans = max(ans, 1LL*maxRangeDiff*nums[i]);
                }
            }
            if(maxNo - nums[i] >= 0) {
                maxRangeDiff = max(maxNo - nums[i], maxRangeDiff);
            }
            maxNo = max(nums[i],maxNo);
        }    
        return ans;
    }
};