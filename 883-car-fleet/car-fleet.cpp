class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
     int n = position.size();
        if (n == 0) return 0;

        // Step 1: Pair the position and speed, then sort by position (descending)
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        
        // Sort ascending by default, but we will iterate backwards
        sort(cars.begin(), cars.end()); 

        int fleets = 0;
        double max_time = 0.0; // Acts as our "stack top"

        // Step 2 & 3: Iterate from the car closest to the target down to the furthest
        for (int i = n - 1; i >= 0; i--) {
            // Time = (Target - Position) / Speed
            double current_time = (double)(target - cars[i].first) / cars[i].second;

            // If this car's time is strictly greater than the fleet leader ahead of it,
            // it cannot catch up. It forms a new fleet!
            if (current_time > max_time) {
                fleets++;
                max_time = current_time; // This car is the new bottleneck
            }
            // If current_time <= max_time, it catches up and joins the existing fleet.
            // We do nothing, and it disappears into the fleet.
        }

        return fleets; }
};