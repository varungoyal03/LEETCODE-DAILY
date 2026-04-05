class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;

        string originalText;
        
       
        for(int c=0;c<col;c++){ 
             int i=c;
            while(i<n){
                originalText+=encodedText[i];
                i+=col+1;
            }
        }

        while(!originalText.empty() && originalText.back()==' ') originalText.pop_back();


        return originalText;
    }
};