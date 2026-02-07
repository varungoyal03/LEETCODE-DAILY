class Solution {
public:
    int minimumDeletions(string s) {
        //try all boudaries

        int countA=count(s.begin(),s.end(),'a');
        if(countA==0 || countA==s.size()) return 0;//
        int countB=0;

int ans=countA;//
        for(auto ch:s){
            if(ch=='b') countB++;
            else countA--;

            ans=min(ans,countB+countA);

        }
         ans=min(ans,countB);//

        return ans;
    }
};

//AAABBBBBAAAAAB
//AAABBBB