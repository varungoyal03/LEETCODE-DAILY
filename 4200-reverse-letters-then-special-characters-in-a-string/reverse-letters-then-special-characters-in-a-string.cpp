class Solution {
public:
bool isletter(char c){
    return c>='a' && c<='z';
}
    string reverseByType(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;

        while(i<j){

          if(!isletter(s[i])) i++;
          else if(!isletter(s[j])) j--;

          else{
            swap(s[i],s[j]);
            i++;
            j--;
          }

        }


         i=0;
        j=n-1;

        while(i<j){

          if(isletter(s[i])) i++;
          else if(isletter(s[j])) j--;

          else{
            swap(s[i],s[j]);
            i++;
            j--;
          }

        }
   return s; }
};