class Solution {
public:
    bool f(string str , int target){
        if(target < 0) return false;
        if(target == 0){
            for(int i = 0 ; i < str.length() ;i++){
                if(str[i] != '0') return false;
            }
            return true;
        }
        for(int i = 0 ; i < str.length() ;i++){
            string temp = str.substr(0,i+1);
            int currSum = stoi(temp);
            // cout<<currSum<<endl;
            if(f(str.substr(i+1), target - currSum)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int  k = 1 ; k<=n ; k++){
            int sq = k*k;
            string str = to_string (sq);
            if(f(str,k)) ans+= sq;
        }
        return ans;
    }
};