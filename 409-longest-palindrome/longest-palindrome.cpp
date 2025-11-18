class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(auto &ch:s) mp[ch]++;

        int len=0;
        bool hasOdd=false;

        for(auto &[ch,f]:mp){
      
            if(f&1){//
                hasOdd=true;
                len+=f-1;}//

            else len+=f;
            
           
        }
   return len+hasOdd; }
};