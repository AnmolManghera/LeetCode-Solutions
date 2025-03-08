class Solution {
public:
    int func(int idx, string s, unordered_set<string>&st){
        if(idx == s.length()) return 0;
        if(s[idx] == '0') return 1e9;
        string temp = "";
        int ans = 1e9;
        for(int i = idx ; i < s.length() ; i++){
            temp += s[i];
            if(st.find(temp) != st.end()){
                ans = min(ans, 1 + func(i+1, s, st));
            }
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        unordered_set<string>st;
        st.insert("1");
        st.insert("101");
        st.insert("11001");
        st.insert("1111101");
        st.insert("1001110001");
        st.insert("110000110101");
        st.insert("11110100001001");
        int ans = func(0,s,st);
        return ans == 1e9 ? -1 : ans;
    }
};