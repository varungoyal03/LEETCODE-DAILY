class RideSharingSystem {
public:

    // vector<bool> availrider(1001,false);
      bool availrider[1001]={};
    queue<int> riders, drivers;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        availrider[riderId] = true;
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans = {-1,-1};
        while(riders.size() && drivers.size()) {
            int rider = riders.front();
            riders.pop();
            if(availrider[rider]) {
                ans[1] = rider;
                ans[0] = drivers.front();
                availrider[rider]=false;
                drivers.pop();
                break;
            }
        }
        return ans;
    }
    
    void cancelRider(int riderId) {
        availrider[riderId] = false;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */