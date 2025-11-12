class Solution {
public:
// to place x,y from x1,y1
// x>=x1 && y<=y1 given
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        auto lamda=[&](vector<int>& p1,vector<int>& p2){
                return p1[0]==p2[0]? p1[1]>=p2[1] : p1[0] <=p2[0]; };

        sort(points.begin(),points.end(),lamda);

int count=0;
        for(int i=0;i<n;i++){
            int yi=points[i][1];
            int prevYjMax=-1;
            for(int j=i+1;j<n;j++){
                    int yj=points[j][1];

                    if(yj>yi ) continue;

                    if(yj>prevYjMax) {
                        count++;
                        prevYjMax=yj;
                    }

            }
        }
    return count;}
};