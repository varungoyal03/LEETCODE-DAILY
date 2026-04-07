class Robot {
public:
int w,h;
int x,y;
int dir;
int peri;

        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

    Robot(int width, int height) {
        w=width;
        h=height;
        x=y=0;
        dir=1;
        peri=2*(w+h-2);

        
    }
    
    void step(int num) {
        int nx,ny;
        num%=peri;
if (num == 0) num = peri;
        while(num--){
            nx=x+directions[dir].first;
            ny=y+directions[dir].second;

            if(nx==w || nx==-1 || ny==h ||ny==-1) {
                dir=(dir-1+4)%4;
                num++;
                continue;
            }

        x=nx;
        y=ny;


        }

        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
         if (dir == 1) return "East";
        if (dir == 2) return "South";
        if (dir == 3) return "West";
        return "North";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */