

class RideSharingSystem {
private:
    list<int> ridersList;
    list<int> driversList;

    unordered_map<int, list<int>::iterator> riderPos;
    

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
      
        ridersList.push_back(riderId);
    
        riderPos[riderId] = --ridersList.end();;
    }

    void addDriver(int driverId) {
       
        driversList.push_back(driverId);
      
    }

    vector<int> matchDriverWithRider() {
        if (driversList.empty() || ridersList.empty()) {
            return {-1, -1};
        }

        int driverId = driversList.front();
        int riderId  = ridersList.front();

        driversList.pop_front();
        ridersList.pop_front();

     
        riderPos.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        if (!riderPos.count(riderId)) return;

        auto it = riderPos[riderId];
        ridersList.erase(it);
        riderPos.erase(riderId);
    }
};
