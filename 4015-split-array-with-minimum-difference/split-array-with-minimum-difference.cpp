class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n), dec(n);

        inc[0] = 1;
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i - 1] && (nums[i] > nums[i - 1]);
        }

        dec[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            dec[i] = dec[i + 1] && (nums[i] > nums[i + 1]);
        }

        long long sum = 0;
        for (int x : nums) sum += x;

        long long ans = 1e12, left = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            if (inc[i] && dec[i + 1])
                ans = min(ans, abs(sum - 2 * left));
        }

        if (ans == 1e12) ans = -1;
        return ans;
    }
};
