class TimeMap {
public:
        map<string, vector<pair<int, string>>> mp;
    TimeMap() {

        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) { 
        if(!mp.count(key)) return "";//
        auto &v=mp[key];
        
        pair<int, string> pair={timestamp+1,""};
        auto it=lower_bound(v.begin(),v.end(),pair);  //** 
 
        if(it==v.begin()) return "";
        --it;

        return it->second;

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

