class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(words[i]!=target) continue;

            ans=min(ans,abs(startIndex -i));
            ans=min(ans,n-abs(startIndex -i));
            

        }
    return ans==INT_MAX?-1:ans;    
    }
};