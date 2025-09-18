class Solution {
public:
    // int helper(vector<int>& nums, int index){
    //     // base case
    //     if(index < 0) return 0;
    //     if(index == 0) return nums[0];

    //     // not take case
    //     int notTake = helper(nums, index - 1);

    //     // take case
    //     int take = nums[index] + helper(nums, index - 2);

    //     return max(notTake, take);

    // }
    int rob(vector<int>& nums) {
        // return helper(nums, nums.size()-1);
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];

    }
};