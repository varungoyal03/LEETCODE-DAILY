class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {



         vector<int> result(n);
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {

               
                    
        
                int direct = j - i;

                int viaXY = abs(i - x) + 1 + abs(j - y);
                int viaYX = abs(i - y) + 1 + abs(j - x);

                int d = min({ direct, viaXY, viaYX });

                    result[d-1]+=2;
                

            }
        }
        
        return result;



    }
};