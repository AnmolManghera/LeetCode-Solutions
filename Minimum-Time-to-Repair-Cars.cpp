class Solution {
public:
    bool isPossible(long long t, vector<int>& ranks, int cars) {
        long long cnt = 0;
        for(int i = 0; i < ranks.size() ; i++) {
            cnt += sqrt(t/ranks[i]);
            if(cnt >= cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        int n = ranks.size();
        long long l = 1;
        long long r = (long)ranks[n-1]*cars*cars;
        long long ans = r;

        while(l <= r) {
            long long mid = (l+r)/2;
            if(isPossible(mid,ranks,cars)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};