class RateLimiter {
    public:
    unordered_map<int,int>last;
    int expire;
    RateLimiter(int expire) {
        this->expire = expire;
    }

    bool limit(int uid, int timestamp) {
        if(!last.count(uid)){
            last[uid] = timestamp;
            return false;
        }
        else{
            if(last[uid]+expire > timestamp) return true;
            else{
                last[uid] = timestamp;
                return false;
            }
        }
    }
};