class Solution {
public:
    string reverseWords(string s) {
        
        int left=0;

        for(int right=0; right<=s.size(); right++)
        {
            if(s[right]==' ' || right==s.size())
            {
                reverse(s.begin()+left, s.begin()+right);
                left = right+1; //update left position
            }
        }
        return s;
    }
};