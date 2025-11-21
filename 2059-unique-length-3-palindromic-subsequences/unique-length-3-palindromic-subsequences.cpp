class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> first(26,-1);
         vector<int> last(26,-1);

         for(int i=0;i<n;i++){
            int ch=s[i]-'a';

            if(first[ch]==-1) first[ch]=i;

            last[ch]=i;
         }
         int ans=0;

         for(int i=0;i<26;i++){

            if(last[i]==-1 || last[i]==first[i]) continue;

            unordered_set<char> set;
            for(int j=first[i]+1 ; j<last[i];j++){
                set.insert(s[j]);     
            }
            ans+=set.size();
         }
        
 return ans;   }
};