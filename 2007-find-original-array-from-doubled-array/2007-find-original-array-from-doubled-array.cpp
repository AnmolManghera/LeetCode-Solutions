class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        if(c.size() % 2) return {};
        sort(c.begin(), c.end());
        vector<int> ans, used(c.size(), 0);
        int i = 0, j = 1;
        while(i < c.size()) {
            // cout << i << " " << used[i] << endl;
            if(used[i]) {
                i++;
                if(i == j) j++;
                continue;
            }
            // we want to add nums[i] to our final array
            // j should go till its double
            while(j < c.size() && c[j] < 2*c[i]) {
                j++;
            }
            while(j < c.size() && used[j]) {
                j++;
            }

            if(j < c.size() && c[j] == 2*c[i]) {
                ans.push_back(c[i]);
                used[j] = 1;
                used[i] = 1;
                i++;
                j++;

                // for(auto it : used) {
                //     cout << it << " ";
                // }
                // cout << endl;
            }
            else {
                break;
            }
        }
        // for(auto it : ans) cout << it << " ";
        if(2*ans.size() == c.size()) return ans;
        return {};
    }
};

// [1, 2, 3, 4, 6, 8]
// i = 0, j = 1
// 
