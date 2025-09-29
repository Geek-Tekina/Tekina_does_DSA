class Solution {
public:
    int memo[50][50]; // assuming max size of values is 50

    int dp(int i, int j, vector<int>& v) {
        if (j - i < 2) return 0; // no triangle possible
        if (memo[i][j] != -1) return memo[i][j];

        int result = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            result = min(result, dp(i, k, v) + dp(k, j, v) + v[i] * v[k] * v[j]);
        }

        return memo[i][j] = result;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(memo, -1, sizeof(memo)); // initialize memo to -1
        return dp(0, n - 1, values);
    }
};
