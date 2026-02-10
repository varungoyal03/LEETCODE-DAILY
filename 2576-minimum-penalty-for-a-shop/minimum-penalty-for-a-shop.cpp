class Solution {
public:
    int bestClosingTime(string customers) {
         int n = customers.size(), penalty = 0, bestHour = 0;

         int countY=count(customers.begin(),customers.end(),'Y');

         penalty=countY;
        int  countN=0;

         for(int i=0;i<n;i++){//shop close at i+1

            if(customers[i]=='Y') countY--;

            else countN++;

                if(countY+countN<penalty) {penalty=countY+countN;
                bestHour=i+1;
                }


         }
    return bestHour;}
};