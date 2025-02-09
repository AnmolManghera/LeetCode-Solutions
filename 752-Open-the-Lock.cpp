class Solution {
public:
    int openLock(vector<string>& d, string target) {
        int ans = INT_MAX;
        set<string>dead(d.begin(),d.end());
        queue<pair<string,int>>q;
        if(dead.find("0000") != dead.end()) return -1;
        set<string>vis;
        q.push({"0000",0});
        while(q.size()){
            string curr = q.front().first;
            int turns = q.front().second;
            q.pop();
            if(curr == target) ans = min(ans,turns);
            if(vis.find(curr) != vis.end()) continue;
            vis.insert(curr);
            //increasing the numbers
            for(int i = 0 ; i < 4 ; i++){
                string temp = curr;
                int next = ((temp[i] - '0') + 1)%10;
                temp[i] = next + '0';
                if(dead.find(temp) != dead.end()) continue;
                else q.push({temp,turns+1});
            }
            //decreasing the numbers
            for(int i = 0 ; i < 4 ;i++){
                string temp = curr;
                int next = ((temp[i] - '0') + 9)%10;
                temp[i] = next + '0';
                if(dead.find(temp) != dead.end()) continue;
                else q.push({temp,turns+1});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};