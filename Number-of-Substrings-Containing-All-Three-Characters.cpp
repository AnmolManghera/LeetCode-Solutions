class Solution {
public:
    int numberOfSubstrings(string s) {
        // for current character , we need last occurence of other 2 characters
        // take minimum of these indices
        int lastA = -1, lastB = -1, lastC = -1;
        for(int i = 0 ; i < 2 ; i++){
            if(s[i] == 'a') lastA = i;
            else if(s[i] == 'b') lastB = i;
            else lastC = i;
        }
        int ans = 0;
        for(int i = 2 ;i < s.length() ; i++){
            if(s[i] == 'a'){
                lastA = i;
                if(lastB != -1 && lastC != -1){
                    ans += (min(lastB,lastC) + 1);
                }
            }
            else if(s[i] == 'b'){
                lastB = i;
                if(lastA != -1 && lastC != -1){
                    ans += (min(lastA,lastC) + 1);
                }
            }
            else if(s[i] == 'c'){
                lastC = i;
                if(lastA != -1 && lastB != -1){
                    ans += (min(lastA,lastB) + 1);
                }
            }
        }
        return ans;
    }
};