class Solution {
public:
    bool isPossible(long long per, vector<int>&candies, long long k){
        long long total = 0;
        for(int i = 0 ; i < candies.size() ; i++){
            total += (candies[i]/per);
        }
        return total >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        long long total = accumulate(candies.begin(),candies.end(),0LL);
        if(total < k) return 0;
        long long candiesPerChild = total/k;
        int n = candies.size();
        long long l = 1, r = candiesPerChild; 
        int ans = 0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(isPossible(mid,candies,k)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};