class Solution {
public:
    int helper(vector<int>& colors, int s, int e,  vector<vector<int>>& dp){
        if(s == e) return 0;

        if(colors[s] != colors[e]) return abs(s-e);
        if(dp[s][e] != -1) return dp[s][e];
        return dp[s][e] = max(helper(colors, s+1, e, dp), helper(colors, s, e-1, dp));
    }
    int maxDistance(vector<int>& colors) {
        vector<vector<int>> dp(colors.size() + 1, vector<int> (colors.size() + 1, -1));
        return helper(colors, 0, colors.size()-1, dp);

    }
};