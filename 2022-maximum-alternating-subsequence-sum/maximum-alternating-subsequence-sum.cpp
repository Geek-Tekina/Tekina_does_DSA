class Solution {
public:
    long long helper(vector<int>& nums, int index, bool isEven, vector<vector<long long>> &dp){
        // base
        if(index == nums.size()){
            return 0;
        }
        long long take = 0, notTake = 0;

        if(dp[index][isEven] != -1) return dp[index][isEven];

        if(isEven){
            take = nums[index] + helper(nums, index + 1, !isEven, dp);
        }else{
            take = (-1 * nums[index]) + helper(nums, index + 1, !isEven, dp);
        }

        notTake = helper(nums, index + 1, isEven, dp);

        return dp[index][isEven] = max(take, notTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size() + 1, vector<long long>(2, -1));
        return helper(nums, 0, true, dp);
    }
};