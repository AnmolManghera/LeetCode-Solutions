class Solution {
public:
    void func(string curr, int &k, string &ans, int n){
        if(k <= 0) return;
        if(curr.length() == n){
            k--;
            if(k == 0) ans = curr;
            return;
        }
        if(curr == ""){
            func(curr + 'a', k, ans, n);
            func(curr + 'b', k, ans, n);
            func(curr + 'c', k, ans, n);
        }
        else{
            if(curr.back() == 'a'){
                func(curr + 'b', k, ans, n);
                func(curr + 'c', k, ans, n);
            }
            if(curr.back() == 'b'){
                func(curr + 'a', k, ans, n);
                func(curr + 'c', k, ans, n);
            }
            if(curr.back() == 'c'){
                func(curr + 'a', k, ans, n);
                func(curr + 'b', k, ans, n);
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        func("",k,ans,n);
        return ans;
    }
};