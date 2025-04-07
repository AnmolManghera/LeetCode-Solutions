class Solution {
public:
    bool func3(int ind,int target,vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i = 0; i<=ind ;i++){
            dp[i][0]= true;
        }  
        if(target>= nums[0]){
            dp[0][nums[0]] = true;
        }
        
        for(int i=1;i<=ind;i++){
            for(int j = 1;j<=target;j++){
                bool not_take = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j){ 
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = not_take || take;
            }
        }
        return dp[ind][target];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i =0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        if(nums.size()==1){
            return false;
        }
        if(totalSum%2 == 1){
            return false;
        }
        return func3(nums.size()-1,totalSum/2,nums);
    }
};
