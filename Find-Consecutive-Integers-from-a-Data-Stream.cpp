class DataStream {
public:
    int val;
    int _k;
    int streak;
    int lastNo;
    vector<int>nums;
    DataStream(int value, int k) {
        val = value;
        _k = k;
        streak = 0;
        lastNo = -1;
    }
    
    bool consec(int num) {
        if(lastNo == -1 || lastNo != num){
            streak = 1;
            lastNo = num;
        }
        else{
            streak += 1;
        }
        return streak >= _k && lastNo == val;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */