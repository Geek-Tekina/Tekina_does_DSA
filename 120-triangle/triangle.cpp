// class Solution {
// public:
    
//     int helper(vector<vector<int>>& mat, int rows, int index, int row, vector<vector<int>>& dp){
//         //base case 
//         if(row == rows){
//             return 0;
//         }
//         if(dp[row][index] != -1) return dp[row][index];
//         int path1 = 0, path2 = 0;
//         path1 = mat[row][index] + helper(mat, rows, index, row + 1, dp);
//         path2 = mat[row][index] + helper(mat, rows, index + 1, row + 1, dp);

//         return dp[row][index] = min(path1, path2);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {

//         int rows = triangle.size();
//         vector<vector<int>> dp(rows + 1, vector<int>(rows + 1, -1));
//         return helper(triangle, rows, 0, 0, dp);
//     }
// };
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int col = 0; col < n; ++col) {
            dp[n - 1][col] = triangle[n - 1][col];
        }

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        
        return dp[0][0];
    }
};
