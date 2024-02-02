class Solution {
private:
    
  
    // Precompute distinct seq ints.
    string intSeq = "123456789";
    // 36 distinct seq ints, stored in a set below.
    vector<int> distinctValues;

    void precomputeDistinctValues() {
        if (!distinctValues.empty()) return;

        // Precompute, produces sorted list.
        for (int len{2}; len < intSeq.size(); ++len) {
            for (int i{}; i <= intSeq.size() - len; ++i) {
                long int number = stoi(intSeq.substr(i, len));
                distinctValues.push_back(number);
            }
        }
        
        // We want numbers of minimum length 2, this prevents us from capturing the largest
        // consecutive number (intSeq). Hence we must add it seperately.
        distinctValues.push_back(stoi(intSeq));
        
        return;
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        
        precomputeDistinctValues();

        vector<int> ourRes;
        
        for (int i{}; i < distinctValues.size(); ++i) {
            if (distinctValues[i] <= high && distinctValues[i] >= low) ourRes.push_back(distinctValues[i]);
        }
        return ourRes;
    }
};
