class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mpp; //ball,color
        unordered_map<int,int>mppp; //color,ball
        // unordered_set<int>distinct;
        vector<int>ans;
        for(int i = 0 ; i < queries.size() ; i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(mpp.find(ball) == mpp.end()){
                mpp[ball] = color;
                mppp[color]++;
            }
            else{
               int prevcolor = mpp[ball];
               if(mppp[prevcolor] == 1){
                   mppp.erase(prevcolor);
               }
               else {
                    mppp[prevcolor]--;
               }
               mpp[ball]  = color;
               mppp[color]++; 
            }
            ans.push_back(mppp.size());
        }
        return ans;
    }
};