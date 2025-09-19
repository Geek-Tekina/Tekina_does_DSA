class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, 0), dp2(n, 0);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n-1; i++){
            int notTake = dp1[i-1];
            int take = nums[i] + dp1[i-2];
            dp1[i] = max(notTake, take);
        }

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for(int i = 3; i < n; i++){
            int notTake = dp2[i-1];
            int take = nums[i] + dp2[i-2];
            dp2[i] = max(notTake, take);
        }

        return max(dp1[n-2], dp2[n-1]);
    }
};
