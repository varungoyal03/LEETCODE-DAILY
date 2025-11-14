class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();

int ans=0;
int i=0;
int countOne=0;
        while(i<n ) {
            if(s[i]=='1')
            {countOne++;
             i++;}
            
            else{

                while(i<n && s[i]=='0'){
                    i++;
                }

                ans+=countOne;

            }


        }
    return ans; }
};