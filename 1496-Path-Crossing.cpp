class Solution {
public:
    bool isPathCrossing(string path) {
        // int up = 0 , down = 0 , left = 0 , right = 0 ;
        // int n = path.length() ;
        // for(int i=0;i<n;i++){
        //     if(path[i]=='N'){
        //         up++;
        //     }
        //     else if(path[i]=='E'){
        //         right++;
        //     }
        //     else if(path[i]=='S'){
        //         down++;
        //     }
        //     else if(path[i]=='W'){
        //         left++;
        //     }
        //     int a = abs(up - down) ;
        //     int b = abs(right - left) ;
        //     if(a+b==0){
        //         return true;
        //     }
        // }
        // return false;

        set<pair<int,int>>set;
        int x,y;
        x=y=0;
        int n=path.size();
        set.insert({0,0});
        for(int i=0;i<n;i++)
        {
            if(path[i]=='N'){
                x++;
            }
            else if(path[i]=='S'){
                x--;
            }
            else if(path[i]=='E'){
                y++;
            }
            else{
                y--;
            }
            if(set.count({x,y})){
                return true;
            }
            else{
              set.insert({x,y});  
            }
        }
        return false;
    }
};
