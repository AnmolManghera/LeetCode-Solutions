class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char>st;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};