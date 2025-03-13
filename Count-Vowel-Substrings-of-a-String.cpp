class Solution {
public:
    bool isConsonant(char ch){
        return (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u');
    }

    bool isValid(vector<int>& freq){
        for(int i = 0; i < 26; i++){
            if((freq[i] > 0) && isConsonant('a' + i)) return false;
        }
        return (freq['a' - 'a'] > 0) && 
            (freq['e' - 'a'] > 0) && 
            (freq['i' - 'a'] > 0) && 
            (freq['o' - 'a'] > 0) && 
            (freq['u' - 'a'] > 0);
    }
    int countVowelSubstrings(string word) {
        int head = 0, tail = 0, ans = 0;
        vector<int>freq(26,0);
        for(head = 0 ; head < word.length() ; head++){
            
            freq[word[head]-'a']++;

            if(isConsonant(word[head])){
                while(tail <= head){
                    freq[word[tail]-'a']--;
                    tail++;
                }
            }

            while(isValid(freq)){
                ans++;
                int curr = head+1;
                while(curr < word.length() && !isConsonant(word[curr])){
                    ans++;
                    curr++;
                }
                freq[word[tail]-'a']--;
                tail++;
            }
        }
        return ans;
    }
};