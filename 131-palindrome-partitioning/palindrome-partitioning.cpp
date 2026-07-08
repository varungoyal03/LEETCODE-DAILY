class Solution {
public:   
    vector<vector<string>> ans;
    vector<string> temp;  
    vector<vector<bool>> isPalindrome;

    void dfs(int start,string &s){
        if(start==s.size()){ans.push_back(temp); return;} 

        string currentStr = "";
        for(int end =start;end<s.size();end++){
            currentStr += s[end];
            if(isPalindrome[start][end]){
                temp.push_back(currentStr);
                dfs(end+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
     isPalindrome.assign(n, vector<bool>(n, false));

     // We check lengths from 1 up to n
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // The end index
                
                // If the outer characters match...
                if (s[i] == s[j]) {
                    // It is a palindrome if it's 1 or 2 chars long, 
                    // OR if the inner substring is also a palindrome.
                    if (len <= 2 || isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }

        dfs(0,s);
        return ans;
    }
};