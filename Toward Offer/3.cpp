class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = 0;
        int row = rows - 1;

        while ( row >= 0 && col < matrix[0].size())
        {
            if(matrix[row][col] > target)
                row--;
            else if (matrix[row][col] < target)
                col++;
            else 
                return true;
        }

        return false;
    }
};