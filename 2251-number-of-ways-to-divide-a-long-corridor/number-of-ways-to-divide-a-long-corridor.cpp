class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
              const int M = 1e9 + 7;
        int totalSeats = 0;
        for (char c : corridor) {
            if (c == 'S') totalSeats++;
        }
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;


          long long ways = 1;
        int seatCount = 0;
        int prev = -1;

        for(int i=0;i<n;i++){
            if(corridor[i]=='P') continue;

            seatCount++;

            if(seatCount==2){
                 prev=i; 
                seatCount=0;
              
            }

            else if (seatCount==1 && prev!=-1){
                ways*= (i-prev);
                ways%=M;

            }
        }

        return ways;
    }
};