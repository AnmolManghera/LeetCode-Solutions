class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<vector<int>>pq; // to store last k places' max ans
        int ans = INT_MIN;
        for(int i = 0 ;i < nums.size() ; i++){
            while(pq.size() && pq.top()[1] < i - k){
                pq.pop();
            } 
            int currVal = pq.size() ? (nums[i] + max(0,pq.top()[0])) : nums[i]; 
            pq.push({currVal,i});
            ans = max(ans,currVal);
        }
        return ans;
    }
};