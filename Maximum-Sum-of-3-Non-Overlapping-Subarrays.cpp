class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>ps(n+1,0);
        for(int i = 0 ; i < n ;i++){
            ps[i+1] = nums[i] + ps[i];
        }
        vector<int>thirdBest(n,-1);
        thirdBest[n-k] = n-k;

        for(int i = n-k-1 ; i >= 0 ; i--){
            long long currSum = ps[i+k] - ps[i];
            int idx = thirdBest[i+1];
            long long nextBest = ps[idx+k] - ps[idx];

            if(currSum >= nextBest){
                thirdBest[i] = i;
            }
            else{
                thirdBest[i] = idx;
            }
        }

        vector<int>secondBest(n,-1);
        
        for(int i = 0 ;i < n; i++){
            if(i+k >= n) break;
            secondBest[i] = thirdBest[i+k];
        }

        vector<pair<pair<int,int>,long long>>firstBest(n);
        long long m = ps[n] - ps[n-k];
        long long t = ps[n-k] - ps[n-2*k];
        firstBest[n - 2*k] = {{n-2*k, n-k} ,m + t };
        for(int i = n - 2*k  - 1; i >= 0 ; i--){
            if(secondBest[i] != -1){
                //choice from this idx and its third best
                long long one = i, two = secondBest[i];
                long long a1 = ps[one+k] - ps[one];
                long long a2 = ps[two+k] - ps[two];
                long long a = a1 + a2;

                //already computed ans from next idx
                int three = firstBest[i+1].first.first, four = firstBest[i+1].first.second;
                long long b1 = ps[three+k] - ps[three];
                long long b2 = ps[four+k] - ps[four];
                long long b = b1 + b2;

                if(a >= b){
                    firstBest[i] = {{one,two},a};
                }
                else{
                    firstBest[i] = {{three,four},b};
                }
            }
        }


        long long bestSum = 0;
        vector<int>ans = {n,n,n};
        for(int i = 0 ;i < n ;i++){
            if(i+k >= n) break;
            long long sum1 = ps[i+k] - ps[i];
            long long sum2 = firstBest[i+k].second;
            long long sum = sum1 + sum2;
            if(sum > bestSum){
                bestSum = sum;
                ans = {i,firstBest[i+k].first.first, firstBest[i+k].first.second};
            }
        }
        return ans;
    }
};