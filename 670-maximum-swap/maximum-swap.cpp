class Solution {
public:

int maximumSwap(int n) {
    string s = to_string(n);

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '9') continue;

        int maxi = i;

        for(int j = i; j < s.size(); j++){
            if(s[j] >= s[maxi]){
                maxi = j;
            }
        }

        if(maxi != i && s[maxi] > s[i]){
            swap(s[i], s[maxi]);
            break;
        }
    }

    return stoi(s);
}
};


