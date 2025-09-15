class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> line(n + 2, 0);

        long long share = 0;   // current number of people sharing today
        long long ans = 0;     // sum of people who still remember on day n

        long long newly = 1;

        if (1 + delay <= n)  line[1 + delay] = (line[1 + delay] + newly) % MOD;
        if (1 + forget <= n) line[1 + forget] = (line[1 + forget] - newly + MOD) % MOD;

        if (1 >= n - forget + 1) ans = (ans + newly) % MOD;

        for (int day = 2; day <= n; ++day) {
            share = (share + line[day]) % MOD;

            newly = share;

            if (day + delay <= n)
                line[day + delay] = (line[day + delay] + newly) % MOD;
            if (day + forget <= n)
                line[day + forget] = (line[day + forget] - newly + MOD) % MOD;

            if (day >= n - forget + 1)
                ans = (ans + newly) % MOD;
        }

        return (int)ans;
    }
};
