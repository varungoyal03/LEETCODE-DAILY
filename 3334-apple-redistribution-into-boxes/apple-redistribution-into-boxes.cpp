class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto a : apple) sum += a;

        sort(capacity.rbegin(),capacity.rend());


        for(int i=0;i<capacity.size();i++){
            sum-=capacity[i];
            if(sum<=0) return i+1;
        }

        return 0;
    }
};