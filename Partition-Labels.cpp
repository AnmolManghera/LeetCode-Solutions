class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastOccurence(26,-1);
        for(int i = 0 ; i < s.length() ; i++) {
            lastOccurence[s[i] - 'a'] = i;
        }
        int i = 0, currStart;
        vector<int>ans;
        int currMax = lastOccurence[s[i]-'a'];
        while(i < s.length()) {
            while(i != currMax) {
                i++;
                currMax = max(currMax,lastOccurence[s[i]-'a']);
            }
            ans.push_back(i-currStart+1);
            i++;
            currStart = i;
            if(i < s.length()) currMax = lastOccurence[s[i]-'a'];
        }
        return ans;
    }
};