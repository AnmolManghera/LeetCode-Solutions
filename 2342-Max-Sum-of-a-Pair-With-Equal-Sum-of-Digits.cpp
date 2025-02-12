class Solution {
public:
    int func(int no){
        int ans = 0;
        while(no){
            int ld = no%10;
            ans += ld;
            no /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>ump;
        for(int i = 0 ; i < nums.size() ; i++){
            int sum = func(nums[i]);
            ump[sum].push_back(nums[i]);
        }
        int ans = -1;
        for(auto it : ump){
            if(it.second.size() >= 2){
                vector<int>&temp = it.second;
                sort(temp.begin(),temp.end(),greater<int>());
                ans = max(ans, temp[0] + temp[1]);
            }
        }
        return ans;
    }
};