class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;

        vector<int> freq(26,0);
        for(char &ch:s1){ freq[ch-'a']++;}

        vector<int> freq1(26, 0), freq2(26, 0);
//precoess first window
        for (char c : s1) freq1[c - 'a']++;
        for (int i = 0; i < n1; i++) freq2[s2[i] - 'a']++;
int matches=0;
        for(int i=0;i<26;i++){
            if(freq1[i]==freq2[i]) matches++;
        }
        if(matches==26) return true;
//slide

        for (int i = n1; i < n2; i++) {
            int newCh=s2[i] - 'a';
            int oldCh=s2[i - n1] - 'a';

            freq2[newCh]++;              // add new char
        


            if (freq1[newCh] == freq2[newCh]) matches++; 
            else if (freq1[newCh]+1 == freq2[newCh]) { matches--;}

  freq2[oldCh]--;         // remove old char
            if (freq1[oldCh] == freq2[oldCh]) matches++; 
            else if (freq1[oldCh]-1 == freq2[oldCh]) { matches--;}

            if(matches==26) return true;
        }


        return false;

        
    }
};