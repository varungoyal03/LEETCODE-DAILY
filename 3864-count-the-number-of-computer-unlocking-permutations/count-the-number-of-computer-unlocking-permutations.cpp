class Solution {
public:
    int countPermutations(vector<int>& complexity) {
       int n = complexity.size();
        // sort(complexity.begin() + 1, complexity.end());

        long long ans = 1;
        for(int i = 1; i < n; i++) {
            if(complexity[0] >= complexity[i]) return 0;
            ans *= i;
            ans %= int(1e9) + 7;
        }

        return ans;//(N-1)! any order unlock
            

    }
};



// x -> <x+1,inf> 
// x+1 -> <x+2,inf>  (SUBSET OF x)

// 5 6 3  6 4