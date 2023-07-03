class Solution {
public:
    bool buddyStrings(string A, string B) {
        // trival case
        if (A.size() != B.size()) return false;
        
        // visited chars
        unordered_set<int> s;
        
        // flags
        bool has_repeat = false;
        int Ndiff = 0;
        char Ak = 0, Bk = 0;
        
        for (int i(0); i < A.size(); ++i) {
            if (A[i] != B[i]) {
                Ndiff += 1;
                if (Ndiff == 1) {
                    Ak = A[i];
                    Bk = B[i];
                }
                else if (Ndiff == 2) {
                    if (A[i] != Bk or B[i] != Ak) return false;
                }
                else {
                    return false;
                }
            }
            // check if A[i] is already in s
            if (s.count(A[i])) {
                has_repeat = true;
            }
            else {
                s.insert(A[i]);
            }
        }
        
        return (Ndiff == 2) or (Ndiff == 0 and has_repeat);
    }
};
