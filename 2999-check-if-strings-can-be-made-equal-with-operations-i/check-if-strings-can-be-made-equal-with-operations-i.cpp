class Solution {
public:
    bool canBeEqual(string s1, string s2) {
           vector<int> odd(26,0);
      vector<int> even(26,0);

      int n=s1.size();

      for(int i=0;i<n;i++){
        if(i&1){
            odd[s1[i]-'a']++;
            odd[s2[i]-'a']--;

        }
        else{
            even[s1[i]-'a']++;
            even[s2[i]-'a']--; 
        }
      } 

      for(int i=0;i<26;i++){
        if(odd[i] || even[i] ) return false;
      } 

      return true; 
    }
};





