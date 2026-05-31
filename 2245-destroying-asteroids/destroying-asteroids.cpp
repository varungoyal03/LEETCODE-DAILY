class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        long long sum=mass;
        for(auto ast:asteroids){
            if(sum < ast) return false;
            sum+=ast;

        }

        return true;
    }
};