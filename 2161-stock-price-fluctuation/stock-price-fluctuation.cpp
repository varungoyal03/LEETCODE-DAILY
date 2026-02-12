class StockPrice {
public:
    map<int, int> mp;
    
    // multiset will store the prices
    
    multiset<int> s;
     int latest_time = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)) s.erase(s.find(mp[timestamp]));
        mp[timestamp]=price;
        s.insert(price);
        latest_time=max(latest_time,timestamp);
    }
    
    
    int current() {
        return mp[latest_time];

        
    }
    
    int maximum() {
        return *s.rbegin();
        
    }
    
    int minimum() {
            return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
