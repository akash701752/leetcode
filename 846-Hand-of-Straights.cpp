class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        
        if(size%groupSize != 0)
            return false;
        
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()!=0){
            auto iter = mp.begin();
            int i=1;
            int t = iter->first;
            while(i<=groupSize){
                
                if(mp.find(t)==mp.end())
                    return false;
                else
                {
                    mp[t]--;
                    if(mp[t]==0)
                        mp.erase(t);
                }
                t++;i++;
            }
            
        }
        return true;
        
        
    }
};
