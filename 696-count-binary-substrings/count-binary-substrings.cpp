class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();

int len=1;
vector<int> grps;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                len++;
            }
            else {grps.push_back(len); 
            len=1;}

        }
        grps.push_back(len);

int ans=0;
        for(int i=1;i<grps.size();i++){
            ans+=min(grps[i-1],grps[i]);
        }
   return ans; }
};


// The string can be broken into groups of consecutive identical characters. For example, "00110011" becomes groups of lengths 2, 2, 2, and 2. Now, every valid substring can only be formed between two adjacent groups