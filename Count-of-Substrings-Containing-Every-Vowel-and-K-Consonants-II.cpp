class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool isValid(vector<int>&freq, int k){
        int cnt = 0, vowels = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(isVowel(i+'a')) vowels += (freq[i] > 0);
            else cnt += freq[i];
        }
        return vowels == 5 && cnt == k;
    }
    bool isConsonantsGreaterThanK(vector<int>&freq, int k){
        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(!isVowel(i+'a')) cnt += freq[i];
        }
        return cnt > k;
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        vector<int>vowelCnt(n,-1);
        if(isVowel(word[n-1])) vowelCnt[n-1] = 1;
        for(int i = n-2 ; i >= 0 ; i--){
            if(isVowel(word[i]) && vowelCnt[i+1] >= 1){
                vowelCnt[i] = vowelCnt[i+1] + 1;
            }
            else if(isVowel(word[i])){
                vowelCnt[i] = 1;
            }
            else if(vowelCnt[i+1] == -1){
                vowelCnt[i] = -1;
            }
        }
        // for(int i = 0 ; i < n ; i++){
        //     cout<<vowelCnt[i]<<" ";
        // }
        int head = 0, tail = 0;
        long long ans = 0;

        vector<int>freq(26,0);
        for(head = 0 ; head < n ; head++){
            // When to contract ?
            // 1. No of vowel at tail is greater than 1
            // 2. No of consonants is greater than k
            freq[word[head]-'a']++;
            while(isConsonantsGreaterThanK(freq,k)){
                freq[word[tail] - 'a']--;
                tail++;
            }

            while(isValid(freq,k)){
                ans++;
                // extend for vowels to the right (because we can take extra vowels)
                int curr = head+1;
                if(curr < n && vowelCnt[curr] != -1){
                    ans += vowelCnt[curr];
                }

                freq[word[tail] - 'a']--;
                tail++;
            }
        }
        return ans;
    }
};