class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = t.length()  , m = s.length();
        int i = 0  ;
        if(m==0 && n>0){
            return true;
        }
        if(m==0 && n==0){
            return true;
        }
        if(m>0 && n==0){
            return false;
        }
        char arrs[] = s.toCharArray() ;
        char arrt[] = t.toCharArray() ;
        for(int j=0;j<n;j++){
            if(arrt[j]==arrs[i]){
                i++;
                if(i==m){
                    return true;
                }
            }
        }
        return false ;
    }
}
