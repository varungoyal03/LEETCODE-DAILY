class Solution {
public:
    // Greedy Solution -> how to fill boat of size 2 effectively, so that we can achieve maximum number of boats.
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int n = people.size();
        
        int low = 0, high = n-1;
        int cnt = 0;

        while(low < high)
        {
            int sum = people[low] + people[high];

            if(sum <= limit)
            {
                cnt++;
                low++;
                high--;
            }
            else
            {
                cnt++;
                high--;
            }
        }

        if(low == high && people[low]<=limit)
        {
            cnt++;
        }

        return cnt;
  
    }
};