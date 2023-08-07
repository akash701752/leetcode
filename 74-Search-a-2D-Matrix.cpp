class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = row? matrix[0].size(): 0;
        int low = 0, high = row - 1, left = 0, right = col - 1;
        while(low <= high){                                            
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) low = mid + 1;
            if(matrix[mid][0] > target) high = mid - 1;  
        }
        //use high, when high == low, high -1 to the smaller row
        if (high < 0) return false;      //incase high < 0
        while(left <= right){
            int mid2 = left + (right - left) / 2;
            if(matrix[high][mid2] == target) return true;
            if(matrix[high][mid2] < target) left = mid2 + 1;
            if(matrix[high][mid2] > target) right = mid2 - 1;
        }
        if(right < 0) return false;
        return row?(col?matrix[high][right] == target:false):false;
    }
};
