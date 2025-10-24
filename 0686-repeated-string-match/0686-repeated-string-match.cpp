class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // a needs to atleast become the size of b

        // if still not possible, double it again once

        string temp = a;
        int count = 1;

        while (temp.size() < b.size()) {
            temp += a;
            count++;
        }

        if (temp.find(b) != string::npos) return count;

        temp += a;
        if (temp.find(b) != string::npos) return count + 1;

        return -1;
    }
};