class Solution {
public:
    int minimumK(vector<int>& nums) {
    int s=1;
    int e=1e5;

    int ans=e;

    auto isValid = [&](int k) {
    long long tot = 0;
    for (int num : nums) {
        tot += (num + k - 1) / k;
    }
    return tot <= 1LL * k * k;
};

//FFFFTTTTTTTT
    while(s<=e){
        int mid=s+(e-s)/2;

        if(isValid(mid)){
            ans=mid;
            e=mid-1;
        }

        else{
            s=mid+1;
        }
    }

    return ans;
    }
};



// Once f(k) ≤ k2 becomes true,
// 👉 it will stay true forever for larger k.

// This creates a boundary:



