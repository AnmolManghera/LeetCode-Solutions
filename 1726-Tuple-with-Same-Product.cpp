class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>ump;
        for(int i = 0 ; i < n; i++){
            for(int j = i+1 ; j < n; j++){
                ump[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto it : ump){
            if(it.second > 1){
                int sz = it.second;
                ans += ((sz)*(sz-1)*4);
            }
        }
        return ans;
    }
};
// 6 -> 1,
// 8 -> 1,
// 12 -> 1,1
// 18 -> 1
// 24 -> 1
