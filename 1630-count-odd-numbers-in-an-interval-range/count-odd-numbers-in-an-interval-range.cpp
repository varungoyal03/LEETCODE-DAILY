class Solution {
public:
int count(int n){
    return (n+1)/2;

}
    int countOdds(int low, int high) {
        
      return  count(high)-count(low-1);
    }
};