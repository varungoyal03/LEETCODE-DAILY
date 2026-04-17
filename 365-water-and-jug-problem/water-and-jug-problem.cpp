class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y)
            return false;

        queue<pair<int, int>> q;
        set < pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int currX = curr.first;
            int currY = curr.second;

            if (currX + currY == target)
                return true;

            vector<pair<int, int>> nextStates = {
                {x, currY}, // Fill X
                {currX, y}, // Fill Y
                {0, currY}, // Empty X
                {currX, 0}, // Empty Y
                {currX - (min(currY + currX, y) - currY),
                 min(currY + currX, y)}, // Pour X -> Y

                {min(currY + currX, x),
                 currY - (min(currY + currX, y) - currX)} // Pour Y -> X
            };

            for(auto state: nextStates){
                if(visited.count(state)) continue;

                if (state.first + state.second == target) return true;
                q.push(state);
                visited.insert(state);


            }


        }
        return false;}
    };