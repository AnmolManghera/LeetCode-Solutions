class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSubsets = pow(2, nums.size());
        int ans = 0;

        for(int i = 1 ; i < totalSubsets ; i++) {
            int idx = 0, mask = i, currXor = 0;
            while(mask) {
                if(mask & 1) {
                    currXor ^= nums[idx];
                }
                mask >>= 1;
                idx++;
            }
            ans += currXor;
        }

        return ans;
    }
};