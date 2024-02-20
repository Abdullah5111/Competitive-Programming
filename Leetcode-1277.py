class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = 0;
        for(int i = 0; i < n; ++i)
            x += matrix[i][0];
        for(int i = 1; i < m; ++i)
            x += matrix[0][i];

        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j < m; ++j)
            {
                if(matrix[i][j] == 1)
                {
                    if(matrix[i - 1][j - 1] != 0 && matrix[i - 1][j] != 0 && matrix[i][j - 1] != 0)
                        matrix[i][j] = min(min(matrix[i - 1][j - 1], matrix[i - 1][j]), matrix[i][j - 1]) + 1;
                }
                x += matrix[i][j];
            }
        }
        return x;
    }
};