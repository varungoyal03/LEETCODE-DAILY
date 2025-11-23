class Solution {
public:
    int minimumFlips(int n) {
        string s;

        while(n){
                s+= (n&1)+'0';
                n=n>>1;
        };
        string t=s;
        reverse(t.begin(),t.end());

int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) count++;
        }
        return count;
    }
};