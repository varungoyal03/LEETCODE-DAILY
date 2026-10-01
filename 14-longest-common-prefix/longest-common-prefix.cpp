class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        	// Find length of smallest string
    int minLen = arr[0].size();

    for(string &str: arr)
        minLen = min(minLen, (int)str.size());

    string res;
    for (int i = 0; i < minLen; i++) {
      
        // Current character (must be the same
        // in all strings to be a part of result)
        char ch = arr[0][i];

        for (string &str: arr) {
            if (str[i] != ch)    
                return res;
        }

        // Append to result
        res.push_back(ch);
    
    }

    return res;
    }
};