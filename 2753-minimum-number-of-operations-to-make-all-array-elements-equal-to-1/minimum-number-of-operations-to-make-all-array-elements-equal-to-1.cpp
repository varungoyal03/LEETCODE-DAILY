class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        
int g=nums[0];
int num1=0;
    for(auto &x:nums){
        if(x==1) num1++;
        g=gcd(g,x);
    }
    // cout<<gcd(2,3);
    if(g!=1) return-1;


    if(num1>0)
    return n-num1;

int minLength=n;
    for(int i=0;i<n;i++){   
        int currGcd=nums[i];
        for(int j=i+1;j<n;j++){
         
            currGcd=gcd(currGcd,nums[j]);
            if( currGcd==1) minLength=min(minLength,j-i);
        }
    }
    cout<<minLength;

    return n-1 +minLength;

    }
};