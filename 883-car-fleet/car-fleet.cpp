class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();

        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(cars.rbegin(),cars.rend());

        int fleet=n;
        double prevArrivalMax=cars[0].second;//time use "double"

        for(int i=1;i<n;i++){
            if(cars[i].second <= prevArrivalMax){
                fleet--;
            }
            else prevArrivalMax=cars[i].second;
            
        }
   return fleet; }
};