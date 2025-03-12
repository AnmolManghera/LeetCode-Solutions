class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCnt = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int posCnt = nums.end() - upper_bound(nums.begin(),nums.end(),0);
        return max(negCnt, posCnt);
    }
};