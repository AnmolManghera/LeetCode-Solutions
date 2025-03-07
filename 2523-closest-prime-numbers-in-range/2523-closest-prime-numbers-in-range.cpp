class Solution {
public:
    vector<int>primesTillR(int right, int left){
        vector<int>prime(right+1,1);
        prime[1] = 0;
        prime[0] = 0;
        for(int i = 4 ; i <= right ; i+=2){
            prime[i] = 0;
        }
        for(int i = 3 ; i <= right ; i+=2){
            if(prime[i]){
                for(int j = 2*i ; j <= right ; j += i){
                    prime[j] = 0;
                }
            }
        }
        vector<int>final;
        for(int i = left ; i <= right ; i++){
            if(prime[i]) {
                final.push_back(i);
            }
        }
        return final;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes = primesTillR(right,left);
        if(primes.size() <= 1) return {-1,-1};
        int k = primes.size();
        int maxi = right - left + 1;
        vector<int>nos;
        for(int i = k-1 ; i >= 1; i--){
            int diff = primes[i] - primes[i-1];
            if(diff <= maxi){
                maxi = diff;
                nos = {primes[i-1],primes[i]};
            }
        }
        return nos;
    }
};