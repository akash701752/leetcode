/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 , r = 0 , n = fruits.size() , ans = 0 ;
        map<int,int> mp ;
        while(r<n)
        {
            mp[fruits[r]] ++ ;
            if(mp.size()>2){
                if(mp[fruits[l]]==1){
                    mp.erase(fruits[l]) ;
                }
                else{
                    mp[fruits[l]]-- ;
                }
                l++ ;
            }
            ans = max(r-l+1,ans) ;
            r++ ;
        }
        return ans ;
    }
};