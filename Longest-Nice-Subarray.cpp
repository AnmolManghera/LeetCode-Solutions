class Solution {
public:
    bool canAddNo(vector<int>bitmap, int no){
        for(int i = 0 ; i < 32 ; i++){
            int isSet = (no>>i) & 1;
            if(isSet && bitmap[i]) return false;
        }
        return true;
    }
    bool addNo(vector<int>&bitmap, int no){
        for(int i = 0 ; i < 32 ; i++){
            if((no >> i)&1) bitmap[i] = 1;
        }
        return true;
    }
    void removeNo(vector<int>&bitmap, int no){
        for(int i = 0 ; i < 32 ; i++){
            if((no >> i)&1) bitmap[i] = 0;
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>bitmap(32,0);
        int head = 0, ans = 0,tail = 0;
        for(head = 0 ; head < nums.size() ; head++) {
            
            while(!canAddNo(bitmap,nums[head])){
                removeNo(bitmap,nums[tail]);
                tail++;
            }
            
            addNo(bitmap,nums[head]);

            ans = max(ans, head - tail + 1);
        }
        return ans;
    }
};