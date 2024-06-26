class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        if(s.size()==0){
            return 0;
        }
		int res=0;
		int start=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=t[i]){
				maxCost-=abs(s[i]-t[i]);
				while(maxCost<0){
					maxCost+=abs(s[start]-t[start]);
					start++;            
				}
			}  
            if(start>i){
                start=i+1;
                continue;
            }    
            res=max(res,i-start+1);
		}

		return res;
    }
};
