class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map <int, int> mp;
        int maxF = 0;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] > maxF){
                maxF = mp[it];
            }
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second == maxF) ++cnt;
        }
        return maxF * cnt;
    }
};