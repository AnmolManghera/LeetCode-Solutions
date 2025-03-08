class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int head = 0, tail = 0, ans = blocks.size(), currW = 0;
        for(head = 0 ; head < blocks.size() ; head++){
            if(blocks[head] == 'W') currW++;
            while(head - tail + 1 > k){
                if(blocks[tail] == 'W') {
                    currW--;
                }
                tail++;
            }
            if(head - tail + 1 == k) ans = min(ans, currW);
        }
        return ans;
    }
};