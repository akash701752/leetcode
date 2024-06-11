class Solution {
private:
    vector<int> findIndex(vector<int> &arr, int target){
        vector<int> res;
        for(int i=0; i<arr.size(); i++){
            if(target == arr[i]){
                res.push_back(i);
            }
        }
        return res;
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        
        int startIndex = 0, endIndex=m-1;
        for(int i=0; i<n; i++){
            vector<int> res = findIndex(arr1, arr2[i]);
            if(res.size() == 0){
                swap(arr1[startIndex], arr1[endIndex]);
                startIndex++;
                endIndex--;
            } else {
                for(int k=0; k<res.size(); k++){
                    swap(arr1[startIndex], arr1[res[k]]);
                    startIndex++;
                }
            }
        }
        sort(arr1.begin()+startIndex, arr1.end());
        return arr1;
    }
};
