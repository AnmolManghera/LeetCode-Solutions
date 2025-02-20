class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(nums[i][i] == '1') ans.push_back('0');
            else ans.push_back('1');
        }
        return ans;
    }
};